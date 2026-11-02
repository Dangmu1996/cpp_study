cmake_minimum_required(VERSION 3.10)
project(19_2_regrex)

set(CMAKE_CXX_STANDARD 17)

add_executable(regrex_match ./src/regrex_match.cpp)
add_executable(regex_search ./src/regex_search.cpp)
add_executable(regex_iterator ./src/regex_iterator.cpp)
add_executable(regex_token_iterator ./src/regex_token_iterator.cpp)
add_executable(regex_token_iterator2 ./src/regex_token_iterator2.cpp)
add_executable(regex_token_iterator3 ./src/regex_token_iterator3.cpp)
add_executable(regex_replace ./src/regex_replace.cpp)
add_executable(regex_replace2 ./src/regex_replace2.cpp)
add_executable(regex_replace3 ./src/regex_replace3.cpp)