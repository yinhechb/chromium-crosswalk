// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef PAPPI_TESTS_TEST_TCP_SOCKET_H_
#define PAPPI_TESTS_TEST_TCP_SOCKET_H_

#include <string>

#include "ppapi/c/pp_stdint.h"
#include "ppapi/cpp/net_address.h"
#include "ppapi/tests/test_case.h"

namespace pp {
class TCPSocket;
}

class TestTCPSocket: public TestCase {
 public:
  explicit TestTCPSocket(TestingInstance* instance);

  // TestCase implementation.
  virtual bool Init();
  virtual void RunTests(const std::string& filter);

 private:
  std::string TestConnect();
  std::string TestReadWrite();
  std::string TestSetOption();
  std::string TestListen();
  std::string TestBacklog();

  std::string ReadFirstLineFromSocket(pp::TCPSocket* socket, std::string* s);
  std::string ReadFromSocket(pp::TCPSocket* socket,
                             char* buffer,
                             size_t num_bytes);
  std::string WriteToSocket(pp::TCPSocket* socket, const std::string& s);
  std::string GetAddressToBind(pp::NetAddress* address);
  std::string StartListen(pp::TCPSocket* socket, int32_t backlog);

  pp::NetAddress addr_;
};

#endif  // PAPPI_TESTS_TEST_TCP_SOCKET_H_
