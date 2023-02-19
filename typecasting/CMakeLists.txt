cmake_minimum_required(VERSION 3.10)
project(tpyecasting)

set(CMAKE_CXX_STANDARD 17)

add_library(Employee ./lib/Employee.cpp ./lib/include/Employee.hpp)
target_include_directories(Employee PUBLIC ./lib/include/)

add_executable(method_member_allias ./src/method_member_allias.cpp)
target_link_libraries(method_member_allias Employee)

add_executable(type_allias ./src/tpye_allias.cc)
add_executable(funter_tpye_allias ./src/funter_tpye_allias.cc)