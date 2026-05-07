cmake_minimum_required(VERSION 3.10)
project(ports_with_generic_types)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(behaviortree_cpp REQUIRED)

add_executable(ports_with_generic_types ./src/main.cpp)
target_include_directories(ports_with_generic_types PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(ports_with_generic_types PRIVATE
    behaviortree_cpp
)