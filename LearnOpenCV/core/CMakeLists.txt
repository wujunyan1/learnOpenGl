cmake_minimum_required(VERSION 3.15)

project(EngineCore)


# ---------------------------------------------------------------------
# set thrd library
LOAD_THRDLIBRARY(
    lua
    luasocket
    zlib
    glm
    cpr
    zippp
    raknet
    freeType
    freeImage
    sparsehash
    RapidXml
    rapidjson
    curl
)

# ---------------------------------------------------------------------
# set include files

#[[set(INCLUDE_FILES 	${PROJECT_SOURCE_DIR}
	${PROJECT_SOURCE_DIR}/Blockman
	${PROJECT_SOURCE_DIR}/External
  	${LORD_SRC_PATH}/Core
  	${LORD_SRC_PATH}/GLES2Render
	${LOGIC_SRC_PATH}
	${SERVER_SRC_PATH})

include_directories( ${INCLUDE_FILES} )]]


# ---------------------------------------------------------------------

file(GLOB_RECURSE HEADER_FILES *.h *.inl)
file(GLOB_RECURSE SOURCE_FILES *.cpp *.c)

set(ALL_FILES ${HEADER_FILES} ${SOURCE_FILES})

macro(GROUP_FILES src_files)
        set(cur_dir ${CMAKE_CURRENT_SOURCE_DIR})
        foreach(group_files ${${src_files}})
            #message(${group_files})
            string(REGEX REPLACE ${cur_dir}/\(.*\) \\1 sgbd_fpath ${group_files})
            string(REGEX REPLACE "\(.*\)/.*" \\1 sgbd_group_name ${sgbd_fpath})
            string(COMPARE EQUAL ${sgbd_fpath} ${sgbd_group_name} sgbd_nogroup)
            string(REPLACE "/" "\\" sgbd_group_name ${sgbd_group_name})
            #if(sgbd_nogroup)
                #set(sgbd_group_name "Logic")
            #endif(sgbd_nogroup)
			
            source_group(${sgbd_group_name} FILES ${group_files})
        endforeach(group_files)
endmacro(GROUP_FILES)

GROUP_FILES(ALL_FILES)


add_library(EngineCore STATIC ${HEADER_FILES} ${SOURCE_FILES})