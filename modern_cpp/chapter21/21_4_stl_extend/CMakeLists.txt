cmake_minimum_required(VERSION 3.10)
project(21_4_stl_extend)

set(CMAKE_CXX_STANDARD 17)


include_directories(lib/include)
include_directories(lib)

add_executable(make_find_all ./src/make_find_all.cpp)
add_executable(make_iterator_traits ./src/make_iterator_traits.cpp)
# add_executable(main ./src/main.cpp)
# add_executable(hash_map_iterator ./src/hash_map_iterator.cpp)
add_executable(test_hash_map ./src/test_hash_map.cpp)