if(LOAD_SHARED)
add_definitions("-DBUILDING_LIBCURL")
else()
add_definitions("-DCURL_STATICLIB")
endif()
