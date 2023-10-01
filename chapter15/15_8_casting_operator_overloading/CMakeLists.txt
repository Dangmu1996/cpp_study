cmake_minimum_required(VERSION 3.10)
project(casting_operator_overlaoding)

set(CMAKE_CXX_STANDARD 17)

add_library(SpreadsheetCell ./lib/include/SpreadsheetCell.hpp ./lib/SpreadsheetCell.cpp)
target_include_directories(SpreadsheetCell PUBLIC ./lib/include/)

add_executable(main ./src/main.cc ./src/Pointer.hpp)
target_link_libraries(main SpreadsheetCell)