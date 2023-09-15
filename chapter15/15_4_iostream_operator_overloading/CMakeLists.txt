cmake_minimum_required(VERSION 3.10)

project(iostream_operator_overloading)

add_library(SpreadsheetCell ./lib/include/SpreadsheetCell.hpp ./lib/SpreadsheetCell.cpp)

target_include_directories(SpreadsheetCell PUBLIC ./lib/include/)

add_executable(main ./src/main.cc)
target_link_libraries(main SpreadsheetCell)