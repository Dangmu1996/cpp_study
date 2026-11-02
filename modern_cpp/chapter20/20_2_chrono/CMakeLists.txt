cmake_minimum_required(VERSION 3.10)

project(20_2_chrono)

set(CMAKE_CXX_STANDARD 17)

add_executable(duration ./src/duration.cpp)
add_executable(clock ./src/clock.cpp)
add_executable(time_point ./src/time_point.cpp)