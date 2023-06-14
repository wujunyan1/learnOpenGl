if( NOT DEFINED LIBRARY_DIR)
set(LIBRARY_DIR ${PROJECT_SOURCE_DIR}/libraries)
endif()

set(LIBRARY_SRC_DIR ${LIBRARY_DIR}/src)

set(LIB_NAME_EX _d)
set(LIBRARY_BIN_DIR "${LIBRARY_DIR}/Bin/Debug")

link_directories(${LIBRARY_BIN_DIR})

set(LOAD_LIB_SUFFIX ${LIB_STATIC_SUFFIX})

if(LORD_PLATFORM_WIN32)
set(LOAD_AS_SHARED TRUE)
endif()

function(LOAD_THRDLIBRARY)
	foreach(LIB IN LISTS ARGN)
		file(TIMESTAMP ${LIBRARY_SRC_DIR}/${LIB}/custom_import.cmake HAVE_CUSTOM_IMPORT_CMAKE)
		if(HAVE_CUSTOM_IMPORT_CMAKE)
			include(${LIBRARY_SRC_DIR}/${LIB}/custom_import.cmake)
		else()
			if(IS_DIRECTORY "${LIBRARY_SRC_DIR}/${LIB}/include")
				include_directories("${LIBRARY_SRC_DIR}/${LIB}/include")
			endif()

			message(STATUS "${LIBRARY_BIN_DIR}/lib${LIB}${LIB_NAME_EX}${LOAD_LIB_SUFFIX}")
			file(TIMESTAMP ${LIBRARY_SRC_DIR}/${LIB}/CMakeLists.txt HAVE_LIB)
			if(HAVE_LIB)
				link_libraries(lib${LIB}${LIB_NAME_EX}${LOAD_LIB_SUFFIX})
				message(STATUS "link_libraries lib${LIB}${LIB_NAME_EX}${LOAD_LIB_SUFFIX}")
			endif()

			file(TIMESTAMP ${LIBRARY_SRC_DIR}/${LIB}/import.cmake HAVE_IMPORT_CMAKE)
			if(HAVE_IMPORT_CMAKE)
				include(${LIBRARY_SRC_DIR}/${LIB}/import.cmake)
			endif()
		endif()

	endforeach()
endfunction()
