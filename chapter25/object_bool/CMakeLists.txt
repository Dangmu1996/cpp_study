cmake_minimum_required(VERSION 3.10)

project(ObjectPool)

set(CMAKE_CXX_STANDARD 17)

include_directories(./src/)

add_executable(main ./src/main.cpp ./src/ObjectPool.hpp)