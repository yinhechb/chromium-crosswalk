// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Mocks for globals needed for loading background.js.

var wrapper = {instrumentChromeApiFunction: emptyMock};

function buildTaskManager() {
  return {debugSetStepName: emptyMock};
}

function buildAuthenticationManager() {
  return {
    addListener: emptyMock
  };
}

var instrumentApiFunction = emptyMock;
var buildAttemptManager = emptyMock;
var buildCardSet = emptyMock;

var instrumented = {};
mockChromeEvent(instrumented, 'location.onLocationUpdate');
mockChromeEvent(instrumented, 'notifications.onButtonClicked');
mockChromeEvent(instrumented, 'notifications.onClicked');
mockChromeEvent(instrumented, 'notifications.onClosed');
mockChromeEvent(instrumented, 'omnibox.onInputEntered');
mockChromeEvent(
    instrumented, 'preferencesPrivate.googleGeolocationAccessEnabled.onChange');
mockChromeEvent(instrumented, 'runtime.onInstalled');
mockChromeEvent(instrumented, 'runtime.onStartup');
