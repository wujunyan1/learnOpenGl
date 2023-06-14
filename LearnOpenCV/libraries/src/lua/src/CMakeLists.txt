# ---------------------------------------------------------------------
# set include files
set(LIB_NAME "liblua")
set(LIB_SRC_PATH ${PROJECT_SOURCE_DIR}/lua/src)
set(LIB_INCLUDE_PATH ${PROJECT_SOURCE_DIR}/lua/include)

include_directories( ${LIB_INCLUDE_PATH} )
include_directories( ${LIB_SRC_PATH} )

file(GLOB_RECURSE HEADER_FILES *.h *.hpp *.inl)
set(SOURCE_FILES lapi.c lcode.c ldebug.c ldo.c ldump.c lfunc.c lgc.c llex.c 
	lobject.c lopcodes.c lparser.c lstate.c lstring.c ltable.c ltm.c 
	lundump.c lvm.c lzio.c lctype.c lbitlib.c lmem.c ltablib.c 
	lauxlib.c lbaselib.c ldblib.c liolib.c lmathlib.c loslib.c 
	lstrlib.c loadlib.c linit.c lcorolib.c lutf8lib.c)

set(ALL_FILES ${HEADER_FILES} ${SOURCE_FILES})


add_library(${LIB_NAME} ${LIBRARY_TYPE} ${HEADER_FILES} ${SOURCE_FILES})

set_target_properties(${LIB_NAME} PROPERTIES PREFIX "")
set_target_properties(${LIB_NAME} PROPERTIES SUFFIX "${LIB_SUFFIX}")

set_target_properties(${LIB_NAME} PROPERTIES DEBUG_OUTPUT_NAME "${LIB_NAME}_d")
set_target_properties(${LIB_NAME} PROPERTIES MINSIZEREL_OUTPUT_NAME ${LIB_NAME})
set_target_properties(${LIB_NAME} PROPERTIES RELEASE_OUTPUT_NAME ${LIB_NAME})
set_target_properties(${LIB_NAME} PROPERTIES RELWITHDEBINFO_OUTPUT_NAME ${LIB_NAME})

message(STATUS "Configure success!")
