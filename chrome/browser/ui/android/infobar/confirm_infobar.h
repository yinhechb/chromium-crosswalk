// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CHROME_BROWSER_UI_ANDROID_INFOBAR_CONFIRM_INFOBAR_H_
#define CHROME_BROWSER_UI_ANDROID_INFOBAR_CONFIRM_INFOBAR_H_

#include "base/basictypes.h"
#include "base/strings/string16.h"
#include "chrome/browser/ui/android/infobar/infobar_android.h"

class ConfirmInfoBarDelegate;

namespace gfx {
class Image;
}

// Implementation of InfoBar for confirm infobars, this currently
// includes, geolocation, popups..
class ConfirmInfoBar : public InfoBarAndroid {
 public:
  ConfirmInfoBar(InfoBarService* owner, InfoBarDelegate* delegate);
  virtual ~ConfirmInfoBar();

 private:
  // InfoBar overrides.
  virtual base::android::ScopedJavaLocalRef<jobject> CreateRenderInfoBar(
      JNIEnv* env) OVERRIDE;
  virtual void ProcessButton(int action,
                             const std::string& action_value) OVERRIDE;

  string16 GetTextFor(ActionType action);
  string16 GetMessage();

  ConfirmInfoBarDelegate* delegate_;
  base::android::ScopedJavaGlobalRef<jobject> java_confirm_delegate_;

  DISALLOW_COPY_AND_ASSIGN(ConfirmInfoBar);
};

// Registers native methods
bool RegisterConfirmInfoBarDelegate(JNIEnv* env);

#endif  // CHROME_BROWSER_UI_ANDROID_INFOBAR_CONFIRM_INFOBAR_H_
