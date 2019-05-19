# OpenGL_Demos
学习OpenGL的一些Demo

主要根据[opengl-tutorial](http://www.opengl-tutorial.org)上面的教程改写的的。

# 编译
使用CMake构建系统，理论上是可以跨平台的，但是只在Visual Studio和MinGW编译环境下测试过。
Windows平台下编译：
```
mkdir _build
cd _build
# 生成Makefiles
cmake -G "MinGW Makefiles" ..
mingw32-make
```

