cmake_minimum_required(VERSION 3.10)
project(18_3_lambda_expression)

set(CMAKE_CXX_STANDARD 17)

add_executable(basiclambda ./src/basiclambda.cpp)
add_executable(generic_lambda_expression ./src/generic_lambda_expression.cpp)
add_executable(lambda_capture_expression ./src/lambda_capture_expression.cpp)
add_executable(lambda_expression_return ./src/lambda_expression_return.cpp)

add_executable(std_library_algorithm_ex ./src/std_library_algorithm_ex.cpp)
add_executable(std_library_algorithm_ex2 ./src/std_library_algorithm_ex2.cpp)
add_executable(std_library_algorithm_ex3 ./src/std_library_algorithm_ex3.cpp)
