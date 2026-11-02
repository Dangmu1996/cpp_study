cmake_minimum_required(VERSION 3.10)
project(19_1_localization)

set(CMAKE_CXX_STANDARD 17)

add_executable(wide_string ./src/wide_string.cpp)
add_executable(code_point ./src/code_point.cpp)
add_executable(locale_and_passit ./src/locale_and_passit.cpp)