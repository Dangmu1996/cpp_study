cmake_minimum_required(VERSION 3.10)

project(atomic_operation_library)

set(CMAKE_CXX_STANDARD 17)

add_executable(lock_free ./src/lock_free.cpp)
add_executable(atomic_example ./src/atomic_example.cc)
add_executable(atomic_operation ./src/atomic_operation.cc)
add_executable(once_flag ./src/once_flag.cc)
add_executable(mutex_1 ./src/mutex_1.cc)
add_executable(mutex_2 ./src/mutex_2.cc)
add_executable(mutex_3 ./src/mutex_3.cc)