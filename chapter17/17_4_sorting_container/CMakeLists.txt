cmake_minimum_required(VERSION 3.10)
project(17_4_sorting_container)

set(CMAKE_CXX_STANDARD 17)

add_library(Bank ./lib/include/Bank.hpp ./lib/Bank.cpp)
add_library(BuddyList ./lib/include/BuddyLists.hpp ./lib/BuddyLists.cpp)

target_include_directories(Bank PUBLIC ./lib/include/)
target_include_directories(BuddyList PUBLIC ./lib/include/)

add_executable(pair_utill_class ./src/pair_utill_class.cpp)
add_executable(map_utill ./src/map_utill.cpp)

add_executable(map_main ./src/map_main.cpp)
target_link_libraries(map_main Bank)

add_executable(multimap_main ./src/multimap_main.cpp)
target_link_libraries(multimap_main BuddyList)