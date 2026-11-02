cmake_minimum_required(VERSION 3.10)

project(17_3_queue)

set(CMAKE_CXX_STANDARD 17)

add_library(ErrorHandler ./lib/include/ErrorHandler.hpp ./lib/ErrorHandler.cpp)
target_include_directories(ErrorHandler PUBLIC ./lib/include/)

add_executable(main ./src/main.cpp)
target_link_libraries(main ErrorHandler)