cmake_minimum_required(VERSION 3.10)

project(22_2_class_template_partial_specialize)

set(CMAKE_CXX_STANDARD 17)

include_directories(./include/)

add_executable(main ./src/main.cpp ./include/Grid.hpp ./include/string_grid.hpp ./include/orig_grid.hpp ./include/ptr_grid.hpp)