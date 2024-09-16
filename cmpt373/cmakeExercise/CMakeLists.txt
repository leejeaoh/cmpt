#Cmake version requirements
cmake_minimum_required(VERSION 3.28.3)
#project name
project(sorting)
#setting c++23 as requirements
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)
#executable 
add_executable(sorting)

#target sources
target_sources(sorting PRIVATE main.cpp SortIntegers.cpp)

#include for headers
target_include_directories(sorting PRIVATE ${CMAKE_SOURCE_DIR})

#clang setting for the complier
set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)