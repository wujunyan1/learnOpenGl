if(BUILD_SHARED_LIBS)
add_definitions("-DZLIB_DLL")
endif()
add_subdirectory(src)