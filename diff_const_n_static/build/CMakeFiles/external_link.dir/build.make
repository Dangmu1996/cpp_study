# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = /home/wego/.local/lib/python2.7/site-packages/cmake/data/bin/cmake

# The command to remove a file.
RM = /home/wego/.local/lib/python2.7/site-packages/cmake/data/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/wego/cpp_study/chapter11/diff_const_n_static

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/wego/cpp_study/chapter11/diff_const_n_static/build

# Include any dependencies generated for this target.
include CMakeFiles/external_link.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/external_link.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/external_link.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/external_link.dir/flags.make

CMakeFiles/external_link.dir/src/external_link.cpp.o: CMakeFiles/external_link.dir/flags.make
CMakeFiles/external_link.dir/src/external_link.cpp.o: ../src/external_link.cpp
CMakeFiles/external_link.dir/src/external_link.cpp.o: CMakeFiles/external_link.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wego/cpp_study/chapter11/diff_const_n_static/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/external_link.dir/src/external_link.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/external_link.dir/src/external_link.cpp.o -MF CMakeFiles/external_link.dir/src/external_link.cpp.o.d -o CMakeFiles/external_link.dir/src/external_link.cpp.o -c /home/wego/cpp_study/chapter11/diff_const_n_static/src/external_link.cpp

CMakeFiles/external_link.dir/src/external_link.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/external_link.dir/src/external_link.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wego/cpp_study/chapter11/diff_const_n_static/src/external_link.cpp > CMakeFiles/external_link.dir/src/external_link.cpp.i

CMakeFiles/external_link.dir/src/external_link.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/external_link.dir/src/external_link.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wego/cpp_study/chapter11/diff_const_n_static/src/external_link.cpp -o CMakeFiles/external_link.dir/src/external_link.cpp.s

# Object files for target external_link
external_link_OBJECTS = \
"CMakeFiles/external_link.dir/src/external_link.cpp.o"

# External object files for target external_link
external_link_EXTERNAL_OBJECTS =

external_link: CMakeFiles/external_link.dir/src/external_link.cpp.o
external_link: CMakeFiles/external_link.dir/build.make
external_link: liblinker.a
external_link: CMakeFiles/external_link.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/wego/cpp_study/chapter11/diff_const_n_static/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable external_link"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/external_link.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/external_link.dir/build: external_link
.PHONY : CMakeFiles/external_link.dir/build

CMakeFiles/external_link.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/external_link.dir/cmake_clean.cmake
.PHONY : CMakeFiles/external_link.dir/clean

CMakeFiles/external_link.dir/depend:
	cd /home/wego/cpp_study/chapter11/diff_const_n_static/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wego/cpp_study/chapter11/diff_const_n_static /home/wego/cpp_study/chapter11/diff_const_n_static /home/wego/cpp_study/chapter11/diff_const_n_static/build /home/wego/cpp_study/chapter11/diff_const_n_static/build /home/wego/cpp_study/chapter11/diff_const_n_static/build/CMakeFiles/external_link.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/external_link.dir/depend
