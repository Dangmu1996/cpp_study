cmake_minimum_required(VERSION 3.10)
project(function_call_operator_overloading)

add_library(FunctionObject ./lib/include/FunctionObject.hpp ./lib/FunctionObject.cpp)
target_include_directories(FunctionObject PUBLIC ./lib/include/)

add_executable(main ./src/main.cc)
target_link_libraries(main FunctionObject)

