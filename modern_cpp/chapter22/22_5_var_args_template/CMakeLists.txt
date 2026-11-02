cmake_minimum_required(VERSION 3.10)

project(22_5_var_args_template)

set(CMAKE_CXX_STANDARD 17)

include_directories(./include/)

add_executable(various ./src/various.cpp)
add_executable(mixin ./src/mixin.cpp ./include/Mixin.hpp)