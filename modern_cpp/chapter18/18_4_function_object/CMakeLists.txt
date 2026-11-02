cmake_minimum_required(VERSION 3.10)
project(function_object)

set(CMAKE_CXX_STANDARD 17)

add_executable(arithmetic_function_pointer ./src/arithmetic_function_pointer.cpp)
add_executable(compare_function_pointer ./src/compare_function_pointer.cpp)
add_executable(logical_function_pointer ./src/logical_function_pointer.cpp)
add_executable(adapter_function_pointer ./src/adapter_function_pointer.cpp)
add_executable(negator_function_object ./src/negator_function_object.cpp)
add_executable(custom_function_object ./src/custom_function_object.cpp)
