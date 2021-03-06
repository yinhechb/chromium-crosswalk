// Copyright (c) 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.


#include "nacl_io/mount_node_udp.h"

#include <errno.h>
#include <string.h>

#include <algorithm>

#include "nacl_io/event_emitter_udp.h"
#include "nacl_io/mount_stream.h"
#include "nacl_io/packet.h"
#include "nacl_io/pepper_interface.h"

namespace {
  const size_t kMaxPacketSize = 65536;
  const size_t kDefaultFifoSize = kMaxPacketSize * 8;
}

namespace nacl_io {

class UDPWork : public MountStream::Work {
 public:
  explicit UDPWork(const ScopedEventEmitterUDP& emitter)
      : MountStream::Work(emitter->stream()->mount_stream()),
        emitter_(emitter),
        packet_(NULL) {
  }

  ~UDPWork() {
    delete packet_;
  }

  UDPSocketInterface* UDPInterface() {
    return mount()->ppapi()->GetUDPSocketInterface();
  }

 protected:
  ScopedEventEmitterUDP emitter_;
  Packet* packet_;
};


class UDPSendWork : public UDPWork {
 public:
  explicit UDPSendWork(const ScopedEventEmitterUDP& emitter)
      : UDPWork(emitter) {}

  virtual bool Start(int32_t val) {
    AUTO_LOCK(emitter_->GetLock());
    MountNodeUDP* stream = static_cast<MountNodeUDP*>(emitter_->stream());

    // Does the stream exist, and can it send?
    if (NULL == stream || !stream->TestStreamFlags(SSF_CAN_SEND))
      return false;

    // If not currently sending...
    if (!stream->TestStreamFlags(SSF_SENDING)) {
      packet_ = emitter_->ReadTXPacket_Locked();
      if (packet_) {
        stream->SetStreamFlags(SSF_SENDING);
        int err = UDPInterface()->SendTo(stream->socket_resource(),
                                         packet_->buffer(),
                                         packet_->len(),
                                         packet_->addr(),
                                         mount()->GetRunCompletion(this));
        if (err == PP_OK_COMPLETIONPENDING)
          return true;

        // Anything else, we should assume the socket has gone bad.
        stream->SetError_Locked(err);
      }
    }
    return false;
  }

  virtual void Run(int32_t length_error) {
    AUTO_LOCK(emitter_->GetLock());
    MountNodeUDP* stream = static_cast<MountNodeUDP*>(emitter_->stream());

    // If the stream is still there...
    if (stream) {
      // And we did send, then Q more work.
      if (length_error >= 0) {
        stream->ClearStreamFlags(SSF_SENDING);
        stream->QueueOutput();
      } else {
        // Otherwise this socket has gone bad.
        stream->SetError_Locked(length_error);
      }
    }
  }
};


class UDPRecvWork : public UDPWork {
 public:
  explicit UDPRecvWork(const ScopedEventEmitterUDP& emitter)
      : UDPWork(emitter) {
    data_ = new char[kMaxPacketSize];
  }

  ~UDPRecvWork() {
    delete[] data_;
  }

  virtual bool Start(int32_t val) {
    AUTO_LOCK(emitter_->GetLock());
    MountNodeUDP* stream = static_cast<MountNodeUDP*>(emitter_->stream());

    // Does the stream exist, and can it recv?
    if (NULL == stream || !stream->TestStreamFlags(SSF_CAN_RECV))
      return false;

    // If the stream is valid and we are not currently receiving
    if (!stream->TestStreamFlags(SSF_RECVING)) {
      stream->SetStreamFlags(SSF_RECVING);
      int err = UDPInterface()->RecvFrom(stream->socket_resource(),
                                         data_,
                                         kMaxPacketSize,
                                         &addr_,
                                         mount()->GetRunCompletion(this));
      if (err == PP_OK_COMPLETIONPENDING)
        return true;

      stream->SetError_Locked(err);
    }
    return false;
  }

  virtual void Run(int32_t length_error) {
    AUTO_LOCK(emitter_->GetLock());
    MountNodeUDP* stream = static_cast<MountNodeUDP*>(emitter_->stream());

    // If the stream is still there, see if we can queue more input
    if (stream) {
      if (length_error > 0) {
        Packet* packet = new Packet(mount()->ppapi());
        packet->Copy(data_, length_error, addr_);
        emitter_->WriteRXPacket_Locked(packet);
        stream->ClearStreamFlags(SSF_RECVING);
        stream->QueueInput();
      } else {
        stream->SetError_Locked(length_error);
      }
    }
  }

 private:
  char* data_;
  PP_Resource addr_;
};


MountNodeUDP::MountNodeUDP(Mount* mount)
    : MountNodeSocket(mount),
      emitter_(new EventEmitterUDP(kDefaultFifoSize, kDefaultFifoSize)) {
  emitter_->AttachStream(this);
}

void MountNodeUDP::Destroy() {
  emitter_->DetachStream();
  MountNodeSocket::Destroy();
}

EventEmitterUDP* MountNodeUDP::GetEventEmitter() {
  return emitter_.get();
}

Error MountNodeUDP::Init(int flags) {
  if (UDPInterface() == NULL)
    return EACCES;

  socket_resource_ = UDPInterface()->Create(mount_->ppapi()->GetInstance());
  if (0 == socket_resource_)
    return EACCES;

  return 0;
}

void MountNodeUDP::QueueInput() {
  UDPRecvWork* work = new UDPRecvWork(emitter_);
  mount_stream()->EnqueueWork(work);
}

void MountNodeUDP::QueueOutput() {
  UDPSendWork* work = new UDPSendWork(emitter_);
  mount_stream()->EnqueueWork(work);
}

Error MountNodeUDP::Bind(const struct sockaddr* addr, socklen_t len) {
  if (0 == socket_resource_)
    return EBADF;

  /* Only bind once. */
  if (local_addr_ != 0)
    return EINVAL;

  PP_Resource out_addr = SockAddrToResource(addr, len);
  if (0 == out_addr)
    return EINVAL;

  int err = UDPInterface()->Bind(socket_resource_,
                                 out_addr,
                                 PP_BlockUntilComplete());
  if (err != 0) {
    mount_->ppapi()->ReleaseResource(out_addr);
    return PPErrorToErrno(err);
  }

  // Now that we are bound, we can start sending and receiving.
  SetStreamFlags(SSF_CAN_SEND | SSF_CAN_RECV);
  QueueInput();

  local_addr_ = out_addr;
  return 0;
}

Error MountNodeUDP::Connect(const struct sockaddr* addr, socklen_t len) {
  if (0 == socket_resource_)
    return EBADF;

  /* Connect for UDP is the default dest, it's legal to change it. */
  if (remote_addr_ != 0) {
    mount_->ppapi()->ReleaseResource(remote_addr_);
    remote_addr_ = 0;
  }

  remote_addr_ = SockAddrToResource(addr, len);
  if (0 == remote_addr_)
    return EINVAL;

  return 0;
}

Error MountNodeUDP::Recv_Locked(void* buf,
                                size_t len,
                                PP_Resource* out_addr,
                                int* out_len) {
  Packet* packet = emitter_->ReadRXPacket_Locked();
  *out_len = 0;
  *out_addr = 0;

  if (packet) {
    int capped_len =
        static_cast<int32_t>(std::min<int>(len, packet->len()));
    memcpy(buf, packet->buffer(), capped_len);

    if (packet->addr() != 0) {
      mount_->ppapi()->AddRefResource(packet->addr());
      *out_addr = packet->addr();
    }

    *out_len = capped_len;
    delete packet;
    return 0;
  }

  // Should never happen, Recv_Locked should not be called
  // unless already in a POLLIN state.
  return EBADF;
}

Error MountNodeUDP::Send_Locked(const void* buf,
                                size_t len,
                                PP_Resource addr,
                                int* out_len) {
  *out_len = 0;
  int capped_len =
      static_cast<int32_t>(std::min<int>(len, kMaxPacketSize));
  Packet* packet = new Packet(mount_->ppapi());
  packet->Copy(buf, capped_len, addr);

  emitter_->WriteTXPacket_Locked(packet);
  *out_len = capped_len;
  return 0;
}

}  // namespace nacl_io

