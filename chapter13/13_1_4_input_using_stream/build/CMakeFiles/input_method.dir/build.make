# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/dangmu/cpp_study/chapter13/13_1_4_input_using_stream

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dangmu/cpp_study/chapter13/13_1_4_input_using_stream/build

# Include any dependencies generated for this target.
include CMakeFiles/input_method.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/input_method.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/input_method.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/input_method.dir/flags.make

CMakeFiles/input_method.dir/src/input_method.cc.o: CMakeFiles/input_method.dir/flags.make
CMakeFiles/input_method.dir/src/input_method.cc.o: ../src/input_method.cc
CMakeFiles/input_method.dir/src/input_method.cc.o: CMakeFiles/input_method.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dangmu/cpp_study/chapter13/13_1_4_input_using_stream/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/input_method.dir/src/input_method.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/input_method.dir/src/input_method.cc.o -MF CMakeFiles/input_method.dir/src/input_method.cc.o.d -o CMakeFiles/input_method.dir/src/input_method.cc.o -c /home/dangmu/cpp_study/chapter13/13_1_4_input_using_stream/src/input_method.cc

CMakeFiles/input_method.dir/src/input_method.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/input_method.dir/src/input_method.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dangmu/cpp_study/chapter13/13_1_4_input_using_stream/src/input_method.cc > CMakeFiles/input_method.dir/src/input_method.cc.i

CMakeFiles/input_method.dir/src/input_method.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/input_method.dir/src/input_method.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dangmu/cpp_study/chapter13/13_1_4_input_using_stream/src/input_method.cc -o CMakeFiles/input_method.dir/src/input_method.cc.s

# Object files for target input_method
input_method_OBJECTS = \
"CMakeFiles/input_method.dir/src/input_method.cc.o"

# External object files for target input_method
input_method_EXTERNAL_OBJECTS =

input_method: CMakeFiles/input_method.dir/src/input_method.cc.o
input_method: CMakeFiles/input_method.dir/build.make
input_method: CMakeFiles/input_method.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dangmu/cpp_study/chapter13/13_1_4_input_using_stream/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable input_method"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/input_method.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/input_method.dir/build: input_method
.PHONY : CMakeFiles/input_method.dir/build

CMakeFiles/input_method.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/input_method.dir/cmake_clean.cmake
.PHONY : CMakeFiles/input_method.dir/clean

CMakeFiles/input_method.dir/depend:
	cd /home/dangmu/cpp_study/chapter13/13_1_4_input_using_stream/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dangmu/cpp_study/chapter13/13_1_4_input_using_stream /home/dangmu/cpp_study/chapter13/13_1_4_input_using_stream /home/dangmu/cpp_study/chapter13/13_1_4_input_using_stream/build /home/dangmu/cpp_study/chapter13/13_1_4_input_using_stream/build /home/dangmu/cpp_study/chapter13/13_1_4_input_using_stream/build/CMakeFiles/input_method.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/input_method.dir/depend
