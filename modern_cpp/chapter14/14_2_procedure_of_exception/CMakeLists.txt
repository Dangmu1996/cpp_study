cmake_minimum_required(VERSION 3.10)
project(prcedure_exception)

set(CMAKE_CXX_STANDARD 17)

add_executable(main ./src/main.cc)
add_executable(try_catch_basic ./src/try_catch_basic.cc)
add_executable(multi_except ./src/multi_except.cc)
add_executable(not_same_except ./src/not_same_except.cc)
add_executable(every_exception ./src/every_exception.cc)
add_executable(terminate ./src/terminate.cc)