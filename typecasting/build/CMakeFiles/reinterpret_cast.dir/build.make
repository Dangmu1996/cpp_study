# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/dangmu1996/cpp_study/typecasting

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dangmu1996/cpp_study/typecasting/build

# Include any dependencies generated for this target.
include CMakeFiles/reinterpret_cast.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/reinterpret_cast.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/reinterpret_cast.dir/flags.make

CMakeFiles/reinterpret_cast.dir/src/reinterpret_cast.cc.o: CMakeFiles/reinterpret_cast.dir/flags.make
CMakeFiles/reinterpret_cast.dir/src/reinterpret_cast.cc.o: ../src/reinterpret_cast.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dangmu1996/cpp_study/typecasting/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/reinterpret_cast.dir/src/reinterpret_cast.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/reinterpret_cast.dir/src/reinterpret_cast.cc.o -c /home/dangmu1996/cpp_study/typecasting/src/reinterpret_cast.cc

CMakeFiles/reinterpret_cast.dir/src/reinterpret_cast.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/reinterpret_cast.dir/src/reinterpret_cast.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dangmu1996/cpp_study/typecasting/src/reinterpret_cast.cc > CMakeFiles/reinterpret_cast.dir/src/reinterpret_cast.cc.i

CMakeFiles/reinterpret_cast.dir/src/reinterpret_cast.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/reinterpret_cast.dir/src/reinterpret_cast.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dangmu1996/cpp_study/typecasting/src/reinterpret_cast.cc -o CMakeFiles/reinterpret_cast.dir/src/reinterpret_cast.cc.s

# Object files for target reinterpret_cast
reinterpret_cast_OBJECTS = \
"CMakeFiles/reinterpret_cast.dir/src/reinterpret_cast.cc.o"

# External object files for target reinterpret_cast
reinterpret_cast_EXTERNAL_OBJECTS =

reinterpret_cast: CMakeFiles/reinterpret_cast.dir/src/reinterpret_cast.cc.o
reinterpret_cast: CMakeFiles/reinterpret_cast.dir/build.make
reinterpret_cast: CMakeFiles/reinterpret_cast.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dangmu1996/cpp_study/typecasting/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable reinterpret_cast"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/reinterpret_cast.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/reinterpret_cast.dir/build: reinterpret_cast

.PHONY : CMakeFiles/reinterpret_cast.dir/build

CMakeFiles/reinterpret_cast.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/reinterpret_cast.dir/cmake_clean.cmake
.PHONY : CMakeFiles/reinterpret_cast.dir/clean

CMakeFiles/reinterpret_cast.dir/depend:
	cd /home/dangmu1996/cpp_study/typecasting/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dangmu1996/cpp_study/typecasting /home/dangmu1996/cpp_study/typecasting /home/dangmu1996/cpp_study/typecasting/build /home/dangmu1996/cpp_study/typecasting/build /home/dangmu1996/cpp_study/typecasting/build/CMakeFiles/reinterpret_cast.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/reinterpret_cast.dir/depend
