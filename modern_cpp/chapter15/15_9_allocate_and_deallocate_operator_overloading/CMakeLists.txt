cmake_minimum_required(VERSION 3.10)
project(memory_alloc_operator_overloading)

set(CMAKE_CXX_STANDARD 17)

add_library(MemoryDemo ./lib/include/MemoryDemo.hpp ./lib/MemoryDemo.cpp)
target_include_directories(MemoryDemo PUBLIC ./lib/include/)

add_executable(main ./src/main.cc)
target_link_libraries(main MemoryDemo)