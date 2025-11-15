cmake_minimum_required(VERSION 3.10)

project(chater_1)

include_directories(./include)

add_executable(hello_world ./src/hello_world.cpp ./include/namespace.h)
add_executable(variable ./src/variable.cpp)
add_executable(struct ./src/struct.cpp ./include/employeestruct.h)
add_executable(function ./src/function.cpp)
add_executable(array ./src/array.cpp)
add_executable(binding ./src/binding.cpp)
add_executable(initializer_list ./src/initialize_list.cpp)