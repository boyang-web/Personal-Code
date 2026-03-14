cmake_minimum_required(VERSION 3.10)
project(Add)
set(CMAKE_CXX_STANDARD 17)
add_executable(Add
src/main.cpp
src/add.cpp
)
target_include_directories(Add PRIVATE include)