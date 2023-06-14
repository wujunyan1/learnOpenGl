# ---------------------------------------------------------------------
# set include files
set(LIB_NAME "libg3log")
set(LIB_SRC_PATH ${PROJECT_SOURCE_DIR}/g3log/src)
set(LIB_INCLUDE_PATH ${PROJECT_SOURCE_DIR}/g3log/include)

include_directories( ${LIB_INCLUDE_PATH} )
include_directories( ${LIB_SRC_PATH} )

file(GLOB_RECURSE HEADER_FILES *.h *.hpp *.inl)
set(SOURCE_FILES filesink.cpp
	g3log.cpp
	logcapture.cpp
	loglevels.cpp
	logmessage.cpp
	logworker.cpp
	time.cpp)

if(${LORD_PLATFORM_WIN32})
  add_definitions("-D_CRT_SECURE_NO_WARNINGS")
  add_definitions("-DDISABLE_VECTORED_EXCEPTIONHANDLING")
  add_definitions("-DDISABLE_FATAL_SIGNALHANDLING")
  list(APPEND SOURCE_FILES crashhandler_windows.cpp)
  list(APPEND SOURCE_FILES stacktrace_windows.cpp)
else()
  list(APPEND SOURCE_FILES crashhandler_unix.cpp)
endif()


add_library(${LIB_NAME} STATIC ${HEADER_FILES} ${SOURCE_FILES})

set_target_properties(${LIB_NAME} PROPERTIES PREFIX "")
set_target_properties(${LIB_NAME} PROPERTIES SUFFIX "${LIB_STATIC_SUFFIX}")

set_target_properties(${LIB_NAME} PROPERTIES DEBUG_OUTPUT_NAME "${LIB_NAME}_d")
set_target_properties(${LIB_NAME} PROPERTIES MINSIZEREL_OUTPUT_NAME ${LIB_NAME})
set_target_properties(${LIB_NAME} PROPERTIES RELEASE_OUTPUT_NAME ${LIB_NAME})
set_target_properties(${LIB_NAME} PROPERTIES RELWITHDEBINFO_OUTPUT_NAME ${LIB_NAME})

message(STATUS "Configure success!")
