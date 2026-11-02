cmake_minimum_required(VERSION 3.10)
project(profiling)

# Include directories for the main target
add_executable(main ./src/main.cc)
target_include_directories(main PRIVATE ./lib/include/)

# Specify source files for the main target

# set(FIRSTNAME_DB_SOURCES ./lib/include/FirstNameDB.hpp ./lib/FirstNameDB.cpp)
set(SECONDNAME_DB_SOURCES ./lib/include/SecondNameDB.hpp ./lib/SecondNameDB.cpp)

# target_sources(main PRIVATE ${FIRSTNAME_DB_SOURCES})
target_sources(main PRIVATE ${SECONDNAME_DB_SOURCES})

# Set C++ standard explicitly
set_target_properties(main PROPERTIES
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED ON
)

# Add -pg for profiling (both compiling and linking)
target_compile_options(main PRIVATE -pg)
target_link_options(main PRIVATE -pg)
