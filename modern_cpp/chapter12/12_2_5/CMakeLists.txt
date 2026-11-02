cmake_minimum_required(VERSION 3.10)
project(nontype_template)

set(CMAKE_CXX_STANDARD 17)

add_Executable(main ./src/main.cpp ./lib/include/Grid.hpp)