cmake_minimum_required(VERSION 3.10)
project(exception_and_variety)

set(CMAKE_CXX_STANDARD 17)

add_library(FileError ./lib/include/FileError.hpp ./lib/FileError.cpp)
add_library(FileOpenError ./lib/include/FileOpenError.hpp ./lib/FileOpenError.cpp)
add_library(FileReadError ./lib/include/FileReadError.hpp ./lib/FileReadError.cpp)

target_include_directories(FileError PUBLIC ./lib/include/)
target_include_directories(FileOpenError PUBLIC ./lib/include/)
target_include_directories(FileReadError PUBLIC ./lib/include/)

add_Executable(main ./src/main.cc)
target_link_libraries(main FileError FileOpenError FileReadError)


add_executable(standard_exception_class ./src/standard_exception_class.cc)
add_executable(suitable_exception ./src/suitable_exception.cc)
add_executable(nested_exception ./src/nested_exception.cc)