cmake_minimum_required(VERSION 3.10)
project(index_operator_overloading)

add_library(Array ./lib/include/Array.hpp ./lib/Array.cpp)
target_include_directories(Array PUBLIC ./lib/include/)

add_executable(main_two ./src/main_two.cc ./src/AssociativeArraay.hpp)

add_executable(main ./src/main.cc)
target_link_libraries(main Array)