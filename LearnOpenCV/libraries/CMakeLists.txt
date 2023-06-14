cmake_minimum_required(VERSION 3.13)

if(COMMAND cmake_policy)  
	cmake_policy(SET CMP0015 NEW)  
endif(COMMAND cmake_policy)  

project(LIBRARIES)

include("${PROJECT_SOURCE_DIR}/../CMakes/Base.cmake")
include("${PROJECT_SOURCE_DIR}/../CMakes/SetOption.cmake")

OPTION(CHECK_ENV "Check env and gen env headers" ON)

set(LIBRARY_TYPE STATIC)
set(BUILD_SHARED_LIBS OFF)
#[[if(LORD_PLATFORM_WIN32)
set(LIBRARY_TYPE SHARED)
set(BUILD_SHARED_LIBS ON)
set(LIB_SUFFIX ".dll")
endif()]]


set(LIBRARIES_ROOT_PATH "${PROJECT_SOURCE_DIR}")
set(PROJECT_SOURCE_DIR "${LIBRARIES_ROOT_PATH}/src")


set(LIBRARIES_SRC_PATH "${LIBRARIES_ROOT_PATH}/src")
set(LIBRARIES_BIN_PATH "${LIBRARIES_ROOT_PATH}/Bin/Debug")

link_directories("${LIBRARIES_BIN_PATH}")

message(STATUS "\${CMAKE_BUILD_TYPE}: ${CMAKE_BUILD_TYPE}")

message(STATUS "\${PROJECT_SOURCE_DIR}: ${PROJECT_SOURCE_DIR}")
message(STATUS "\${PROJECT_BINARY_DIR}: ${PROJECT_BINARY_DIR}")
message(STATUS "\${LIBRARIES_ROOT_PATH}: ${LIBRARIES_ROOT_PATH}")
message(STATUS "\${LIBRARIES_SRC_PATH}: ${LIBRARIES_SRC_PATH}")
message(STATUS "\${LIBRARIES_BIN_PATH}: ${LIBRARIES_BIN_PATH}")

# Add sub directories
add_custom_target(SELECTED_TARGETS ALL)
add_subdirectory("src")

