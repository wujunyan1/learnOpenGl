
if (LORD_PLATFORM_LINUX)
	add_definitions("-DLUA_USE_LINUX")
endif()

if (LORD_PLATFORM_IOS)
	add_definitions("-DLUA_USE_LINUX")
	add_definitions("-DLUA_USE_MACOSX_SYSTEM")
endif()

add_definitions("-DLUA_COMPAT_5_2")

if(BUILD_SHARED_LIBS)
	add_definitions("-DLUA_BUILD_AS_DLL")
endif()
add_subdirectory(src)
