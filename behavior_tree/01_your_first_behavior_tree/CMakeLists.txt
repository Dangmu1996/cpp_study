cmake_minimum_required(VERSION 3.16)
project(fist_behavior_tree)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(behaviortree_cpp REQUIRED)

add_executable(first_bt
    src/main.cpp
)

target_include_directories(first_bt PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(first_bt PRIVATE
    behaviortree_cpp
)