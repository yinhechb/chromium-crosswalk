// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "remote_desktop_browsertest.h"

namespace remoting {

IN_PROC_BROWSER_TEST_F(RemoteDesktopBrowserTest, MANUAL_Auth) {
  VerifyInternetAccess();

  Install();

  LaunchChromotingApp();

  // Authorize, Authenticate, and Approve.
  Auth();

  Cleanup();
}

}  // namespace remoting
