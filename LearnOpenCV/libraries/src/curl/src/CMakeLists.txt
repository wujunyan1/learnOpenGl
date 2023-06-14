
set(LIB_NAME "libcurl")
set(LIB_SRC_PATH "${LIBRARIES_SRC_PATH}/curl/src")
set(LIB_INCLUDE_PATH "${LIBRARIES_SRC_PATH}/curl/include")
set(ZIB_INCLUDE_PATH "${LIBRARIES_SRC_PATH}/zlib/src")
if(WIN32)
	set(OPENSSL_INCLUDE_PATH "${LIBRARIES_SRC_PATH}/openssl/include")
endif()
# Use:
# * CURL_STATICLIB
# 需要编译的src 放到 inc.cmake里面配置了
include(${LIB_SRC_PATH}/Makefile.inc.cmake)

# The rest of the build
include_directories(${LIB_INCLUDE_PATH})
include_directories(${LIB_INCLUDE_PATH}/curl)
include_directories(${LIB_SRC_PATH})
include_directories(${ZIB_INCLUDE_PATH})
if(WIN32)
	include_directories(${OPENSSL_INCLUDE_PATH})
endif()
list(APPEND HHEADERS ${LIB_INCLUDE_PATH}/curl/curl_config.h)

link_directories("${LIBRARIES_SRC_PATH}/openssl/lib")
add_library(${LIB_NAME} ${LIBRARY_TYPE} ${HHEADERS} ${CSOURCES})

if(BUILD_SHARED_LIBS)
if(WIN32)
	target_link_libraries(${LIB_NAME} ${CURL_LIBS} libzlib${LIB_NAME_EX} libcrypto.lib libssl.lib Crypt32.lib)
else()
	target_link_libraries(${LIB_NAME} ${CURL_LIBS} libzlib${LIB_NAME_EX})
endif()
endif()

# Remove the "lib" prefix since the library is already named "libcurl".
set_target_properties(${LIB_NAME} PROPERTIES PREFIX "")
set_target_properties(${LIB_NAME} PROPERTIES SUFFIX "${LIB_SUFFIX}")

set_target_properties(${LIB_NAME} PROPERTIES DEBUG_OUTPUT_NAME "${LIB_NAME}_d")
set_target_properties(${LIB_NAME} PROPERTIES MINSIZEREL_OUTPUT_NAME ${LIB_NAME})
set_target_properties(${LIB_NAME} PROPERTIES RELEASE_OUTPUT_NAME ${LIB_NAME})
set_target_properties(${LIB_NAME} PROPERTIES RELWITHDEBINFO_OUTPUT_NAME ${LIB_NAME})