cmake_minimum_required(VERSION 3.10)
project(matplotcpp_setting)

set(CMAKE_CXX_STANDARD 17)

find_package(Python3 COMPONENTS Interpreter Development REQUIRED)
find_package(Python3 COMPONENTS NumPy)

include_directories(
    ${Python3_INCLUDE_DIRS}
    include
)

add_executable(main ./src/main.cc)
target_link_libraries(main ${Python3_LIBRARIES})

