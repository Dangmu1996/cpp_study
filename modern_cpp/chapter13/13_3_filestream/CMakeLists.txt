cmake_minimum_required(VERSION 3.10)
project(filestream)

set(CMAKE_CXX_STANDARD 17)

add_executable(main ./src/main.cc)

add_executable(seek_put ./src/seek_put.cc)

add_executable(tie_stream ./src/tie_stream.cc)
