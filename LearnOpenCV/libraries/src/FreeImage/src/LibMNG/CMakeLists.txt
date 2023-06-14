# List the header files
set(SUB_DIR "${LIB_SRC_PATH}/LibMNG")
SET(LIBMNG_HEADER_FILES ${SUB_DIR}/libmng.h
            ${SUB_DIR}/libmng_chunk_descr.h
            ${SUB_DIR}/libmng_chunk_io.h
            ${SUB_DIR}/libmng_chunk_prc.h
            ${SUB_DIR}/libmng_chunks.h
            ${SUB_DIR}/libmng_cms.h
            ${SUB_DIR}/libmng_conf.h
            ${SUB_DIR}/libmng_data.h
            ${SUB_DIR}/libmng_display.h
            ${SUB_DIR}/libmng_dither.h
            ${SUB_DIR}/libmng_error.h
            ${SUB_DIR}/libmng_filter.h
            ${SUB_DIR}/libmng_jpeg.h
            ${SUB_DIR}/libmng_memory.h
            ${SUB_DIR}/libmng_object_prc.h
            ${SUB_DIR}/libmng_objects.h
            ${SUB_DIR}/libmng_pixels.h
            ${SUB_DIR}/libmng_read.h
            ${SUB_DIR}/libmng_trace.h
            ${SUB_DIR}/libmng_types.h
            ${SUB_DIR}/libmng_write.h
            ${SUB_DIR}/libmng_zlib.h
)


# List the source files
SET(LIBMNG_SOURCE_FILES  ${SUB_DIR}/libmng_callback_xs.c
         ${SUB_DIR}/libmng_chunk_descr.c
         ${SUB_DIR}/libmng_chunk_io.c
         ${SUB_DIR}/libmng_chunk_prc.c
         #libmng_chunk_xs.c
         ${SUB_DIR}/libmng_cms.c
         ${SUB_DIR}/libmng_display.c
         ${SUB_DIR}/libmng_dither.c
         ${SUB_DIR}/libmng_error.c
         ${SUB_DIR}/libmng_filter.c
         ${SUB_DIR}/libmng_hlapi.c
         ${SUB_DIR}/libmng_jpeg.c
         ${SUB_DIR}/libmng_object_prc.c
         ${SUB_DIR}/libmng_pixels.c
         ${SUB_DIR}/libmng_prop_xs.c
         ${SUB_DIR}/libmng_read.c
         #libmng_trace.c
         ${SUB_DIR}/libmng_write.c
         ${SUB_DIR}/libmng_zlib.c
)
