cmake_minimum_required(VERSION 3.28.3)
project(sosier)

CPMAddPackage(
    NAME sos
    GIT_REPOSITORY https://github.com/nsumner/example-dependency.git
    GIT_TAG v0.2
)

add_executable(sosier main.cpp)

target_link_libraries(sosier PRIVATE sekrit-sos)
