include("/Users/jeaohlee/Desktop/cmpt-coures/cmpt373/cmakeexercise/cmake/CPM.cmake")
CPMAddPackage("NAME;sos;GIT_REPOSITORY;https://github.com/nsumner/example-dependency.git;GIT_TAG;v0.2")
set(sos_FOUND TRUE)