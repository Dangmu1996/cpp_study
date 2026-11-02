cmake_minimum_required(VERSION 3.10)

project(Logger)

set(CMAKE_CXX_STANDARD 17)

include_directories(./lib/include/)

add_executable(main ./src/main.cpp ./lib/include/Logger.hpp ./lib/Logger.cpp)