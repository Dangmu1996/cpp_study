cmake_minimum_required(VERSION 3.10)
project(eigen_setting)

set(CMAKE_CXX_STANDARD 17)

find_package(Eigen3 REQUIRED)

include_directories(
    ${Eigen3_INCLUDE_DIRS}
)

add_executable(main ./src/main.cc)
target_link_libraries(main ${Eigen3_LIBRARIES})
