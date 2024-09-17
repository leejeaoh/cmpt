#clang setting for the complier
set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)
#Cmake version requirements
cmake_minimum_required(VERSION 3.28.3)
#project name
project(sorting)
#setting c++23 as requirements
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#setting output dir
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib") 

#adding sub dir for lib and exc
add_subdirectory(lib/sortIntegers)
add_subdirectory(tools/fibSorter)