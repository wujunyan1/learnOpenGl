
set(CMAKE_ALLOW_LOSSE_LOOP_CONSTRUCTS ON)
SET(CMAKE_VERBOSE_MAKEFILE ON)

message(STATUS "Configuring build system...")
message(STATUS "CMake version: ${CMAKE_VERSION} CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")

option(LORD_STATIC "Static build" TRUE)
option(LORD_UNICODE "Using Unicode charset" FALSE)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG "${PROJECT_SOURCE_DIR}/Bin/Debug")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${PROJECT_SOURCE_DIR}/Bin/Release")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_MINSIZEREL "${PROJECT_SOURCE_DIR}/Bin/MinSizeRel")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELWITHDEBINFO "${PROJECT_SOURCE_DIR}/Bin/RelWithDebInfo")

# set(LIB_NAME_EX $<$<CONFIG:Debug>:_d>)
if(WIN32)
	message(STATUS "Platform: Windows")
	set(BUILD_SERVER_AS_LIB FALSE)
	set(LORD_PLATFORM_WIN32 TRUE)
	set(LIB_STATIC_SUFFIX ".lib")
	set(OS_NAME "WIN32")
	add_definitions("-DOS_WIN32")
	add_definitions("-D_ENABLE_EXTENDED_ALIGNED_STORAGE")
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${PROJECT_SOURCE_DIR}../../../res")
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${PROJECT_SOURCE_DIR}../../../res")
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_MINSIZEREL "${PROJECT_SOURCE_DIR}../../../res")
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO "${PROJECT_SOURCE_DIR}../../../res")
	set(CMAKE_PDB_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/Bin/")
	set(CMAKE_ILK_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/Bin/")
elseif(UNIX)
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${PROJECT_SOURCE_DIR}/Bin/Debug")
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${PROJECT_SOURCE_DIR}/Bin/Release")
	if(APPLE)
		message(STATUS "Platform: Mac iOS")
		
		set(OS_NAME "APPLE")
		set(LORD_PLATFORM_IOS TRUE)
		set(LORD_STATIC TRUE CACHE BOOL "Forcing static build for iPhone" FORCE)
		
		add_definitions("-DOS_IOS")
		add_definitions("-DOS_MACOSX")
		set(LIB_STATIC_SUFFIX ".a")
	elseif(CMAKE_SYSTEM_NAME MATCHES "Linux")
		message(STATUS "Platform: Unix/Linux")
		set(OS_NAME "LINUX")
		set(LORD_PLATFORM_LINUX TRUE)
		set(LORD_STATIC TRUE CACHE BOOL "Forcing static build for linux" FORCE)
		add_definitions("-DOS_LINUX")
		set(LIB_STATIC_SUFFIX ".a")
	endif()
endif()

set(LIB_SHARED_SUFFIX ".dll")
set(LIB_SUFFIX  ${LIB_STATIC_SUFFIX})

if(LORD_STATIC)
	add_definitions("-DLORD_STATIC")
endif()

if(LORD_UNICODE)
	add_definitions("-D_UNICODE")
endif()

if(LORD_PLATFORM_WIN32)
	# compiler building setting
	# Flags used by the compiler during all build types.
	set(CMAKE_CXX_FLAGS "/DWIN32 /D_WINDOWS /W3 /Zm1000 /EHsc /GR /MP /bigobj")
	# Flags used by the compiler during debug builds.
	set(CMAKE_CXX_FLAGS_DEBUG "/D_DEBUG /MDd /Zi /Ob0 /Od /RTC1")
	# Flags used by the compiler during release minsize builds.
	set(CMAKE_CXX_FLAGS_MINSIZEREL "/MD /O1 /Ob1 /D NDEBUG")
	# Flags used by the compiler during release builds (/MD /Ob1 /Oi /Ot /Oy /Gs will produce slightly less optimized but smaller files).
	set(CMAKE_CXX_FLAGS_RELEASE "/MD /O2 /Ob2 /D NDEBUG")
	# Flags used by the compiler during Release with Debug Info builds.
	set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "/MD /Zi /O2 /Ob1 /D NDEBUG")
	# Flags used by the compiler during all build types.
	set(CMAKE_C_FLAGS "/DWIN32 /D_WINDOWS /W3 /Zm1000 /bigobj")
	# Flags used by the compiler during debug builds.
	set(CMAKE_C_FLAGS_DEBUG "/D_DEBUG /MDd /Zi  /Ob0 /Od /RTC1")
	# Flags used by the compiler during release minsize builds.
	set(CMAKE_C_FLAGS_MINSIZEREL "/MD /O1 /Ob1 /D NDEBUG")
	# Flags used by the compiler during release builds (/MD /Ob1 /Oi /Ot /Oy /Gs will produce slightly less optimized but smaller files).
	set(CMAKE_C_FLAGS_RELEASE "/MD /O2 /Ob2 /D NDEBUG")
	# Flags used by the compiler during Release with Debug Info builds.
	set(CMAKE_C_FLAGS_RELWITHDEBINFO "/MD /Zi /O2 /Ob1 /D NDEBUG")
	
	if(USER_MACRO)
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /D${USER_MACRO}")
		set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /D${USER_MACRO}")
	endif()

	if(MSVC)
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /fp:fast")
		
		# Enable intrinsics on MSVC in debug mode
		set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /Oi")
		if (CMAKE_CL_64)
			# Visual Studio bails out on debug builds in 64bit mode unless
			# this flag is set...
			set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /bigobj")
			set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} /bigobj")
		endif ()
		
	endif()
	
	# This seems to break Xcode projects so definitely don't enable on Apple builds
	set(CMAKE_USE_RELATIVE_PATHS true)
	set(CMAKE_SUPPRESS_REGENERATION true)
		
elseif(LORD_PLATFORM_IOS)
		
elseif(LORD_PLATFORM_LINUX)
	
else()
	message(STATUS "Platform: Unknown")
endif()

