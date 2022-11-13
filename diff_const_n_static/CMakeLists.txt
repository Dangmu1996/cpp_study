cmake_minimum_required(VERSION 3.10)
project(chapter11)

set(CMAKE_CXX_STANDARD 17)

add_executable(const_ptr ./src/const_ptr.cpp)
add_executable(const_ref ./src/const_ref.cpp)

add_library(linker ./lib/linker.cpp ./lib/include/linker.h)
target_include_directories(linker PUBLIC ./lib/include/)

add_executable(external_link ./src/external_link.cpp)
target_link_libraries(external_link linker)