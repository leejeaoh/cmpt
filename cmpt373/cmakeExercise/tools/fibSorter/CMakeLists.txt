cmake_minimum_required(VERSION 3.28)
project(fibSorter)

add_executable(fibSorter main.cpp)

target_link_libraries(fibSorter PRIVATE sortIntegers)

install(TARGETS fibSorter
    DESTINATION bin
)
