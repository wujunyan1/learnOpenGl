# ---------------------------------------------------------------------
# set include files
set(LIB_NAME "libFreeImage")
set(LIB_SRC_PATH "${PROJECT_SOURCE_DIR}/FreeImage/src")
set(LIB_INCLUDE_PATH "${PROJECT_SOURCE_DIR}/FreeImage/include")
set(ZLIB_INCLUDE_PATH ${PROJECT_SOURCE_DIR}/zlib/src)

include( ${LIB_SRC_PATH}/DeprecationManager/CMakeLists.txt )
include( ${LIB_SRC_PATH}/FreeImage/CMakeLists.txt )
include( ${LIB_SRC_PATH}/FreeImageToolkit/CMakeLists.txt )
if(LORD_PLATFORM_WIN32)
include( ${LIB_SRC_PATH}/LibJPEG/CMakeLists.txt )
include( ${LIB_SRC_PATH}/LibPNG/CMakeLists.txt )
endif()
include( ${LIB_SRC_PATH}/LibOpenJPEG/CMakeLists.txt )
include( ${LIB_SRC_PATH}/LibMNG/CMakeLists.txt )
include( ${LIB_SRC_PATH}/Metadata/CMakeLists.txt )
include( ${LIB_SRC_PATH}/LibWebP/CMakeLists.txt )


include_directories( ${LIB_INCLUDE_PATH} )
include_directories( ${LIB_INCLUDE_PATH}/FreeImage )
include_directories( ${LIB_SRC_PATH} )
include_directories( ${LIB_SRC_PATH}/DeprecationManager )
include_directories( ${LIB_SRC_PATH}/FreeImage )
include_directories( ${LIB_SRC_PATH}/FreeImageToolKit )
if(LORD_PLATFORM_WIN32)
include_directories( ${LIB_SRC_PATH}/LibJPEG )
include_directories( ${LIB_SRC_PATH}/LibPNG )
endif()
include_directories( ${LIB_SRC_PATH}/LibOpenJPEG )
include_directories( ${LIB_SRC_PATH}/LibMNG )

include_directories( ${LIB_SRC_PATH}/Metadata )
include_directories( ${LIB_SRC_PATH}/LibWebP )
include_directories( ${ZLIB_INCLUDE_PATH} )


set(HEADER_FILES ${DEPRECATIONMANAGER_HEADER_FILES} ${FREEIMAGE_HEADER_FILES} ${FREEIMAGETOOLKIT_HEADER_FILES} ${LIBJPEG_HEADER_FILES}
                  ${LIBOPENJPEG_HEADER_FILES} ${LIBPNG_HEADER_FILES} ${LIBMNG_HEADER_FILES} ${METADATA_HEADER_FILES} ${ZLIB_HEADER_FILES} ${WEBP_HEADER_FILES})
				  
set(SOURCE_FILES  ${DEPRECATIONMANAGER_SOURCE_FILES} ${FREEIMAGE_SOURCE_FILES} ${FREEIMAGETOOLKIT_SOURCE_FILES} ${LIBJPEG_SOURCE_FILES}
                  ${LIBOPENJPEG_SOURCE_FILES} ${LIBPNG_SOURCE_FILES} ${LIBMNG_SOURCE_FILES} ${METADATA_SOURCE_FILES} ${ZLIB_SOURCE_FILES} ${WEBP_SOURCE_FILES})

set(ALL_FILES ${HEADER_FILES} ${SOURCE_FILES})


macro(GROUP_FILES src_files)
        set(cur_dir ${CMAKE_CURRENT_SOURCE_DIR})
        foreach(group_files ${${src_files}})
            string(REGEX REPLACE ${cur_dir}/\(.*\) \\1 sgbd_fpath ${group_files})
            string(REGEX REPLACE "\(.*\)/.*" \\1 sgbd_group_name ${sgbd_fpath})
            string(COMPARE EQUAL ${sgbd_fpath} ${sgbd_group_name} sgbd_nogroup)
            string(REPLACE "/" "\\" sgbd_group_name ${sgbd_group_name})
            if(sgbd_nogroup)
                set(sgbd_group_name "Main")
            endif(sgbd_nogroup)
			
            source_group(${sgbd_group_name} FILES ${group_files})
        endforeach(group_files)
endmacro(GROUP_FILES)

GROUP_FILES(ALL_FILES)



add_library(${LIB_NAME} STATIC ${HEADER_FILES} ${SOURCE_FILES})


set_target_properties(${LIB_NAME} PROPERTIES PREFIX "")
set_target_properties(${LIB_NAME} PROPERTIES SUFFIX "${LIB_STATIC_SUFFIX}")

set_target_properties(${LIB_NAME} PROPERTIES DEBUG_OUTPUT_NAME "${LIB_NAME}_d")
set_target_properties(${LIB_NAME} PROPERTIES MINSIZEREL_OUTPUT_NAME ${LIB_NAME})
set_target_properties(${LIB_NAME} PROPERTIES RELEASE_OUTPUT_NAME ${LIB_NAME})
set_target_properties(${LIB_NAME} PROPERTIES RELWITHDEBINFO_OUTPUT_NAME ${LIB_NAME})

message(STATUS "Configure success!")
