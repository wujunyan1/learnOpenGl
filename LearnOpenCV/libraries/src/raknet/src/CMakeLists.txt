# ---------------------------------------------------------------------
# set include files
set(LIB_NAME "libraknet")
set(LIB_INCLUDE_PATH ${PROJECT_SOURCE_DIR}/raknet/include/raknet)
set(LIB_INCLUDE_PATH_EXPORT ${PROJECT_SOURCE_DIR}/raknet/include)
include_directories( ${LIB_INCLUDE_PATH} )
include_directories( ${LIB_INCLUDE_PATH_EXPORT} )

file(GLOB_RECURSE HEADER_FILES *.h *.hpp *.inl)
file(GLOB_RECURSE SOURCE_FILES *.cpp *.c)

set(ALL_FILES ${HEADER_FILES} ${SOURCE_FILES})


add_library(${LIB_NAME} STATIC ${HEADER_FILES} ${SOURCE_FILES})

set_target_properties(${LIB_NAME} PROPERTIES PREFIX "")
set_target_properties(${LIB_NAME} PROPERTIES SUFFIX "${LIB_STATIC_SUFFIX}")

set_target_properties(${LIB_NAME} PROPERTIES DEBUG_OUTPUT_NAME "${LIB_NAME}_d")
set_target_properties(${LIB_NAME} PROPERTIES MINSIZEREL_OUTPUT_NAME ${LIB_NAME})
set_target_properties(${LIB_NAME} PROPERTIES RELEASE_OUTPUT_NAME ${LIB_NAME})
set_target_properties(${LIB_NAME} PROPERTIES RELWITHDEBINFO_OUTPUT_NAME ${LIB_NAME})

message(STATUS "Configure success!")
