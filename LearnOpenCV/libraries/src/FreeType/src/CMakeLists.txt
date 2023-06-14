# ---------------------------------------------------------------------
# set include files
set(LIB_NAME "libFreeType")
set(LIB_SRC_PATH ${PROJECT_SOURCE_DIR}/FreeType/src)
set(LIB_INCLUDE_PATH ${PROJECT_SOURCE_DIR}/FreeType/include)

include_directories( ${LIB_INCLUDE_PATH} )
include_directories( ${LIB_SRC_PATH})
include_directories( ${PROJECT_SOURCE_DIR}/zlib/src)

file(GLOB_RECURSE HEADER_FILES *.h *.hpp *.inl)
set(SOURCE_FILES autofit/autofit.c
  base/ftbase.c
  base/ftbbox.c
  base/ftbdf.c
  base/ftbitmap.c
  base/ftcid.c
  base/ftfstype.c
  base/ftgasp.c
  base/ftglyph.c
  base/ftgxval.c
  base/ftinit.c
  base/ftmm.c
  base/ftotval.c
  base/ftpatent.c
  base/ftpfr.c
  base/ftstroke.c
  base/ftsynth.c
  base/ftsystem.c
  base/fttype1.c
  base/ftwinfnt.c
  bdf/bdf.c
  cache/ftcache.c
  cff/cff.c
  cid/type1cid.c
  gzip/ftgzip.c
  lzw/ftlzw.c
  pcf/pcf.c
  pfr/pfr.c
  psaux/psaux.c
  pshinter/pshinter.c
  psnames/psnames.c
  raster/raster.c
  sfnt/sfnt.c
  smooth/smooth.c
  truetype/truetype.c
  type1/type1.c
  type42/type42.c
  winfonts/winfnt.c)
if (WIN32)
list(APPEND SOURCE_FILES base/ftdebug_win32.c)
else()
list(APPEND SOURCE_FILES base/ftdebug.c)
endif()
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


target_compile_definitions(
  ${LIB_NAME}  PRIVATE FT2_BUILD_LIBRARY)
  
SET_TARGET_PROPERTIES(${LIB_NAME} PROPERTIES LINKER_LANGUAGE CXX)

set_target_properties(${LIB_NAME} PROPERTIES PREFIX "")
set_target_properties(${LIB_NAME} PROPERTIES SUFFIX "${LIB_STATIC_SUFFIX}")

set_target_properties(${LIB_NAME} PROPERTIES DEBUG_OUTPUT_NAME "${LIB_NAME}_d")
set_target_properties(${LIB_NAME} PROPERTIES MINSIZEREL_OUTPUT_NAME ${LIB_NAME})
set_target_properties(${LIB_NAME} PROPERTIES RELEASE_OUTPUT_NAME ${LIB_NAME})
set_target_properties(${LIB_NAME} PROPERTIES RELWITHDEBINFO_OUTPUT_NAME ${LIB_NAME})

message(STATUS "Configure success!")
