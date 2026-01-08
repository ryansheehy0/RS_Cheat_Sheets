[Home](../README.md#c)

# CMake
A cross platform build system used to generate other build systems, like a makefile.

CMakeLists.txt

```C++
cmake_minimum_required(VERSION 3.20.0)
project(ProjectName)
add_executable(CompiledName main.cpp other.cpp)
```

- Automatically detect the compiler and generates the build system into a folder.
	- cmake -B ./folder
	- cmake --build ./folder    To build
	- The executable is in the build folder