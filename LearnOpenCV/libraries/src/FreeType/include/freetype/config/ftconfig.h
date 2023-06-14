#pragma once
#ifdef OS_WIN32
#include "ftconfig_win32.h"
#endif

#ifdef OS_LINUX
#include "ftconfig_linux.h"
#endif

#ifdef OS_ANDROID
#include "ftconfig_android.h"
#endif

#ifdef OS_IOS
#include "ftconfig_ios.h"
#endif
