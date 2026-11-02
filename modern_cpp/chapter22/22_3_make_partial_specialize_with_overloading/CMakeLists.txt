cmake_minimum_required(VERSION 3.10)

project(22_3_make_partial_specialize_with_overloading)

set(CMAKE_CXX_STANDARD 17)

include_directories(./lib/include)

add_library(SpreadSheetCell ./lib/include/SpreadSheetCell.hpp ./lib/SpreadSheetCell.cpp)

add_executable(main ./src/main.cpp)
target_link_libraries(main SpreadSheetCell)