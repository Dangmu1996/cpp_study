cmake_minimum_required(VERSION 3.10)
project(forward_declaration)

add_library(logger ./lib/Logger.cpp ./lib/include/Logger.hpp)
add_library(Preference ./lib/Preference.cpp ./lib/include/Preference.hpp)
target_include_directories(logger PUBLIC ./lib/include/)
target_include_directories(Preference PUBLIC ./lib/include/)

add_executable(main ./src/main.cpp)
target_link_libraries(main logger Preference)
