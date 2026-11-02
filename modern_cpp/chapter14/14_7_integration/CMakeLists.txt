cmake_minimum_required(VERSION 3.10)
project(integration)

set(CMAKE_CXX_STANDARD 17)

add_library(GameBoard ./lib/GameBoard.cpp ./lib/include/GameBoard.hpp)

target_include_directories(GameBoard PUBLIC ./lib/include/)

add_executable(main ./src/main.cc)
target_link_libraries(main GameBoard)