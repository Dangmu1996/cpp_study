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
include CMakeFiles/linker.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/linker.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/linker.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/linker.dir/flags.make

CMakeFiles/linker.dir/lib/linker.cpp.o: CMakeFiles/linker.dir/flags.make
CMakeFiles/linker.dir/lib/linker.cpp.o: ../lib/linker.cpp
CMakeFiles/linker.dir/lib/linker.cpp.o: CMakeFiles/linker.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wego/cpp_study/chapter11/diff_const_n_static/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/linker.dir/lib/linker.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/linker.dir/lib/linker.cpp.o -MF CMakeFiles/linker.dir/lib/linker.cpp.o.d -o CMakeFiles/linker.dir/lib/linker.cpp.o -c /home/wego/cpp_study/chapter11/diff_const_n_static/lib/linker.cpp

CMakeFiles/linker.dir/lib/linker.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/linker.dir/lib/linker.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wego/cpp_study/chapter11/diff_const_n_static/lib/linker.cpp > CMakeFiles/linker.dir/lib/linker.cpp.i

CMakeFiles/linker.dir/lib/linker.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/linker.dir/lib/linker.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wego/cpp_study/chapter11/diff_const_n_static/lib/linker.cpp -o CMakeFiles/linker.dir/lib/linker.cpp.s

# Object files for target linker
linker_OBJECTS = \
"CMakeFiles/linker.dir/lib/linker.cpp.o"

# External object files for target linker
linker_EXTERNAL_OBJECTS =

liblinker.a: CMakeFiles/linker.dir/lib/linker.cpp.o
liblinker.a: CMakeFiles/linker.dir/build.make
liblinker.a: CMakeFiles/linker.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/wego/cpp_study/chapter11/diff_const_n_static/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library liblinker.a"
	$(CMAKE_COMMAND) -P CMakeFiles/linker.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/linker.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/linker.dir/build: liblinker.a
.PHONY : CMakeFiles/linker.dir/build

CMakeFiles/linker.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/linker.dir/cmake_clean.cmake
.PHONY : CMakeFiles/linker.dir/clean

CMakeFiles/linker.dir/depend:
	cd /home/wego/cpp_study/chapter11/diff_const_n_static/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wego/cpp_study/chapter11/diff_const_n_static /home/wego/cpp_study/chapter11/diff_const_n_static /home/wego/cpp_study/chapter11/diff_const_n_static/build /home/wego/cpp_study/chapter11/diff_const_n_static/build /home/wego/cpp_study/chapter11/diff_const_n_static/build/CMakeFiles/linker.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/linker.dir/depend
