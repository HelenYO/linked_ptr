# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/elena/Desktop/Linked_ptr

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/elena/Desktop/Linked_ptr/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Linked_ptr.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Linked_ptr.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Linked_ptr.dir/flags.make

CMakeFiles/Linked_ptr.dir/main3.cpp.o: CMakeFiles/Linked_ptr.dir/flags.make
CMakeFiles/Linked_ptr.dir/main3.cpp.o: ../main3.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/elena/Desktop/Linked_ptr/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Linked_ptr.dir/main3.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Linked_ptr.dir/main3.cpp.o -c /Users/elena/Desktop/Linked_ptr/main3.cpp

CMakeFiles/Linked_ptr.dir/main3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Linked_ptr.dir/main3.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/elena/Desktop/Linked_ptr/main3.cpp > CMakeFiles/Linked_ptr.dir/main3.cpp.i

CMakeFiles/Linked_ptr.dir/main3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Linked_ptr.dir/main3.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/elena/Desktop/Linked_ptr/main3.cpp -o CMakeFiles/Linked_ptr.dir/main3.cpp.s

CMakeFiles/Linked_ptr.dir/main3.cpp.o.requires:

.PHONY : CMakeFiles/Linked_ptr.dir/main3.cpp.o.requires

CMakeFiles/Linked_ptr.dir/main3.cpp.o.provides: CMakeFiles/Linked_ptr.dir/main3.cpp.o.requires
	$(MAKE) -f CMakeFiles/Linked_ptr.dir/build.make CMakeFiles/Linked_ptr.dir/main3.cpp.o.provides.build
.PHONY : CMakeFiles/Linked_ptr.dir/main3.cpp.o.provides

CMakeFiles/Linked_ptr.dir/main3.cpp.o.provides.build: CMakeFiles/Linked_ptr.dir/main3.cpp.o


# Object files for target Linked_ptr
Linked_ptr_OBJECTS = \
"CMakeFiles/Linked_ptr.dir/main3.cpp.o"

# External object files for target Linked_ptr
Linked_ptr_EXTERNAL_OBJECTS =

Linked_ptr: CMakeFiles/Linked_ptr.dir/main3.cpp.o
Linked_ptr: CMakeFiles/Linked_ptr.dir/build.make
Linked_ptr: CMakeFiles/Linked_ptr.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/elena/Desktop/Linked_ptr/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Linked_ptr"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Linked_ptr.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Linked_ptr.dir/build: Linked_ptr

.PHONY : CMakeFiles/Linked_ptr.dir/build

CMakeFiles/Linked_ptr.dir/requires: CMakeFiles/Linked_ptr.dir/main3.cpp.o.requires

.PHONY : CMakeFiles/Linked_ptr.dir/requires

CMakeFiles/Linked_ptr.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Linked_ptr.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Linked_ptr.dir/clean

CMakeFiles/Linked_ptr.dir/depend:
	cd /Users/elena/Desktop/Linked_ptr/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/elena/Desktop/Linked_ptr /Users/elena/Desktop/Linked_ptr /Users/elena/Desktop/Linked_ptr/cmake-build-debug /Users/elena/Desktop/Linked_ptr/cmake-build-debug /Users/elena/Desktop/Linked_ptr/cmake-build-debug/CMakeFiles/Linked_ptr.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Linked_ptr.dir/depend

