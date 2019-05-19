if(MSVC AND NOT "${MSVC_VERSION}" LESS 1400)
	add_definitions( "/MP" )
endif()


add_definitions(
	-DTW_STATIC
	-DTW_NO_LIB_PRAGMA
	-DTW_NO_DIRECT3D
	-DGLEW_STATIC
	-D_CRT_SECURE_NO_WARNINGS
)

### GLFW ###

add_subdirectory (glfw-3.3)

include_directories(
	glfw-3.3/include/
	glew-1.13.0/include/
)


### GLEW ###

set(GLEW_SOURCE	glew-1.13.0/src/glew.c)

set(GLEW_INCLUDE
	glew-1.13.0/include/GL/glew.h
	glew-1.13.0/include/GL/glxew.h
	glew-1.13.0/include/GL/wglew.h
)


add_library(GLEW STATIC
	${GLEW_SOURCE}
	${GLEW_INCLUDE}
)

target_link_libraries(GLEW
	${OPENGL_LIBRARY}
	${EXTRA_LIBS}
)

