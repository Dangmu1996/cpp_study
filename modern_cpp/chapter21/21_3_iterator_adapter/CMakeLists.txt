cmake_minimum_required(VERSION 3.10)

project(21_3_iterator_adapter)

set(CMAKE_CXX_STANDARD 17)

add_executable(reverse_iterator ./src/reverse_iterator.cpp)
add_executable(additional_iterator ./src/additional_iterator.cpp)
add_executable(additional_iterator_two ./src/additional_iterator_two.cpp)
add_executable(moveable_iterator ./src/moveable_iterator.cpp)