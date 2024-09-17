#target executable
add_executable(cursesExample
    main.cpp
)

#find the ncurses package
set(CURSES_USE_NCURSES TRUE)
find_package(Curses REQUIRED)

#linking the ncurses lib to the executable
target_link_libraries(cursesExample PRIVATE ${CURSES_LIBRARIES})

target_include_directories(cursesExample PRIVATE ${CURSES_INCLUDE_DIRS})

install(TARGETS cursesExample
    DESTINATION bin
)