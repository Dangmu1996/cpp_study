cmake_minimum_required(VERSION 3.10)
project(class_template)

set(CMAKE_CXX_STANDARD 17)

add_library(GamePiece ./lib/include/GamePiece.hpp ./lib/ChessPiece.cpp)
add_library(GameBoard ./lib/include/GameBoard.hpp ./lib/GameBoard.cpp)
add_library(Grid ./lib/include/Grid.hpp ./lib/Grid.cpp)


target_include_directories(GamePiece PUBLIC ./lib/include/)
target_include_directories(GameBoard PUBLIC ./lib/include/)
target_include_directories(Grid PUBLIC ./lib/include/)


add_Executable(main ./src/main.cpp ./lib/include/Grid.hpp)
target_link_libraries(main GamePiece GameBoard Grid)