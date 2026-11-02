cmake_minimum_required(VERSION 3.10)
project(function_template)

set(CMAKE_CXX_STANDARD 17)

add_library(SpreadsheetCell ./lib/include/SpreadsheetCell.hpp ./lib/SpreadsheetCell.cpp)
target_include_directories(SpreadsheetCell PUBLIC ./lib/include/)

add_Executable(main ./src/main.cc)
target_link_libraries(main SpreadsheetCell)