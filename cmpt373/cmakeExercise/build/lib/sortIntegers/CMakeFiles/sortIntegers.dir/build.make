# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.30.3/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.30.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/jeaohlee/Desktop/cmpt-coures/cmpt373/cmakeexercise

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/jeaohlee/Desktop/cmpt-coures/cmpt373/cmakeexercise/build

# Include any dependencies generated for this target.
include lib/sortIntegers/CMakeFiles/sortIntegers.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include lib/sortIntegers/CMakeFiles/sortIntegers.dir/compiler_depend.make

# Include the progress variables for this target.
include lib/sortIntegers/CMakeFiles/sortIntegers.dir/progress.make

# Include the compile flags for this target's objects.
include lib/sortIntegers/CMakeFiles/sortIntegers.dir/flags.make

lib/sortIntegers/CMakeFiles/sortIntegers.dir/SortIntegers.cpp.o: lib/sortIntegers/CMakeFiles/sortIntegers.dir/flags.make
lib/sortIntegers/CMakeFiles/sortIntegers.dir/SortIntegers.cpp.o: /Users/jeaohlee/Desktop/cmpt-coures/cmpt373/cmakeexercise/lib/sortIntegers/SortIntegers.cpp
lib/sortIntegers/CMakeFiles/sortIntegers.dir/SortIntegers.cpp.o: lib/sortIntegers/CMakeFiles/sortIntegers.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/jeaohlee/Desktop/cmpt-coures/cmpt373/cmakeexercise/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/sortIntegers/CMakeFiles/sortIntegers.dir/SortIntegers.cpp.o"
	cd /Users/jeaohlee/Desktop/cmpt-coures/cmpt373/cmakeexercise/build/lib/sortIntegers && /opt/homebrew/opt/llvm/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT lib/sortIntegers/CMakeFiles/sortIntegers.dir/SortIntegers.cpp.o -MF CMakeFiles/sortIntegers.dir/SortIntegers.cpp.o.d -o CMakeFiles/sortIntegers.dir/SortIntegers.cpp.o -c /Users/jeaohlee/Desktop/cmpt-coures/cmpt373/cmakeexercise/lib/sortIntegers/SortIntegers.cpp

lib/sortIntegers/CMakeFiles/sortIntegers.dir/SortIntegers.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/sortIntegers.dir/SortIntegers.cpp.i"
	cd /Users/jeaohlee/Desktop/cmpt-coures/cmpt373/cmakeexercise/build/lib/sortIntegers && /opt/homebrew/opt/llvm/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jeaohlee/Desktop/cmpt-coures/cmpt373/cmakeexercise/lib/sortIntegers/SortIntegers.cpp > CMakeFiles/sortIntegers.dir/SortIntegers.cpp.i

lib/sortIntegers/CMakeFiles/sortIntegers.dir/SortIntegers.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/sortIntegers.dir/SortIntegers.cpp.s"
	cd /Users/jeaohlee/Desktop/cmpt-coures/cmpt373/cmakeexercise/build/lib/sortIntegers && /opt/homebrew/opt/llvm/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jeaohlee/Desktop/cmpt-coures/cmpt373/cmakeexercise/lib/sortIntegers/SortIntegers.cpp -o CMakeFiles/sortIntegers.dir/SortIntegers.cpp.s

# Object files for target sortIntegers
sortIntegers_OBJECTS = \
"CMakeFiles/sortIntegers.dir/SortIntegers.cpp.o"

# External object files for target sortIntegers
sortIntegers_EXTERNAL_OBJECTS =

lib/libsortIntegers.a: lib/sortIntegers/CMakeFiles/sortIntegers.dir/SortIntegers.cpp.o
lib/libsortIntegers.a: lib/sortIntegers/CMakeFiles/sortIntegers.dir/build.make
lib/libsortIntegers.a: lib/sortIntegers/CMakeFiles/sortIntegers.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/jeaohlee/Desktop/cmpt-coures/cmpt373/cmakeexercise/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ../libsortIntegers.a"
	cd /Users/jeaohlee/Desktop/cmpt-coures/cmpt373/cmakeexercise/build/lib/sortIntegers && $(CMAKE_COMMAND) -P CMakeFiles/sortIntegers.dir/cmake_clean_target.cmake
	cd /Users/jeaohlee/Desktop/cmpt-coures/cmpt373/cmakeexercise/build/lib/sortIntegers && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sortIntegers.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/sortIntegers/CMakeFiles/sortIntegers.dir/build: lib/libsortIntegers.a
.PHONY : lib/sortIntegers/CMakeFiles/sortIntegers.dir/build

lib/sortIntegers/CMakeFiles/sortIntegers.dir/clean:
	cd /Users/jeaohlee/Desktop/cmpt-coures/cmpt373/cmakeexercise/build/lib/sortIntegers && $(CMAKE_COMMAND) -P CMakeFiles/sortIntegers.dir/cmake_clean.cmake
.PHONY : lib/sortIntegers/CMakeFiles/sortIntegers.dir/clean

lib/sortIntegers/CMakeFiles/sortIntegers.dir/depend:
	cd /Users/jeaohlee/Desktop/cmpt-coures/cmpt373/cmakeexercise/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jeaohlee/Desktop/cmpt-coures/cmpt373/cmakeexercise /Users/jeaohlee/Desktop/cmpt-coures/cmpt373/cmakeexercise/lib/sortIntegers /Users/jeaohlee/Desktop/cmpt-coures/cmpt373/cmakeexercise/build /Users/jeaohlee/Desktop/cmpt-coures/cmpt373/cmakeexercise/build/lib/sortIntegers /Users/jeaohlee/Desktop/cmpt-coures/cmpt373/cmakeexercise/build/lib/sortIntegers/CMakeFiles/sortIntegers.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : lib/sortIntegers/CMakeFiles/sortIntegers.dir/depend

