// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CONTENT_PUBLIC_COMMON_MEDIA_STREAM_REQUEST_H_
#define CONTENT_PUBLIC_COMMON_MEDIA_STREAM_REQUEST_H_

#include <map>
#include <string>
#include <vector>

#include "base/basictypes.h"
#include "content/common/content_export.h"
#include "googleurl/src/gurl.h"

namespace content {

// Types of media streams.
enum MediaStreamDeviceType {
  MEDIA_NO_SERVICE = 0,

  // A device provided by the operating system (e.g., webcam input).
  MEDIA_DEVICE_AUDIO_CAPTURE,
  MEDIA_DEVICE_VIDEO_CAPTURE,

  // Mirroring of a browser tab.
  MEDIA_TAB_AUDIO_CAPTURE,
  MEDIA_TAB_VIDEO_CAPTURE,

  NUM_MEDIA_TYPES
};

// Types of media stream requests that can be made to the media controller.
enum MediaStreamRequestType {
  MEDIA_DEVICE_ACCESS = 0,
  MEDIA_GENERATE_STREAM,
  MEDIA_ENUMERATE_DEVICES,
  MEDIA_OPEN_DEVICE
};

// Convenience predicates to determine whether the given type represents some
// audio or some video device.
CONTENT_EXPORT bool IsAudioMediaType(MediaStreamDeviceType type);
CONTENT_EXPORT bool IsVideoMediaType(MediaStreamDeviceType type);

// TODO(xians): Change the structs to classes.
// Represents one device in a request for media stream(s).
struct CONTENT_EXPORT MediaStreamDevice {
  MediaStreamDevice(
      MediaStreamDeviceType type,
      const std::string& device_id,
      const std::string& name);

  ~MediaStreamDevice();

  // The device's type.
  MediaStreamDeviceType type;

  // The device's unique ID.
  std::string device_id;

  // The device's "friendly" name. Not guaranteed to be unique.
  std::string name;
};

typedef std::vector<MediaStreamDevice> MediaStreamDevices;

typedef std::map<MediaStreamDeviceType, MediaStreamDevices>
    MediaStreamDeviceMap;

// Represents a request for media streams (audio/video).
struct CONTENT_EXPORT MediaStreamRequest {
  MediaStreamRequest(
      int render_process_id,
      int render_view_id,
      const GURL& security_origin,
      MediaStreamRequestType request_type,
      MediaStreamDeviceType audio_type,
      MediaStreamDeviceType video_type);

  ~MediaStreamRequest();

  // The render process id generating this request.
  int render_process_id;

  // The render view id generating this request.
  int render_view_id;

  // The WebKit security origin for the current request (e.g. "html5rocks.com").
  GURL security_origin;

  // Stores the type of request that was made to the media controller. Right now
  // this is only used to destinguish between WebRTC and Pepper requests, as the
  // latter should not be subject to user approval but only to policy check.
  // Pepper requests are signified by the |MEDIA_OPEN_DEVICE| value.
  MediaStreamRequestType request_type;

  // Flag to indicate if the request contains audio.
  MediaStreamDeviceType audio_type;

  // Flag to indicate if the request contains video.
  MediaStreamDeviceType video_type;
};

}  // namespace content

#endif  // CONTENT_PUBLIC_COMMON_MEDIA_STREAM_REQUEST_H_
