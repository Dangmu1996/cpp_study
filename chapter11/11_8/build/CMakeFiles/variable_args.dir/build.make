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
CMAKE_SOURCE_DIR = /home/dangmu1996/cpp_study/11_8

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dangmu1996/cpp_study/11_8/build

# Include any dependencies generated for this target.
include CMakeFiles/variable_args.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/variable_args.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/variable_args.dir/flags.make

CMakeFiles/variable_args.dir/src/variable_args.cc.o: CMakeFiles/variable_args.dir/flags.make
CMakeFiles/variable_args.dir/src/variable_args.cc.o: ../src/variable_args.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dangmu1996/cpp_study/11_8/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/variable_args.dir/src/variable_args.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/variable_args.dir/src/variable_args.cc.o -c /home/dangmu1996/cpp_study/11_8/src/variable_args.cc

CMakeFiles/variable_args.dir/src/variable_args.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/variable_args.dir/src/variable_args.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dangmu1996/cpp_study/11_8/src/variable_args.cc > CMakeFiles/variable_args.dir/src/variable_args.cc.i

CMakeFiles/variable_args.dir/src/variable_args.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/variable_args.dir/src/variable_args.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dangmu1996/cpp_study/11_8/src/variable_args.cc -o CMakeFiles/variable_args.dir/src/variable_args.cc.s

# Object files for target variable_args
variable_args_OBJECTS = \
"CMakeFiles/variable_args.dir/src/variable_args.cc.o"

# External object files for target variable_args
variable_args_EXTERNAL_OBJECTS =

variable_args: CMakeFiles/variable_args.dir/src/variable_args.cc.o
variable_args: CMakeFiles/variable_args.dir/build.make
variable_args: CMakeFiles/variable_args.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dangmu1996/cpp_study/11_8/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable variable_args"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/variable_args.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/variable_args.dir/build: variable_args

.PHONY : CMakeFiles/variable_args.dir/build

CMakeFiles/variable_args.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/variable_args.dir/cmake_clean.cmake
.PHONY : CMakeFiles/variable_args.dir/clean

CMakeFiles/variable_args.dir/depend:
	cd /home/dangmu1996/cpp_study/11_8/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dangmu1996/cpp_study/11_8 /home/dangmu1996/cpp_study/11_8 /home/dangmu1996/cpp_study/11_8/build /home/dangmu1996/cpp_study/11_8/build /home/dangmu1996/cpp_study/11_8/build/CMakeFiles/variable_args.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/variable_args.dir/depend
