cmake_minimum_required(VERSION 3.10)
project(17_6_some_container)

set(CMAKE_CXX_STANDARD 17)

add_library(CableCompany ./lib/include/CableCompany.hpp ./lib/CableCompany.cpp)

target_include_directories(CableCompany PUBLIC ./lib/include)

add_executable(c_style_array ./src/c_style_array.cpp)
add_executable(string_ex ./src/string_ex.cpp)
add_executable(bitset_basic ./src/bitset_basic.cpp)

add_executable(bitset_main ./src/bitset_main.cpp)
target_link_libraries(bitset_main CableCompany)