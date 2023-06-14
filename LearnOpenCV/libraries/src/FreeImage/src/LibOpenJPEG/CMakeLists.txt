set(SUB_DIR "${LIB_SRC_PATH}/LibOpenJPEG")
set(LIBOPENJPEG_HEADER_FILES ${SUB_DIR}/bio.h
            ${SUB_DIR}/cio.h
            ${SUB_DIR}/dwt.h
            ${SUB_DIR}/event.h
            ${SUB_DIR}/fix.h
            ${SUB_DIR}/image.h
            ${SUB_DIR}/int.h
            ${SUB_DIR}/j2k.h
            ${SUB_DIR}/j2k_lib.h
            ${SUB_DIR}/jp2.h
            ${SUB_DIR}/jpt.h
            ${SUB_DIR}/mct.h
            ${SUB_DIR}/mqc.h
            ${SUB_DIR}/openjpeg.h
            ${SUB_DIR}/opj_includes.h
            ${SUB_DIR}/opj_malloc.h
            ${SUB_DIR}/pi.h
            ${SUB_DIR}/raw.h
            ${SUB_DIR}/t1.h
            ${SUB_DIR}/t1_luts.h
            ${SUB_DIR}/t2.h
            ${SUB_DIR}/tcd.h
            ${SUB_DIR}/tgt.h
)


# List the source files
set(LIBOPENJPEG_SCOURCE_FILES ${SUB_DIR}/bio.c
         ${SUB_DIR}/cio.c
         ${SUB_DIR}/dwt.c
         ${SUB_DIR}/event.c
         ${SUB_DIR}/image.c
         ${SUB_DIR}/j2k.c
         ${SUB_DIR}/j2k_lib.c
         ${SUB_DIR}/jp2.c
         ${SUB_DIR}/jpt.c
         ${SUB_DIR}/mct.c
         ${SUB_DIR}/mqc.c
         ${SUB_DIR}/openjpeg.c
         ${SUB_DIR}/pi.c
         ${SUB_DIR}/raw.c
         ${SUB_DIR}/t1.c
         ${SUB_DIR}/t2.c
         ${SUB_DIR}/tcd.c
         ${SUB_DIR}/tgt.c
)

