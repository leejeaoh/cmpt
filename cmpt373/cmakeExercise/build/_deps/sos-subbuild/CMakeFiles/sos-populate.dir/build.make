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
CMAKE_SOURCE_DIR = /Users/jeaohlee/Desktop/cmpt-coures/cmpt373/cmakeExercise/build/_deps/sos-subbuild

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/jeaohlee/Desktop/cmpt-coures/cmpt373/cmakeExercise/build/_deps/sos-subbuild

# Utility rule file for sos-populate.

# Include any custom commands dependencies for this target.
include CMakeFiles/sos-populate.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/sos-populate.dir/progress.make

CMakeFiles/sos-populate: CMakeFiles/sos-populate-complete

CMakeFiles/sos-populate-complete: sos-populate-prefix/src/sos-populate-stamp/sos-populate-install
CMakeFiles/sos-populate-complete: sos-populate-prefix/src/sos-populate-stamp/sos-populate-mkdir
CMakeFiles/sos-populate-complete: sos-populate-prefix/src/sos-populate-stamp/sos-populate-download
CMakeFiles/sos-populate-complete: sos-populate-prefix/src/sos-populate-stamp/sos-populate-update
CMakeFiles/sos-populate-complete: sos-populate-prefix/src/sos-populate-stamp/sos-populate-patch
CMakeFiles/sos-populate-complete: sos-populate-prefix/src/sos-populate-stamp/sos-populate-configure
CMakeFiles/sos-populate-complete: sos-populate-prefix/src/sos-populate-stamp/sos-populate-build
CMakeFiles/sos-populate-complete: sos-populate-prefix/src/sos-populate-stamp/sos-populate-install
CMakeFiles/sos-populate-complete: sos-populate-prefix/src/sos-populate-stamp/sos-populate-test
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/jeaohlee/Desktop/cmpt-coures/cmpt373/cmakeExercise/build/_deps/sos-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Completed 'sos-populate'"
	/opt/homebrew/Cellar/cmake/3.30.3/bin/cmake -E make_directory /Users/jeaohlee/Desktop/cmpt-coures/cmpt373/cmakeExercise/build/_deps/sos-subbuild/CMakeFiles
	/opt/homebrew/Cellar/cmake/3.30.3/bin/cmake -E touch /Users/jeaohlee/Desktop/cmpt-coures/cmpt373/cmakeExercise/build/_deps/sos-subbuild/CMakeFiles/sos-populate-complete
	/opt/homebrew/Cellar/cmake/3.30.3/bin/cmake -E touch /Users/jeaohlee/Desktop/cmpt-coures/cmpt373/cmakeExercise/build/_deps/sos-subbuild/sos-populate-prefix/src/sos-populate-stamp/sos-populate-done

sos-populate-prefix/src/sos-populate-stamp/sos-populate-update:
.PHONY : sos-populate-prefix/src/sos-populate-stamp/sos-populate-update

sos-populate-prefix/src/sos-populate-stamp/sos-populate-build: sos-populate-prefix/src/sos-populate-stamp/sos-populate-configure
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/jeaohlee/Desktop/cmpt-coures/cmpt373/cmakeExercise/build/_deps/sos-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "No build step for 'sos-populate'"
	cd /Users/jeaohlee/Desktop/cmpt-coures/cmpt373/cmakeexercise/build/_deps/sos-build && /opt/homebrew/Cellar/cmake/3.30.3/bin/cmake -E echo_append
	cd /Users/jeaohlee/Desktop/cmpt-coures/cmpt373/cmakeexercise/build/_deps/sos-build && /opt/homebrew/Cellar/cmake/3.30.3/bin/cmake -E touch /Users/jeaohlee/Desktop/cmpt-coures/cmpt373/cmakeExercise/build/_deps/sos-subbuild/sos-populate-prefix/src/sos-populate-stamp/sos-populate-build

sos-populate-prefix/src/sos-populate-stamp/sos-populate-configure: sos-populate-prefix/tmp/sos-populate-cfgcmd.txt
sos-populate-prefix/src/sos-populate-stamp/sos-populate-configure: sos-populate-prefix/src/sos-populate-stamp/sos-populate-patch
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/jeaohlee/Desktop/cmpt-coures/cmpt373/cmakeExercise/build/_deps/sos-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "No configure step for 'sos-populate'"
	cd /Users/jeaohlee/Desktop/cmpt-coures/cmpt373/cmakeexercise/build/_deps/sos-build && /opt/homebrew/Cellar/cmake/3.30.3/bin/cmake -E echo_append
	cd /Users/jeaohlee/Desktop/cmpt-coures/cmpt373/cmakeexercise/build/_deps/sos-build && /opt/homebrew/Cellar/cmake/3.30.3/bin/cmake -E touch /Users/jeaohlee/Desktop/cmpt-coures/cmpt373/cmakeExercise/build/_deps/sos-subbuild/sos-populate-prefix/src/sos-populate-stamp/sos-populate-configure

sos-populate-prefix/src/sos-populate-stamp/sos-populate-download: sos-populate-prefix/src/sos-populate-stamp/sos-populate-gitinfo.txt
sos-populate-prefix/src/sos-populate-stamp/sos-populate-download: sos-populate-prefix/src/sos-populate-stamp/sos-populate-mkdir
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/jeaohlee/Desktop/cmpt-coures/cmpt373/cmakeExercise/build/_deps/sos-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Performing download step (git clone) for 'sos-populate'"
	cd /Users/jeaohlee/Desktop/cmpt-coures/cmpt373/cmakeexercise/build/_deps && /opt/homebrew/Cellar/cmake/3.30.3/bin/cmake -DCMAKE_MESSAGE_LOG_LEVEL=VERBOSE -P /Users/jeaohlee/Desktop/cmpt-coures/cmpt373/cmakeExercise/build/_deps/sos-subbuild/sos-populate-prefix/tmp/sos-populate-gitclone.cmake
	cd /Users/jeaohlee/Desktop/cmpt-coures/cmpt373/cmakeexercise/build/_deps && /opt/homebrew/Cellar/cmake/3.30.3/bin/cmake -E touch /Users/jeaohlee/Desktop/cmpt-coures/cmpt373/cmakeExercise/build/_deps/sos-subbuild/sos-populate-prefix/src/sos-populate-stamp/sos-populate-download

sos-populate-prefix/src/sos-populate-stamp/sos-populate-install: sos-populate-prefix/src/sos-populate-stamp/sos-populate-build
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/jeaohlee/Desktop/cmpt-coures/cmpt373/cmakeExercise/build/_deps/sos-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "No install step for 'sos-populate'"
	cd /Users/jeaohlee/Desktop/cmpt-coures/cmpt373/cmakeexercise/build/_deps/sos-build && /opt/homebrew/Cellar/cmake/3.30.3/bin/cmake -E echo_append
	cd /Users/jeaohlee/Desktop/cmpt-coures/cmpt373/cmakeexercise/build/_deps/sos-build && /opt/homebrew/Cellar/cmake/3.30.3/bin/cmake -E touch /Users/jeaohlee/Desktop/cmpt-coures/cmpt373/cmakeExercise/build/_deps/sos-subbuild/sos-populate-prefix/src/sos-populate-stamp/sos-populate-install

sos-populate-prefix/src/sos-populate-stamp/sos-populate-mkdir:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/jeaohlee/Desktop/cmpt-coures/cmpt373/cmakeExercise/build/_deps/sos-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Creating directories for 'sos-populate'"
	/opt/homebrew/Cellar/cmake/3.30.3/bin/cmake -Dcfgdir= -P /Users/jeaohlee/Desktop/cmpt-coures/cmpt373/cmakeExercise/build/_deps/sos-subbuild/sos-populate-prefix/tmp/sos-populate-mkdirs.cmake
	/opt/homebrew/Cellar/cmake/3.30.3/bin/cmake -E touch /Users/jeaohlee/Desktop/cmpt-coures/cmpt373/cmakeExercise/build/_deps/sos-subbuild/sos-populate-prefix/src/sos-populate-stamp/sos-populate-mkdir

sos-populate-prefix/src/sos-populate-stamp/sos-populate-patch: sos-populate-prefix/src/sos-populate-stamp/sos-populate-patch-info.txt
sos-populate-prefix/src/sos-populate-stamp/sos-populate-patch: sos-populate-prefix/src/sos-populate-stamp/sos-populate-update
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/jeaohlee/Desktop/cmpt-coures/cmpt373/cmakeExercise/build/_deps/sos-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "No patch step for 'sos-populate'"
	/opt/homebrew/Cellar/cmake/3.30.3/bin/cmake -E echo_append
	/opt/homebrew/Cellar/cmake/3.30.3/bin/cmake -E touch /Users/jeaohlee/Desktop/cmpt-coures/cmpt373/cmakeExercise/build/_deps/sos-subbuild/sos-populate-prefix/src/sos-populate-stamp/sos-populate-patch

sos-populate-prefix/src/sos-populate-stamp/sos-populate-update:
.PHONY : sos-populate-prefix/src/sos-populate-stamp/sos-populate-update

sos-populate-prefix/src/sos-populate-stamp/sos-populate-test: sos-populate-prefix/src/sos-populate-stamp/sos-populate-install
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/jeaohlee/Desktop/cmpt-coures/cmpt373/cmakeExercise/build/_deps/sos-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "No test step for 'sos-populate'"
	cd /Users/jeaohlee/Desktop/cmpt-coures/cmpt373/cmakeexercise/build/_deps/sos-build && /opt/homebrew/Cellar/cmake/3.30.3/bin/cmake -E echo_append
	cd /Users/jeaohlee/Desktop/cmpt-coures/cmpt373/cmakeexercise/build/_deps/sos-build && /opt/homebrew/Cellar/cmake/3.30.3/bin/cmake -E touch /Users/jeaohlee/Desktop/cmpt-coures/cmpt373/cmakeExercise/build/_deps/sos-subbuild/sos-populate-prefix/src/sos-populate-stamp/sos-populate-test

sos-populate-prefix/src/sos-populate-stamp/sos-populate-update: sos-populate-prefix/tmp/sos-populate-gitupdate.cmake
sos-populate-prefix/src/sos-populate-stamp/sos-populate-update: sos-populate-prefix/src/sos-populate-stamp/sos-populate-update-info.txt
sos-populate-prefix/src/sos-populate-stamp/sos-populate-update: sos-populate-prefix/src/sos-populate-stamp/sos-populate-download
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/jeaohlee/Desktop/cmpt-coures/cmpt373/cmakeExercise/build/_deps/sos-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Performing update step for 'sos-populate'"
	cd /Users/jeaohlee/Desktop/cmpt-coures/cmpt373/cmakeexercise/build/_deps/sos-src && /opt/homebrew/Cellar/cmake/3.30.3/bin/cmake -Dcan_fetch=YES -DCMAKE_MESSAGE_LOG_LEVEL=VERBOSE -P /Users/jeaohlee/Desktop/cmpt-coures/cmpt373/cmakeExercise/build/_deps/sos-subbuild/sos-populate-prefix/tmp/sos-populate-gitupdate.cmake

sos-populate: CMakeFiles/sos-populate
sos-populate: CMakeFiles/sos-populate-complete
sos-populate: sos-populate-prefix/src/sos-populate-stamp/sos-populate-build
sos-populate: sos-populate-prefix/src/sos-populate-stamp/sos-populate-configure
sos-populate: sos-populate-prefix/src/sos-populate-stamp/sos-populate-download
sos-populate: sos-populate-prefix/src/sos-populate-stamp/sos-populate-install
sos-populate: sos-populate-prefix/src/sos-populate-stamp/sos-populate-mkdir
sos-populate: sos-populate-prefix/src/sos-populate-stamp/sos-populate-patch
sos-populate: sos-populate-prefix/src/sos-populate-stamp/sos-populate-test
sos-populate: sos-populate-prefix/src/sos-populate-stamp/sos-populate-update
sos-populate: CMakeFiles/sos-populate.dir/build.make
.PHONY : sos-populate

# Rule to build all files generated by this target.
CMakeFiles/sos-populate.dir/build: sos-populate
.PHONY : CMakeFiles/sos-populate.dir/build

CMakeFiles/sos-populate.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sos-populate.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sos-populate.dir/clean

CMakeFiles/sos-populate.dir/depend:
	cd /Users/jeaohlee/Desktop/cmpt-coures/cmpt373/cmakeExercise/build/_deps/sos-subbuild && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jeaohlee/Desktop/cmpt-coures/cmpt373/cmakeExercise/build/_deps/sos-subbuild /Users/jeaohlee/Desktop/cmpt-coures/cmpt373/cmakeExercise/build/_deps/sos-subbuild /Users/jeaohlee/Desktop/cmpt-coures/cmpt373/cmakeExercise/build/_deps/sos-subbuild /Users/jeaohlee/Desktop/cmpt-coures/cmpt373/cmakeExercise/build/_deps/sos-subbuild /Users/jeaohlee/Desktop/cmpt-coures/cmpt373/cmakeExercise/build/_deps/sos-subbuild/CMakeFiles/sos-populate.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/sos-populate.dir/depend

