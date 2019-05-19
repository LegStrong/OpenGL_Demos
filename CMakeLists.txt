
cmake_minimum_required (VERSION 2.6)
project (OpenGL_Demos)

# 依赖OpenGL
find_package(OpenGL REQUIRED)


# 添加第三方子目录
add_subdirectory (external)


# 头文件目录
include_directories(
	external/glfw-3.3/include/
	external/glm-0.9.7.1/
	external/glew-1.13.0/include/
    external/glm/
    common/
	.
)

# 所有库
set(ALL_LIBS
	${OPENGL_LIBRARY}
	glfw
	GLEW
)

# 预编译宏
add_definitions(
	-DTW_STATIC
	-DTW_NO_LIB_PRAGMA
	-DTW_NO_DIRECT3D
	-DGLEW_STATIC
	-D_CRT_SECURE_NO_WARNINGS
)

# 添加可执行文件
add_executable (OpenGL_Demos
    main.cpp
    demo.cpp
    democube.cpp

    common/shader.cpp
)

# 添加依赖库
target_link_libraries(OpenGL_Demos
	${ALL_LIBS}
	GLEW
)
