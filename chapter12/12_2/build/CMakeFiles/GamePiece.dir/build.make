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
CMAKE_SOURCE_DIR = /home/dangmu1996/cpp_study/chapter12/12_2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dangmu1996/cpp_study/chapter12/12_2/build

# Include any dependencies generated for this target.
include CMakeFiles/GamePiece.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/GamePiece.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/GamePiece.dir/flags.make

CMakeFiles/GamePiece.dir/lib/ChessPiece.cpp.o: CMakeFiles/GamePiece.dir/flags.make
CMakeFiles/GamePiece.dir/lib/ChessPiece.cpp.o: ../lib/ChessPiece.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dangmu1996/cpp_study/chapter12/12_2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/GamePiece.dir/lib/ChessPiece.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GamePiece.dir/lib/ChessPiece.cpp.o -c /home/dangmu1996/cpp_study/chapter12/12_2/lib/ChessPiece.cpp

CMakeFiles/GamePiece.dir/lib/ChessPiece.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GamePiece.dir/lib/ChessPiece.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dangmu1996/cpp_study/chapter12/12_2/lib/ChessPiece.cpp > CMakeFiles/GamePiece.dir/lib/ChessPiece.cpp.i

CMakeFiles/GamePiece.dir/lib/ChessPiece.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GamePiece.dir/lib/ChessPiece.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dangmu1996/cpp_study/chapter12/12_2/lib/ChessPiece.cpp -o CMakeFiles/GamePiece.dir/lib/ChessPiece.cpp.s

# Object files for target GamePiece
GamePiece_OBJECTS = \
"CMakeFiles/GamePiece.dir/lib/ChessPiece.cpp.o"

# External object files for target GamePiece
GamePiece_EXTERNAL_OBJECTS =

libGamePiece.a: CMakeFiles/GamePiece.dir/lib/ChessPiece.cpp.o
libGamePiece.a: CMakeFiles/GamePiece.dir/build.make
libGamePiece.a: CMakeFiles/GamePiece.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dangmu1996/cpp_study/chapter12/12_2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libGamePiece.a"
	$(CMAKE_COMMAND) -P CMakeFiles/GamePiece.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/GamePiece.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/GamePiece.dir/build: libGamePiece.a

.PHONY : CMakeFiles/GamePiece.dir/build

CMakeFiles/GamePiece.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/GamePiece.dir/cmake_clean.cmake
.PHONY : CMakeFiles/GamePiece.dir/clean

CMakeFiles/GamePiece.dir/depend:
	cd /home/dangmu1996/cpp_study/chapter12/12_2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dangmu1996/cpp_study/chapter12/12_2 /home/dangmu1996/cpp_study/chapter12/12_2 /home/dangmu1996/cpp_study/chapter12/12_2/build /home/dangmu1996/cpp_study/chapter12/12_2/build /home/dangmu1996/cpp_study/chapter12/12_2/build/CMakeFiles/GamePiece.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/GamePiece.dir/depend
