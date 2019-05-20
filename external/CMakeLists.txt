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
	glew-2.1.0/include/
)


### GLEW ###
set(GLEW_SOURCE	glew-2.1.0/src/glew.c)

set(GLEW_INCLUDE
	glew-2.1.0/include/GL/glew.h
	glew-2.1.0/include/GL/glxew.h
	glew-2.1.0/include/GL/wglew.h
)


add_library(GLEW STATIC
	${GLEW_SOURCE}
	${GLEW_INCLUDE}
)

target_link_libraries(GLEW
	${OPENGL_LIBRARY}
	${EXTRA_LIBS}
)


### ASSIMP ###
set(BUILD_STATIC_LIB ON)
# Gtest must have pthread disabled with mingw32
#https://github.com/assimp/assimp/issues/433
# 直接Disable测试
set(ASSIMP_BUILD_TESTS OFF)
add_subdirectory (assimp-4.1.0)

# Compile built-in, modified version of Zlib
#include(CheckIncludeFile)
#include(CheckTypeSize)
#include(CheckFunctionExists)
#add_subdirectory( assimp-4.1.0/contrib/zlib )
#
## Compile without Boost
#include_directories( assimp-4.1.0/code/BoostWorkaround )
#add_definitions( -DASSIMP_BUILD_BOOST_WORKAROUND )
#
#set(ASSIMP_BUILD_GLTF_IMPORTER OFF)
#set(ASSIMP_LIB_INSTALL_DIR "lib")
#set(Z_LIB_INSTALL_DIR "lib")
#
#
## Compile AssImp
#set( LIB_INSTALL_DIR "lib")
##set(LIBASSIMP_COMPONENT libassimp3.0-r1270-OGLtuts)
##set(ZLIB_LIBRARIES zlib)
#set(BUILD_STATIC_LIB ON)
##set(ZLIB_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/zlib)
#add_subdirectory( assimp-4.1.0/code )