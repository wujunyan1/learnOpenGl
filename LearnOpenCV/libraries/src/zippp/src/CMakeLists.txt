# ---------------------------------------------------------------------
# set include files
set(LIB_NAME "libzippp")
set(LIB_SRC_PATH ${PROJECT_SOURCE_DIR}/zippp/src)
set(LIB_INCLUDE_PATH ${PROJECT_SOURCE_DIR}/zippp/include)
set(ZLIB_INCLUDE_PATH ${PROJECT_SOURCE_DIR}/zlib/include)

include_directories( ${LIB_INCLUDE_PATH} )
include_directories( ${LIB_SRC_PATH} )
include_directories( ${PROJECT_SOURCE_DIR}/zip/include)
include_directories( ${ZLIB_INCLUDE_PATH} )

file(GLOB_RECURSE HEADER_FILES *.h *.hpp *.inl)
file(GLOB_RECURSE SOURCE_FILES *.cpp *.c)

add_library(${LIB_NAME} STATIC ${HEADER_FILES} ${SOURCE_FILES})


set_target_properties(${LIB_NAME} PROPERTIES PREFIX "")
set_target_properties(${LIB_NAME} PROPERTIES SUFFIX "${LIB_STATIC_SUFFIX}")

set_target_properties(${LIB_NAME} PROPERTIES DEBUG_OUTPUT_NAME "${LIB_NAME}_d")
set_target_properties(${LIB_NAME} PROPERTIES MINSIZEREL_OUTPUT_NAME ${LIB_NAME})
set_target_properties(${LIB_NAME} PROPERTIES RELEASE_OUTPUT_NAME ${LIB_NAME})
set_target_properties(${LIB_NAME} PROPERTIES RELWITHDEBINFO_OUTPUT_NAME ${LIB_NAME})

message(STATUS "Configure success!")
