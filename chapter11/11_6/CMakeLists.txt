cmake_minimum_required(VERSION 3.10)
project(chapter11_6)

set(CMAKE_CXX_STANDARD 17)

add_executable(complex_literal ./src/complex_literal.cpp)
add_executable(string_literal ./src/string_literal.cpp)
add_executable(raw_mode_complex ./src/raw_mode_complex.cpp)