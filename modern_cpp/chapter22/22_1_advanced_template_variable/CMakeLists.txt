cmake_minimum_required(VERSION 3.10)

project(22_1_advanced_template_variable)

set(CMAKE_CXX_STANDARD 17)

include_directories(./include/)

add_library(SpreadsheetCell ./include/SpreadsheetCell.hpp ./src/SpreadsheetCell.cpp)

add_executable(main ./src/main.cpp ./include/Grid.hpp)
add_executable(main_2 ./src/main_2.cpp ./include/Grid_template_template.hpp)
add_executable(main_3 ./src/main_3.cpp ./include/Grid_defaultelement.hpp)
target_link_libraries(main_3 SpreadsheetCell)
