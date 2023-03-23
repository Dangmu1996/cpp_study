cmake_minimum_required(VERSION 3.10)
project(scope_n_attribute)

set(CMAKE_CXX_STANDARD 17)

add_executable(scope ./src/scope.cc)
add_executable(nonreturn ./src/nonreturn.cc)
#add_executable(deprecated ./src/deprecated.cc)
#add_executable(nondiscard ./src/nondiscard.cc)
add_executable(mybe_unused ./src/maybe_unused.cc)