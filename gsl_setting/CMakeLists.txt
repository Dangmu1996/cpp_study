cmake_minimum_required(VERSION 3.10)
project(gsl_setting)

set(CMAKE_CXX_STANDARD 17)

find_package(GSL REQUIRED)

add_executable(gsl_example ./src/gsl_example.cpp)
target_link_libraries(gsl_example ${GSL_LIBRARIES})

add_executable(polynomials ./src/polynomials.cpp)
target_link_libraries(polynomials ${GSL_LIBRARIES})