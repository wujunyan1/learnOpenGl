set(SUB_DIR "${LIB_SRC_PATH}/LibPNG")
set(LIBPNG_HEADER_FILES ${SUB_DIR}/png.h
            ${SUB_DIR}/pngconf.h
)


# List the source files
set(LIBPNG_HEADER_FILES ${SUB_DIR}/png.c
         ${SUB_DIR}/pngerror.c
         #pnggccrd.c
         ${SUB_DIR}/pngget.c
         ${SUB_DIR}/pngmem.c
         ${SUB_DIR}/pngpread.c
         ${SUB_DIR}/pngread.c
         ${SUB_DIR}/pngrio.c
         ${SUB_DIR}/pngrtran.c
         ${SUB_DIR}/pngrutil.c
         ${SUB_DIR}/pngset.c
         ${SUB_DIR}/pngtrans.c
         #pngvcrd.c
         ${SUB_DIR}/pngwio.c
         ${SUB_DIR}/pngwrite.c
         ${SUB_DIR}/pngwtran.c
         ${SUB_DIR}/pngwutil.c
)