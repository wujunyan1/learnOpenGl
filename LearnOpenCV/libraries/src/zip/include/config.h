#pragma once
#ifdef OS_WIN32
	#include "config_win32.h"
#endif

#ifdef OS_LINUX
	#include "config_linux.h"
#endif

#ifdef OS_ANDROID
    #include "config_android.h"
#endif

#ifdef OS_IOS
    #include "config_ios.h"
#endif
