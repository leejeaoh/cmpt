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
include tools/fibSorter/CMakeFiles/fibSorter.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include tools/fibSorter/CMakeFiles/fibSorter.dir/compiler_depend.make

# Include the progress variables for this target.
include tools/fibSorter/CMakeFiles/fibSorter.dir/progress.make

# Include the compile flags for this target's objects.
include tools/fibSorter/CMakeFiles/fibSorter.dir/flags.make

tools/fibSorter/CMakeFiles/fibSorter.dir/main.cpp.o: tools/fibSorter/CMakeFiles/fibSorter.dir/flags.make
tools/fibSorter/CMakeFiles/fibSorter.dir/main.cpp.o: /Users/jeaohlee/Desktop/cmpt-coures/cmpt373/cmakeexercise/tools/fibSorter/main.cpp
tools/fibSorter/CMakeFiles/fibSorter.dir/main.cpp.o: tools/fibSorter/CMakeFiles/fibSorter.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/jeaohlee/Desktop/cmpt-coures/cmpt373/cmakeexercise/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tools/fibSorter/CMakeFiles/fibSorter.dir/main.cpp.o"
	cd /Users/jeaohlee/Desktop/cmpt-coures/cmpt373/cmakeexercise/build/tools/fibSorter && /opt/homebrew/opt/llvm/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tools/fibSorter/CMakeFiles/fibSorter.dir/main.cpp.o -MF CMakeFiles/fibSorter.dir/main.cpp.o.d -o CMakeFiles/fibSorter.dir/main.cpp.o -c /Users/jeaohlee/Desktop/cmpt-coures/cmpt373/cmakeexercise/tools/fibSorter/main.cpp

tools/fibSorter/CMakeFiles/fibSorter.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/fibSorter.dir/main.cpp.i"
	cd /Users/jeaohlee/Desktop/cmpt-coures/cmpt373/cmakeexercise/build/tools/fibSorter && /opt/homebrew/opt/llvm/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jeaohlee/Desktop/cmpt-coures/cmpt373/cmakeexercise/tools/fibSorter/main.cpp > CMakeFiles/fibSorter.dir/main.cpp.i

tools/fibSorter/CMakeFiles/fibSorter.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/fibSorter.dir/main.cpp.s"
	cd /Users/jeaohlee/Desktop/cmpt-coures/cmpt373/cmakeexercise/build/tools/fibSorter && /opt/homebrew/opt/llvm/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jeaohlee/Desktop/cmpt-coures/cmpt373/cmakeexercise/tools/fibSorter/main.cpp -o CMakeFiles/fibSorter.dir/main.cpp.s

# Object files for target fibSorter
fibSorter_OBJECTS = \
"CMakeFiles/fibSorter.dir/main.cpp.o"

# External object files for target fibSorter
fibSorter_EXTERNAL_OBJECTS =

bin/fibSorter: tools/fibSorter/CMakeFiles/fibSorter.dir/main.cpp.o
bin/fibSorter: tools/fibSorter/CMakeFiles/fibSorter.dir/build.make
bin/fibSorter: lib/libsortIntegers.a
bin/fibSorter: tools/fibSorter/CMakeFiles/fibSorter.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/jeaohlee/Desktop/cmpt-coures/cmpt373/cmakeexercise/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../bin/fibSorter"
	cd /Users/jeaohlee/Desktop/cmpt-coures/cmpt373/cmakeexercise/build/tools/fibSorter && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/fibSorter.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tools/fibSorter/CMakeFiles/fibSorter.dir/build: bin/fibSorter
.PHONY : tools/fibSorter/CMakeFiles/fibSorter.dir/build

tools/fibSorter/CMakeFiles/fibSorter.dir/clean:
	cd /Users/jeaohlee/Desktop/cmpt-coures/cmpt373/cmakeexercise/build/tools/fibSorter && $(CMAKE_COMMAND) -P CMakeFiles/fibSorter.dir/cmake_clean.cmake
.PHONY : tools/fibSorter/CMakeFiles/fibSorter.dir/clean

tools/fibSorter/CMakeFiles/fibSorter.dir/depend:
	cd /Users/jeaohlee/Desktop/cmpt-coures/cmpt373/cmakeexercise/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jeaohlee/Desktop/cmpt-coures/cmpt373/cmakeexercise /Users/jeaohlee/Desktop/cmpt-coures/cmpt373/cmakeexercise/tools/fibSorter /Users/jeaohlee/Desktop/cmpt-coures/cmpt373/cmakeexercise/build /Users/jeaohlee/Desktop/cmpt-coures/cmpt373/cmakeexercise/build/tools/fibSorter /Users/jeaohlee/Desktop/cmpt-coures/cmpt373/cmakeexercise/build/tools/fibSorter/CMakeFiles/fibSorter.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : tools/fibSorter/CMakeFiles/fibSorter.dir/depend

