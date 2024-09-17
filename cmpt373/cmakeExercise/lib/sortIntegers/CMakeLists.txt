#target library
add_library(sortIntegers STATIC SortIntegers.cpp)

#public header dir
target_include_directories(sortIntegers PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)