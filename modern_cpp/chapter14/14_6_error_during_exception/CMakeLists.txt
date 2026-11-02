cmake_minimum_required(VERSION 3.10)
project(error_exception)

set(CMAKE_CXX_STANDARD 17)

add_library(Matrix ./lib/include/Matrix.hpp ./lib/Matrix.cpp)
add_library(Element ./lib/include/Element.hpp ./lib/Element.cpp)
target_include_directories(Matrix PUBLIC ./lib/include/)
target_include_directories(Element PUBLIC ./lib/include/)

add_executable(memory_error ./src/memory_error.cc)
add_executable(new_handler ./src/new_handler.cc)

add_executable(initializer_exception ./src/initializer_exception.cc)
target_link_libraries(initializer_exception Matrix Element)

add_executable(try_black ./src/try_block.cc)