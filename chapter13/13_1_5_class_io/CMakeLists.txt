cmake_minimum_required(VERSION 3.10)
project(class_io)

set(CMAKE_CXX_STANDARD 17)

add_library(Muffin ./lib/include/Muffin.hpp ./lib/Muffin.cpp)
target_include_directories(Muffin PUBLIC ./lib/include/)

add_Executable(main ./src/main.cc)
target_link_libraries(main Muffin)