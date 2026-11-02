cmake_minimum_required(VERSION 3.10)
project(template_heritage)

set(CMAKE_CXX_STANDARD 17)

add_Executable(main ./src/main.cpp ./lib/include/Grid.hpp ./lib/include/GameBoard.hpp)