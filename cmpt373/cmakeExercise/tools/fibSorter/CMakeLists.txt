cmake_minimum_required(VERSION 3.28)
project(fibSorter)

add_executable(fibSorter main.cpp)

target_link_libraries(fibSorter PRIVATE sortIntegers c++abi)

target_compile_features(fibSorter PUBLIC cxx_std_23)

install(TARGETS fibSorter
    DESTINATION bin
)