#pragma once
#ifdef OS_WIN32
	#include "curl_config_win32.h"
#endif

#ifdef OS_LINUX
	#include "curl_config_linux.h"
#endif

#ifdef OS_ANDROID
    #include "curl_config_android.h"
#endif

#ifdef OS_IOS
    #include "curl_config_ios.h"
#endif
