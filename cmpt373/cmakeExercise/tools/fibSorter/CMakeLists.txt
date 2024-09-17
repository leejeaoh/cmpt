#target executable 
add_executable(fibSorter main.cpp)

#linking the executable with the sortIntegers lib
target_link_libraries(fibSorter PRIVATE sortIntegers)