cmake_minimum_required(VERSION 3.10)

project(chater_1)

include_directories(./include)

add_library(employee ./include/employee.h ./include/employee.cpp)
add_library(database ./include/database.h ./include/database.cpp)

add_executable(hello_world ./src/hello_world.cpp ./include/namespace.h)
add_executable(variable ./src/variable.cpp)
add_executable(struct ./src/struct.cpp ./include/employeestruct.h)
add_executable(function ./src/function.cpp)
add_executable(array ./src/array.cpp)
add_executable(binding ./src/binding.cpp)
add_executable(initializer_list ./src/initialize_list.cpp)
add_executable(pointer ./src/pointer.cpp)
add_executable(const ./src/const.cpp)
add_executable(exception ./src/exception.cpp)
add_executable(employeetest ./src/employeetest.cpp)
target_link_libraries(employeetest employee)

add_executable(databasetest ./src/databasetest.cpp)
target_link_libraries(databasetest employee database)