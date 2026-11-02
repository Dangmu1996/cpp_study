cmake_minimum_required(VERSION 3.10)

project(22_4_template_recursive)

set(CMAKE_CXX_STANDARD 17)

include_directories(./include/)

add_executable(main ./src/main.cpp ./include/Grid.hpp ./include/MultiGrid.hpp)