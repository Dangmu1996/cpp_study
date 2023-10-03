cmake_minimum_required(VERSION 3.10)

project(17_2_sequential_container)

set(CMAKE_CXX_STANDARD 17)

add_executable(static_size_vector ./src/static_size_vector.cc)
add_executable(dynamic_size_vector ./src/dynamic_size_vector.cc)
add_executable(specific_function_vector ./src/specific_function_vector.cc)
add_executable(copy_substitute_vector ./src/copy_substitute_vector.cc)
add_executable(compare_vector ./src/compare_vector.cc)
add_executable(iterator_vector ./src/iterator_vector.cc)