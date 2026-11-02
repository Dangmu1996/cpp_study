cmake_minimum_required(VERSION 3.10)

project(chapter_20_3_random)

set(CMAKE_CXX_STANDARD 17)

add_executable(random ./src/random.cpp)
add_executable(random_2 ./src/random_2.cpp)
add_executable(uniform_integer_distribution ./src/uniform_integer_distribution.cpp)
