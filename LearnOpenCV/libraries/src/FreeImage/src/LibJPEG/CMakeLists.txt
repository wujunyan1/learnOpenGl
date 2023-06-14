# List the header files
set(SUB_DIR "${LIB_SRC_PATH}/LibJPEG")
SET(LIBJPEG_HEADER_FILES ${SUB_DIR}/jconfig.h
            ${SUB_DIR}/jdct.h
            ${SUB_DIR}/jerror.h
            ${SUB_DIR}/jinclude.h
            ${SUB_DIR}/jmemsys.h
            ${SUB_DIR}/jmorecfg.h
            ${SUB_DIR}/jpegint.h
            ${SUB_DIR}/jpeglib.h
            ${SUB_DIR}/jversion.h
            ${SUB_DIR}/transupp.h
)


# List the source files
SET(LIBJPEG_SOURCE_FILES ${SUB_DIR}/jaricom.c
         ${SUB_DIR}/jcapimin.c
         ${SUB_DIR}/jcapistd.c
         ${SUB_DIR}/jcarith.c
         ${SUB_DIR}/jccoefct.c
         ${SUB_DIR}/jccolor.c
         ${SUB_DIR}/jcdctmgr.c
         ${SUB_DIR}/jchuff.c
         ${SUB_DIR}/jcinit.c
         ${SUB_DIR}/jcmainct.c
         ${SUB_DIR}/jcmarker.c
         ${SUB_DIR}/jcmaster.c
         ${SUB_DIR}/jcomapi.c
         ${SUB_DIR}/jcparam.c
         ${SUB_DIR}/jcprepct.c
         ${SUB_DIR}/jcsample.c
         ${SUB_DIR}/jctrans.c
         ${SUB_DIR}/jdapimin.c
         ${SUB_DIR}/jdapistd.c
         ${SUB_DIR}/jdarith.c
         ${SUB_DIR}/jdatadst.c
         ${SUB_DIR}/jdatasrc.c
         ${SUB_DIR}/jdcoefct.c
         ${SUB_DIR}/jdcolor.c
         ${SUB_DIR}/jddctmgr.c
         ${SUB_DIR}/jdhuff.c
         ${SUB_DIR}/jdinput.c
         ${SUB_DIR}/jdmainct.c
         ${SUB_DIR}/jdmarker.c
         ${SUB_DIR}/jdmaster.c
         ${SUB_DIR}/jdmerge.c
         ${SUB_DIR}/jdpostct.c
         ${SUB_DIR}/jdsample.c
         ${SUB_DIR}/jdtrans.c
         ${SUB_DIR}/jerror.c
         ${SUB_DIR}/jfdctflt.c
         ${SUB_DIR}/jfdctfst.c
         ${SUB_DIR}/jfdctint.c
         ${SUB_DIR}/jidctflt.c
         ${SUB_DIR}/jidctfst.c
         ${SUB_DIR}/jidctint.c
         ${SUB_DIR}/jmemmgr.c
         ${SUB_DIR}/jmemnobs.c
         ${SUB_DIR}/jquant1.c
         ${SUB_DIR}/jquant2.c
         ${SUB_DIR}/jutils.c
         ${SUB_DIR}/transupp.c
)
