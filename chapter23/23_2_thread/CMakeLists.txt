cmake_minimum_required(VERSION 3.10)

project(23_2_thread)

set(CMAKE_CXX_STANDARD 17)

add_executable(function_pointer_thread ./src/function_pointer_thread.cpp)
add_executable(class_thread ./src/class_thread.cpp)
add_executable(lambda_thread ./src/lambda_thread.cpp)
add_executable(class_method_thread ./src/class_method_thread.cpp)
add_executable(thread_exception ./src/thread_exception.cpp)