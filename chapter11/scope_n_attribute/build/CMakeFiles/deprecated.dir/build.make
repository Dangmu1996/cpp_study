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
CMAKE_SOURCE_DIR = /home/dangmu1996/cpp_study/scope_n_attribute

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dangmu1996/cpp_study/scope_n_attribute/build

# Include any dependencies generated for this target.
include CMakeFiles/deprecated.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/deprecated.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/deprecated.dir/flags.make

CMakeFiles/deprecated.dir/src/deprecated.cc.o: CMakeFiles/deprecated.dir/flags.make
CMakeFiles/deprecated.dir/src/deprecated.cc.o: ../src/deprecated.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dangmu1996/cpp_study/scope_n_attribute/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/deprecated.dir/src/deprecated.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/deprecated.dir/src/deprecated.cc.o -c /home/dangmu1996/cpp_study/scope_n_attribute/src/deprecated.cc

CMakeFiles/deprecated.dir/src/deprecated.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/deprecated.dir/src/deprecated.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dangmu1996/cpp_study/scope_n_attribute/src/deprecated.cc > CMakeFiles/deprecated.dir/src/deprecated.cc.i

CMakeFiles/deprecated.dir/src/deprecated.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/deprecated.dir/src/deprecated.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dangmu1996/cpp_study/scope_n_attribute/src/deprecated.cc -o CMakeFiles/deprecated.dir/src/deprecated.cc.s

# Object files for target deprecated
deprecated_OBJECTS = \
"CMakeFiles/deprecated.dir/src/deprecated.cc.o"

# External object files for target deprecated
deprecated_EXTERNAL_OBJECTS =

deprecated: CMakeFiles/deprecated.dir/src/deprecated.cc.o
deprecated: CMakeFiles/deprecated.dir/build.make
deprecated: CMakeFiles/deprecated.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dangmu1996/cpp_study/scope_n_attribute/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable deprecated"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/deprecated.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/deprecated.dir/build: deprecated

.PHONY : CMakeFiles/deprecated.dir/build

CMakeFiles/deprecated.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/deprecated.dir/cmake_clean.cmake
.PHONY : CMakeFiles/deprecated.dir/clean

CMakeFiles/deprecated.dir/depend:
	cd /home/dangmu1996/cpp_study/scope_n_attribute/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dangmu1996/cpp_study/scope_n_attribute /home/dangmu1996/cpp_study/scope_n_attribute /home/dangmu1996/cpp_study/scope_n_attribute/build /home/dangmu1996/cpp_study/scope_n_attribute/build /home/dangmu1996/cpp_study/scope_n_attribute/build/CMakeFiles/deprecated.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/deprecated.dir/depend
