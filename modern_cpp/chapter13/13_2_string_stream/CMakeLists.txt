cmake_minimum_required(VERSION 3.10)
project(string_stream)

set(CMAKE_CXX_STANDARD 17)

add_library(Muffin ./lib/include/Muffin.hpp ./lib/Muffin.cpp)
target_include_directories(Muffin PUBLIC ./lib/include/)

add_executable(ostream_example ./src/ostream_example.cc)

add_executable(main ./src/main.cc)
target_link_libraries(main Muffin)