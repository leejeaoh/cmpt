# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

# If CMAKE_DISABLE_SOURCE_CHANGES is set to true and the source directory is an
# existing directory in our source tree, calling file(MAKE_DIRECTORY) on it
# would cause a fatal error, even though it would be a no-op.
if(NOT EXISTS "/Users/jeaohlee/Desktop/cmpt/cmpt373/cmakeExercise/build/_deps/sos-src")
  file(MAKE_DIRECTORY "/Users/jeaohlee/Desktop/cmpt/cmpt373/cmakeExercise/build/_deps/sos-src")
endif()
file(MAKE_DIRECTORY
  "/Users/jeaohlee/Desktop/cmpt/cmpt373/cmakeExercise/build/_deps/sos-build"
  "/Users/jeaohlee/Desktop/cmpt/cmpt373/cmakeExercise/build/_deps/sos-subbuild/sos-populate-prefix"
  "/Users/jeaohlee/Desktop/cmpt/cmpt373/cmakeExercise/build/_deps/sos-subbuild/sos-populate-prefix/tmp"
  "/Users/jeaohlee/Desktop/cmpt/cmpt373/cmakeExercise/build/_deps/sos-subbuild/sos-populate-prefix/src/sos-populate-stamp"
  "/Users/jeaohlee/Desktop/cmpt/cmpt373/cmakeExercise/build/_deps/sos-subbuild/sos-populate-prefix/src"
  "/Users/jeaohlee/Desktop/cmpt/cmpt373/cmakeExercise/build/_deps/sos-subbuild/sos-populate-prefix/src/sos-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/jeaohlee/Desktop/cmpt/cmpt373/cmakeExercise/build/_deps/sos-subbuild/sos-populate-prefix/src/sos-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/jeaohlee/Desktop/cmpt/cmpt373/cmakeExercise/build/_deps/sos-subbuild/sos-populate-prefix/src/sos-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
