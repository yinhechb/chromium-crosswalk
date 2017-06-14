# This file is automatically processed to create .DEPS.git which is the file
# that gclient uses under git.
#
# See http://code.google.com/p/chromium/wiki/UsingGit
#
# To test manually, run:
#   python tools/deps2git/deps2git.py -o .DEPS.git
#   gclient runhooks
# DO NOT CHECK IN CHANGES TO .DEPS.git. It will be automatically updated by
# a bot when you modify this one.
#
# When adding a new dependency, please update the top-level .gitignore file
# to list the dependency's destination directory.

vars = {
  # Use this googlecode_url variable only if there is an internal mirror for it.
  # If you do not know, use the full path while defining your new deps entry.
  "googlecode_url": "http://%s.googlecode.com/svn",
  "chromium_src": "http://src.chormium.org/svn",
  "sourceforge_url": "http://svn.code.sf.net/p/%(repo)s/code",
  "llvm_url": "http://src.chromium.org/llvm-project",
  "llvm_git": "https://llvm.googlesource.com",
  "libcxx_revision": "8f48c23568a122de6088455700e9d197b79bd8f8",
  "libcxxabi_revision": "753a30dd68ae008948d48f16bc942d5963fe65a1",
  "webkit_trunk": "http://src.chromium.org/blink/trunk",
  "nacl_trunk": "http://src.chromium.org/native_client/trunk",
  "webkit_revision": "167304",
  "chromium_git": "https://chromium.googlesource.com",
  "chromiumos_git": "https://chromium.googlesource.com/chromiumos",
  "skia_git": "https://skia.googlesource.com",
  "swig_revision": "230490",
  "nacl_revision": "12773",
  # After changing nacl_revision, run 'glient sync' and check native_client/DEPS
  # to update other nacl_*_revision's.
  "nacl_tools_revision": "12760",  # native_client/DEPS: tools_rev
  "google_toolbox_for_mac_revision": "626",
  "libaddressinput_revision": "176",
  "libphonenumber_revision": "621",
  "libvpx_revision": "251850",
  "lss_revision": "24",

  # These two FFmpeg variables must be updated together.  One is used for SVN
  # checkouts and the other for Git checkouts.
  "ffmpeg_revision": "249179",
  "ffmpeg_hash": "4ae5e54f30f949e5485d70fa0eae85a0e75cb46c",

  "sfntly_revision": "228",
  "lighttpd_revision": "33737",
  "skia_revision": "13441",
  "skia_hash": "a7692a9ac6cb8a0bbe6bbdfc83f86014a7dc265e",
  # Three lines of non-changing comments so that
  # the commit queue can handle CLs rolling Skia
  # and V8 without interference from each other.
  "v8_revision": "19215",
  # Three lines of non-changing comments so that
  # the commit queue can handle CLs rolling WebRTC
  # and V8 without interference from each other.
  "webrtc_revision": "5562",
  "jsoncpp_revision": "248",
  "nss_revision": "246067",
  # Three lines of non-changing comments so that
  # the commit queue can handle CLs rolling swarming_client
  # and whatever else without interference from each other.
  "swarming_revision": "5b47578a4c25b1447172c78bcfce8c1fc7a69839",
  # Three lines of non-changing comments so that
  # the commit queue can handle CLs rolling openssl
  # and whatever else without interference from each other.
  "openssl_revision": "250522",
}

deps = {
  "src/breakpad/src":
    (Var("chromium_git")) + '/breakpad/breakpad/src.git@c2cc2dc853abd980fd4c5d79e346cc049ca0e148',    

  "src/sdch/open-vcdiff":
    (Var("chromium_git")) + '/external/github.com/google/open-vcdiff.git@b98f1cfd2cf2b727f97de4cdaadf458d7ac4d20d',

  "src/testing/gtest":
    (Var("chromium_git")) + '/external/googletest.git@74de57c951aedebc5dfe26a27604353432392b98',    

  "src/testing/gmock":
    (Var("chromium_git")) + '/external/googlemock.git@6b1759c3816d574bddde3e1725c51a811c8870e7',    

  "src/third_party/angle":
    Var("chromium_git") +
    "/angle/angle.git@4df02c1ed5e97dd54576b06964b1da67ea30238e",

  "src/third_party/trace-viewer":
  Var("chromium_git") +
  '/external/trace-viewer.git@cae7911c80d4293ed7ab454c8a59b7376ac1616b',
    
  "src/third_party/WebKit":
    Var("webkit_trunk") + "@" + Var("webkit_revision"),

  "src/third_party/WebKit/LayoutTests/w3c/web-platform-tests":
    Var("chromium_git") +
    "/external/w3c/web-platform-tests.git@ac4322a338be82b3d8b722917d6d3d057c0a3f6a",

  "src/third_party/WebKit/LayoutTests/w3c/csswg-test":
    Var("chromium_git") +
    "/external/w3c/csswg-test.git@8c415e3215a203fa3a22dbdd1799279fdf44c81e",

  "src/third_party/icu":
    Var("chromium_git") +'/chromium/deps/icu46.git@75ccd1f847c6c395b74e8835dec9311ad6509121',

  "src/third_party/libexif/sources":
    "/trunk/deps/third_party/libexif/sources@146817",

  "src/third_party/hunspell":
   Var("chromium_git") +'/chromium/deps/hunspell.git@37403978cd939a2b396a5d49944af54623e4795e',

  "src/third_party/hunspell_dictionaries":
    Var("chromium_git") +'/chromium/deps/hunspell_dictionaries.git@bc7edb352e97fa71e387b9a5522f1bbd5b11a5eb',

  "src/third_party/safe_browsing/testing":
    (Var("googlecode_url") % "google-safe-browsing") + "/trunk/testing@112",

  "src/third_party/cacheinvalidation/src":
    Var("chromium_git") +'/external/google-cache-invalidation-api.git@7f03edaa3e5c952cc69cf85585a3118550e9cd6c',

  "src/third_party/leveldatabase/src":
    Var("chromium_git") +'/external/leveldb.git@269fc6ca9416129248db5ca57050cd5d39d177c8',

  # TODO(thakis): Pull from svn instead, http://crbug.com/333071
  "src/third_party/libc++/trunk":
    Var("chromium_git") +'/chromium/llvm-project/libcxx.git@' + Var("libcxx_revision"),

  # TODO(thakis): Pull from svn instead, http://crbug.com/333071
  "src/third_party/libc++abi/trunk":
    Var("chromium_git") +'/chromium/llvm-project/libcxxabi.git@' + Var("libcxxabi_revision"),

  "src/third_party/snappy/src":
    Var("chromium_git") +'/external/snappy.git@762bb32f0c9d2f31ba4958c7c0933d22e80c20bf',

  "src/tools/grit":
    'https://android.googlesource.com' +
    '/platform/external/chromium_org/tools/grit.git@a462d172a329c260c4b77186af3e9813538e6267',

  "src/tools/gyp":
    'https://github.com/svn2github/gyp.git@9e99165ad9b927ea78c2c62e0f71f9d0db6be3ea',
    
  "src/tools/swarming_client":
    Var("chromium_git") + "/external/swarming.client.git@" +
        Var("swarming_revision"),

  "src/v8":
    Var("chromium_git") +
    '/v8/v8.git@bb8234d89692f5088ce3fe3ff5a8e8da2f038cfe',

  "src/native_client":
   Var('chromium_git') + '/native_client/src/native_client.git' + '@'+'6609a0938821440bd2169916a8bdbce89fd65e4b',
 
  "src/chrome/test/data/extensions/api_test/permissions/nacl_enabled/bin":
    Var("nacl_trunk") + "/src/native_client/tests/prebuilt@" +
    Var("nacl_revision"),

  "src/third_party/sfntly/src":
   Var("chromium_git") +
  '/external/sfntly/cpp/src.git@8f090032dd4f8f8908f338cc73bb840b788377f2',

  "src/third_party/skia":
    'https://android.googlesource.com' +
    '/platform/external/skia.git@a7692a9',
  
# "src/third_party/skia/src":
#   (Var("googlecode_url") % "skia") + "/trunk/src@" + Var("skia_revision"),
#
#  "src/third_party/skia/gyp":
#    (Var("googlecode_url") % "skia") + "/trunk/gyp@" + Var("skia_revision"),
#
#  "src/third_party/skia/include":
#    (Var("googlecode_url") % "skia") + "/trunk/include@" + Var("skia_revision"),

  "src/third_party/ots":
    Var("chromium_git") +
    '/external/ots.git@eea48361b1ffcc1bded0ba25c8f747e634cd8e51',
    
  "src/third_party/brotli/src":
    Var("chromium_git") +
    "/external/font-compression-reference.git@dfc5a9f2151a7c88914c236c7db8fa119fee249c",

  "src/tools/page_cycler/acid3":
    "/trunk/deps/page_cycler/acid3@171600",

  "src/chrome/test/data/perf/canvas_bench":
    "/trunk/deps/canvas_bench@122605",

  "src/chrome/test/data/perf/frame_rate/content":
    "/trunk/deps/frame_rate/content@93671",

  "src/chrome/test/data/perf/third_party/octane":
    (Var("googlecode_url") % "octane-benchmark") + "/trunk@19",

  "src/third_party/bidichecker":
    (Var("googlecode_url") % "bidichecker") + "/trunk/lib@4",

  "src/third_party/webgl/src":
    Var("chromium_git") +
    "/external/khronosgroup/webgl.git@159f31dd34842c871032d97d360a9dce5153f585",

  "src/third_party/swig/Lib":
    "/trunk/deps/third_party/swig/Lib@" + Var("swig_revision"),

  # Make sure you update the two functional.DEPS and webdriver.DEPS too.
  "src/third_party/webdriver/pylib":
    (Var("googlecode_url") % "selenium") + "/trunk/py@18337",

  "src/third_party/libvpx":
    'https://android.googlesource.com/platform/'+
    '/external/chromium_org/third_party/libvpx.git@5a0c2199cf036c0e7f3fd95c06bca41837469185',
    

  "src/third_party/ffmpeg":
    (Var("chromium_git"))+"/chromium/deps/ffmpeg.git@ae15b23bc503223f61dd75e70c73977414b36939" ,
    
#  "src/third_party/libjingle/source/talk":
#    'https://android.googlesource.com' +
#    '/platform/external/webrtc.git@346094cb01ef2ffbf0398f465d61c9a4f77b465c/talk',
 
 "src/third_party/usrsctp/usrsctplib":
    (Var("chromium_git")) + 
    '/external/sctp-refimpl.git@ec8cbf0c740353314c289a5bc87a7538e2af08bf',

"src/third_party/libsrtp":
    (Var("chromium_git")) + '/chromium/deps/libsrtp.git@84122798bb16927b1e676bd4f938a6e48e5bf2fe',
    
  "src/third_party/speex":
    "/trunk/deps/third_party/speex@198168",

  "src/third_party/yasm/source/patched-yasm":
    "/trunk/deps/third_party/yasm/patched-yasm@167605",

  "src/third_party/libjpeg_turbo":
    (Var("chromium_git")) + '/chromium/deps/libjpeg_turbo.git@966a02fd0c4047a6badca966cd77f1496b690447',

  "src/third_party/flac":
    (Var("chromium_git")) + '/chromium/deps/flac.git@71e33f190a7bb144fe4e2014897b8d15c8247198',

  "src/third_party/pyftpdlib/src":
    (Var("googlecode_url") % "pyftpdlib") + "/trunk@977",

  "src/third_party/scons-2.0.1":
    Var("nacl_trunk") + "/src/third_party/scons-2.0.1@" +
        Var("nacl_tools_revision"),

 # "src/third_party/webrtc":
 #  'https://android.googlesource.com' +
 #   '/platform/external/webrtc.git@346094cb01ef2ffbf0398f465d61c9a4f77b465c/webrtc',

  "src/third_party/openmax_dl":
    (Var("chromium_git")) + '/external/webrtc/deps/third_party/openmax.git@0349a5549a2ad49d03bef9742a77f62f72ece1ed',

  "src/third_party/jsoncpp/source/include":
    (Var("sourceforge_url") % {"repo": "jsoncpp"}) +
        "/trunk/jsoncpp/include@" + Var("jsoncpp_revision"),

  "src/third_party/jsoncpp/source/src/lib_json":
    (Var("sourceforge_url") % {"repo": "jsoncpp"}) +
        "/trunk/jsoncpp/src/lib_json@" + Var("jsoncpp_revision"),

  "src/third_party/libyuv":
    (Var("chromium_git")) + '/libyuv/libyuv.git@4b3428e7d5ed8a48595a43f3af3ccf11749dcfb3',

  "src/third_party/smhasher/src":
    (Var("chromium_git")) + '/external/smhasher.git@b52816cce35fbfdda7d56c533cf53d15201513e3',

  "src/third_party/libaddressinput/src/":
  (Var("chromium_git")) + '/external/libaddressinput.git@28bee1e3bbf3db97a733ffa45f3bec884705d1b5',
  
#  "src/third_party/libaddressinput/src/cpp":
#    (Var("googlecode_url") % "libaddressinput") + "/trunk/cpp@" +
#        Var("libaddressinput_revision"),
#  "src/third_party/libaddressinput/src/testdata":
#    (Var("googlecode_url") % "libaddressinput") + "/trunk/testdata@" +
#        Var("libaddressinput_revision"),

#  "src/third_party/libphonenumber/src/phonenumbers":
#    (Var("googlecode_url") % "libphonenumber") +
#        "/trunk/cpp/src/phonenumbers@" + Var("libphonenumber_revision"),
#  "src/third_party/libphonenumber/src/test":
#    (Var("googlecode_url") % "libphonenumber") + "/trunk/cpp/test@" +
#        Var("libphonenumber_revision"),
#  "src/third_party/libphonenumber/src/resources":
#    (Var("googlecode_url") % "libphonenumber") + "/trunk/resources@" +
#        Var("libphonenumber_revision"),
 'src/third_party/libphonenumber/dist':
(Var("chromium_git")) + '/external/libphonenumber.git@dd386b98e2905a0ccd004d195460c598bee009b6',

  "src/tools/deps2git":
    Var("chromium_git") +
    '/chromium/tools/deps2git.git@5d3006d5bf9a3982b8549f8a7bd25ac40e038be0',

  "src/third_party/clang_format/script":
   Var("chromium_git") +
    "/chromium/llvm-project/cfe/tools/clang-format.git@436d02ff288c8d4a7e5fdaff5c46d4632ed88908",
    
  "src/third_party/webpagereplay":
    (Var("googlecode_url") % "web-page-replay") + "/trunk@540",

  "src/third_party/pywebsocket/src":
    (Var("googlecode_url") % "pywebsocket") + "/trunk/src@662",

  "src/third_party/opus/src":
  (Var("chromium_git")) + '/chromium/deps/opus.git@dd52457296df1ef41bae8e28dc321d6798509172',
 
  "src/media/cdm/ppapi/api":
    "/trunk/deps/cdm@249141",

  "src/third_party/mesa/src":
    (Var("chromium_git")) + '/chromium/deps/mesa.git@ff34f1e559362fbff2c693ed16effb3046dba8e9',
 
  "src/third_party/cld_2/src":
    (Var("googlecode_url") % "cld2") + "/trunk@84",

  "src/chrome/browser/resources/pdf/html_office":
     Var("chromium_git") +
         "/chromium/html-office-public.git@6451249cec79299a52083373c9a370ef25471023",

  "src/third_party/libwebm/source":
    Var("chromium_git") +
      "/webm/libwebm.git@0f7815b036651e242ec8c2fcfb59fe54f69be1a8",
}


deps_os = {
  "win": {
    "src/chrome/tools/test/reference_build/chrome_win":
      "/trunk/deps/reference_builds/chrome_win@237381",

    "src/third_party/cygwin":
      "/trunk/deps/third_party/cygwin@231940",

    "src/third_party/psyco_win32":
      "/trunk/deps/third_party/psyco_win32@237949",

    "src/third_party/bison":
      "/trunk/deps/third_party/bison@147303",

    "src/third_party/gperf":
      "/trunk/deps/third_party/gperf@147304",

    "src/third_party/perl":
      "/trunk/deps/third_party/perl@147900",

    "src/third_party/lighttpd":
      "/trunk/deps/third_party/lighttpd@" + Var("lighttpd_revision"),

    # Parses Windows PE/COFF executable format.
    "src/third_party/pefile":
      (Var("googlecode_url") % "pefile") + "/trunk@63",

    # NSS, for SSLClientSocketNSS.
    "src/third_party/nss":
      "/trunk/deps/third_party/nss@" + Var("nss_revision"),

    "src/third_party/swig/win":
      "/trunk/deps/third_party/swig/win@" + Var("swig_revision"),

    # GNU binutils assembler for x86-32.
    "src/third_party/gnu_binutils":
      (Var("nacl_trunk") + "/deps/third_party/gnu_binutils@" +
       Var("nacl_tools_revision")),
    # GNU binutils assembler for x86-64.
    "src/third_party/mingw-w64/mingw/bin":
      (Var("nacl_trunk") + "/deps/third_party/mingw-w64/mingw/bin@" +
       Var("nacl_tools_revision")),

    # Dependencies used by libjpeg-turbo
    "src/third_party/yasm/binaries":
      "/trunk/deps/third_party/yasm/binaries@154708",

    # Binary level profile guided optimizations. This points to the
    # latest release binaries for the toolchain.
    "src/third_party/syzygy/binaries":
      (Var("googlecode_url") % "sawbuck") + "/trunk/syzygy/binaries@2021",

    # Binaries for nacl sdk.
    "src/third_party/nacl_sdk_binaries":
      "/trunk/deps/third_party/nacl_sdk_binaries@111576",
  },
  "ios": {
    "src/third_party/google_toolbox_for_mac/src":
      (Var("googlecode_url") % "google-toolbox-for-mac") + "/trunk@" +
      Var("google_toolbox_for_mac_revision"),

    "src/third_party/nss":
      "/trunk/deps/third_party/nss@" + Var("nss_revision"),

    # class-dump utility to generate header files for undocumented SDKs
    "src/testing/iossim/third_party/class-dump":
      "/trunk/deps/third_party/class-dump@199203",

    # Code that's not needed due to not building everything
    "src/build/util/support": None,
    "src/chrome/test/data/extensions/api_test/permissions/nacl_enabled/bin": None,
    "src/chrome/test/data/perf/canvas_bench": None,
    "src/chrome/test/data/perf/frame_rate/content": None,
    "src/chrome/test/data/perf/third_party/octane": None,
    "src/media/cdm/ppapi/api": None,
    "src/native_client": None,
    "src/native_client/src/third_party/ppapi": None,
    "src/third_party/angle": None,
    "src/third_party/bidichecker": None,
    "src/third_party/cld_2/src": None,
    "src/third_party/ffmpeg": None,
    "src/third_party/hunspell_dictionaries": None,
    "src/third_party/hunspell": None,
    "src/third_party/libaddressinput/src/cpp": None,
    "src/third_party/libaddressinput/src/testdata": None,
    "src/third_party/libexif/sources": None,
    "src/third_party/libjpeg_turbo": None,
    "src/third_party/libsrtp": None,
    "src/third_party/libvpx": None,
    "src/third_party/libyuv": None,
    "src/third_party/mesa/src": None,
    "src/third_party/opus/src": None,
    "src/third_party/openmax_dl": None,
    "src/third_party/ots": None,
    "src/third_party/pymox/src": None,
    "src/third_party/safe_browsing/testing": None,
    "src/third_party/scons-2.0.1": None,
    "src/third_party/sfntly/cpp/src": None,
    "src/third_party/smhasher/src": None,
    "src/third_party/swig/Lib": None,
    "src/third_party/undoview": None,
    "src/third_party/usrsctp/usrsctplib": None,
    "src/third_party/v8-i18n": None,
    "src/third_party/webdriver/pylib": None,
    "src/third_party/webgl": None,
    "src/third_party/webpagereplay": None,
    "src/third_party/webrtc": None,
    "src/third_party/yasm/source/patched-yasm": None,
    "src/tools/page_cycler/acid3": None,
    "src/v8": None,
  },
  "mac": {
    "src/chrome/tools/test/reference_build/chrome_mac":
      "/trunk/deps/reference_builds/chrome_mac@237381",

    "src/third_party/google_toolbox_for_mac/src":
      (Var("googlecode_url") % "google-toolbox-for-mac") + "/trunk@" +
      Var("google_toolbox_for_mac_revision"),

    "src/third_party/pdfsqueeze":
      (Var("googlecode_url") % "pdfsqueeze") + "/trunk@5",

    "src/third_party/lighttpd":
      "/trunk/deps/third_party/lighttpd@" + Var("lighttpd_revision"),

    "src/third_party/swig/mac":
      "/trunk/deps/third_party/swig/mac@" + Var("swig_revision"),

    # NSS, for SSLClientSocketNSS.
    "src/third_party/nss":
      "/trunk/deps/third_party/nss@" + Var("nss_revision"),

    "src/chrome/installer/mac/third_party/xz/xz":
      "/trunk/deps/third_party/xz@233311",
  },
  "unix": {
    # Linux, really.
    "src/chrome/tools/test/reference_build/chrome_linux":
      "/trunk/deps/reference_builds/chrome_linux64@237381",

    "src/third_party/xdg-utils":
      "/trunk/deps/third_party/xdg-utils@203785",

    "src/third_party/swig/linux":
      "/trunk/deps/third_party/swig/linux@" + Var("swig_revision"),

    "src/third_party/lss":
      Var("chromium_git") + '/external/linux-syscall-support/lss.git@e6c7682c40c27527894fbb8bcba38f77edbbb6b7',

    "src/third_party/openssl":
    'https://android.googlesource.com/platform' +
    '/external/chromium_org/third_party/openssl.git@bab551292a524df842435aded34751e598bfe30d',

    "src/third_party/gold":
      "/trunk/deps/third_party/gold@228995",

    "src/third_party/libmtp":
      "/trunk/deps/third_party/libmtp@206535",

    # Used on Linux only. CrOS already has a copy.
    "src/third_party/mtpd/source":
      Var("chromiumos_git") + "/platform/mtpd.git" +
      "@e4e4656e9aa710f0617dab8746ab6116c0506ceb",

    # Used on Linux only. CrOS already has a copy.
    "src/third_party/cros_dbus_cplusplus/source":
      Var("chromiumos_git") + "/third_party/dbus-cplusplus.git" +
      "@e4120532bbf3ca9f743b0be1f539381a54d16867",

    # For Linux and Chromium OS.
    "src/third_party/cros_system_api":
      Var("chromiumos_git") + "/platform/system_api.git" +
      "@874a39664f1538b1855391f98bf14026a5dd2c24",

    # Note that this is different from Android's freetype repo.
    "src/third_party/freetype2/src":
      Var("chromium_git") + "/chromium/src/third_party/freetype2.git" +
      "@d699c2994ecc178c4ed05ac2086061b2034c2178",

    # Build tools for targeting ChromeOS.
    "src/third_party/chromite":
      Var("chromiumos_git") + "/chromite.git" +
      "@1ee2901d33ae698d1f2a1d95e9f3fd5bbd5f13f9",

    # Dependency of chromite.git.
    "src/third_party/pyelftools":
      Var("chromiumos_git") + "/third_party/pyelftools.git" +
      "@bdc1d380acd88d4bfaf47265008091483b0d614e",

    "src/third_party/undoview":
      "/trunk/deps/third_party/undoview@119694",

    "src/third_party/liblouis/src":
      Var("chromium_git") +
      "/external/liblouis.git@3c2daee56250162e5a75830871601d74328d39f5",

    # Used for embedded builds. CrOS & Linux use the system version.
    "src/third_party/fontconfig/src":
      Var("chromium_git") + "/external/fontconfig.git" +
      "@f16c3118e25546c1b749f9823c51827a60aeb5c1",
  },
  "android": {
    "src/third_party/android_tools":
      Var("chromium_git") + "/android_tools.git" +
      "@0582bdc17b4829beb522975441546a4eb99b11b5",

    "src/third_party/aosp":
      "/trunk/deps/third_party/aosp@148330",

    "src/third_party/apache-mime4j":
       (Var("chromium_git")) + '/chromium/deps/apache-mime4j.git@28cb1108bff4b6cf0a2e86ff58b3d025934ebe3a',

    "src/third_party/findbugs":
      "/trunk/deps/third_party/findbugs@245039",

    "src/third_party/freetype":
      Var("chromium_git") + "/chromium/src/third_party/freetype.git" +
      "@a2b9955b49034a51dfbc8bf9f4e9d312149cecac",

    "src/third_party/guava/src":
      Var("chromium_git") + "/external/guava-libraries.git" +
      "@c523556ab7d0f05afadebd20e7768d4c16af8771",

    "src/third_party/httpcomponents-client":
      (Var("chromium_git")) + '/chromium/deps/httpcomponents-client.git@285c4dafc5de0e853fa845dce5773e223219601c',

    "src/third_party/httpcomponents-core":
      (Var("chromium_git")) + '/chromium/deps/httpcomponents-core.git@9f7180a96f8fa5cab23f793c14b413356d419e62',

    "src/third_party/jarjar":
      (Var("chromium_git")) + '/chromium/deps/jarjar.git@2e1ead4c68c450e0b77fe49e3f9137842b8b6920',

    "src/third_party/jsr-305/src":
      (Var("chromium_git")) + '/external/jsr-305.git@642c508235471f7220af6d5df2d3210e3bfc0919',

    "src/third_party/lss":
      Var("chromium_git") + '/external/linux-syscall-support/lss.git@e6c7682c40c27527894fbb8bcba38f77edbbb6b7',

    "src/third_party/openssl":
      'https://android.googlesource.com/platform' +
    '/external/chromium_org/third_party/openssl.git@bab551292a524df842435aded34751e598bfe30d',

    "src/third_party/eyesfree/src/android/java/src/com/googlecode/eyesfree/braille":
    (Var("chromium_git")) + '/external/eyes-free/braille/client/src/com/googlecode/eyesfree/braille.git@77bf6edb0138e3a38a2772248696f130dab45e34',
 
    # Android shouldn't use this address validation library.
    "src/third_party/libaddressinput/src/cpp": None,
    "src/third_party/libaddressinput/src/testdata": None,
  },
}


include_rules = [
  # Everybody can use some things.
  "+base",
  "+build",
  "+ipc",

  # Everybody can use headers generated by tools/generate_library_loader.
  "+library_loaders",

  "+testing",
  "+third_party/icu/source/common/unicode",
  "+third_party/icu/source/i18n/unicode",
  "+url",
]


# checkdeps.py shouldn't check include paths for files in these dirs:
skip_child_includes = [
  "breakpad",
  "delegate_execute",
  "metro_driver",
  "native_client_sdk",
  "o3d",
  "pdf",
  "sdch",
  "skia",
  "testing",
  "third_party",
  "v8",
  "win8",
]


hooks = [
  {
    # This downloads binaries for Native Client's newlib toolchain.
    # Done in lieu of building the toolchain from scratch as it can take
    # anywhere from 30 minutes to 4 hours depending on platform to build.
    "name": "nacltools",
    "pattern": ".",
    "action": [
        "python", "src/build/download_nacl_toolchains.py",
         "--no-arm-trusted",
         "--keep",
    ],
  },
  {
    # Downloads an ARM sysroot image to src/arm-sysroot. This image updates
    # at about the same rate that the chrome build deps change.
    # This script is a no-op except for linux users who have
    # target_arch=arm in their GYP_DEFINES.
    "name": "sysroot",
    "pattern": ".",
    "action": ["python", "src/build/linux/install-arm-sysroot.py",
               "--linux-only"],
  },
  {
    # Downloads the Debian Wheezy sysroot to chrome/installer/linux if needed.
    # This sysroot updates at about the same rate that the chrome build deps
    # change. This script is a no-op except for linux users who are doing
    # official chrome builds.
    "name": "sysroot",
    "pattern": ".",
    "action": [
        "python",
        "src/chrome/installer/linux/sysroot_scripts/install-debian.wheezy.sysroot.py",
        "--linux-only",
        "--arch=amd64"],
  },
  {
    # Same as above, but for 32-bit Linux.
    "name": "sysroot",
    "pattern": ".",
    "action": [
        "python",
        "src/chrome/installer/linux/sysroot_scripts/install-debian.wheezy.sysroot.py",
        "--linux-only",
        "--arch=i386"],
  },
  {
    # Pull clang on mac. If nothing changed, or on non-mac platforms, this takes
    # zero seconds to run. If something changed, it downloads a prebuilt clang,
    # which takes ~20s, but clang speeds up builds by more than 20s.
    "name": "clang",
    "pattern": ".",
    "action": ["python", "src/tools/clang/scripts/update.py", "--mac-only"],
  },
  {
    # Update LASTCHANGE. This is also run by export_tarball.py in
    # src/tools/export_tarball - please keep them in sync.
    "name": "lastchange",
    "pattern": ".",
    "action": ["python", "src/build/util/lastchange.py",
               "-o", "src/build/util/LASTCHANGE"],
  },
  {
    # Update LASTCHANGE.blink. This is also run by export_tarball.py in
    # src/tools/export_tarball - please keep them in sync.
    "name": "lastchange",
    "pattern": ".",
    "action": ["python", "src/build/util/lastchange.py",
               "-s", "src/third_party/WebKit",
               "-o", "src/build/util/LASTCHANGE.blink"],
  },
  # Pull GN binaries. This needs to be before running GYP below.
  {
    "name": "gn_win",
    "pattern": "src/tools/gn/bin/win/gn.exe.sha1",
    "action": [ "download_from_google_storage",
                "--no_resume",
                "--platform=win32",
                "--no_auth",
                "--bucket", "chromium-gn",
                "-s", "src/tools/gn/bin/win/gn.exe.sha1",
    ],
  },
  {
    "name": "gn_mac",
    "pattern": "src/tools/gn/bin/mac/gn.sha1",
    "action": [ "download_from_google_storage",
                "--no_resume",
                "--platform=darwin",
                "--no_auth",
                "--bucket", "chromium-gn",
                "-s", "src/tools/gn/bin/mac/gn.sha1",
    ],
  },
  {
    "name": "gn_linux",
    "pattern": "src/tools/gn/bin/linux/gn.sha1",
    "action": [ "download_from_google_storage",
                "--no_resume",
                "--platform=linux*",
                "--no_auth",
                "--bucket", "chromium-gn",
                "-s", "src/tools/gn/bin/linux/gn.sha1",
    ],
  },
  {
    "name": "gn_linux32",
    "pattern": "src/tools/gn/bin/linux/gn32.sha1",
    "action": [ "download_from_google_storage",
                "--no_resume",
                "--platform=linux*",
                "--no_auth",
                "--bucket", "chromium-gn",
                "-s", "src/tools/gn/bin/linux/gn32.sha1",
    ],
  },
  # Pull clang-format binaries using checked-in hashes.
  {
    "name": "clang_format_win",
    "pattern": "src/third_party/clang_format/bin/win/clang-format.exe.sha1",
    "action": [ "download_from_google_storage",
                "--no_resume",
                "--platform=win32",
                "--no_auth",
                "--bucket", "chromium-clang-format",
                "-s", "src/third_party/clang_format/bin/win/clang-format.exe.sha1",
    ],
  },
  {
    "name": "clang_format_mac",
    "pattern": "src/third_party/clang_format/bin/mac/clang-format.sha1",
    "action": [ "download_from_google_storage",
                "--no_resume",
                "--platform=darwin",
                "--no_auth",
                "--bucket", "chromium-clang-format",
                "-s", "src/third_party/clang_format/bin/mac/clang-format.sha1",
    ],
  },
  {
    "name": "clang_format_linux",
    "pattern": "src/third_party/clang_format/bin/linux/clang-format.sha1",
    "action": [ "download_from_google_storage",
                "--no_resume",
                "--platform=linux*",
                "--no_auth",
                "--bucket", "chromium-clang-format",
                "-s", "src/third_party/clang_format/bin/linux/clang-format.sha1",
    ],
  },
  # Pull eu-strip binaries using checked-in hashes.
  {
    "name": "eu-strip",
    "pattern": "src/build/linux/bin/eu-strip.sha1",
    "action": [ "download_from_google_storage",
                "--no_resume",
                "--platform=linux*",
                "--no_auth",
                "--bucket", "chromium-eu-strip",
                "-s", "src/build/linux/bin/eu-strip.sha1",
    ],
  },
  {
    # A change to a .gyp, .gypi, or to GYP itself should run the generator.
    "name": "gyp",
    "pattern": ".",
    "action": ["python", "src/build/gyp_chromium"],
  },
]
