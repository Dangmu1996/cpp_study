cmake_minimum_required(VERSION 3.10)

project(condition_variable)

set(CMAKE_CXX_STANDARD 17)

add_executable(promise_n_future ./src/promoise_n_future.cpp)
add_executable(packaged_task ./src/packaged_task.cpp)
add_executable(async ./src/async.cpp)
add_executable(exception ./src/exception.cpp)
add_executable(shared_future ./src/shared_future.cpp)