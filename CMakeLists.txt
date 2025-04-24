cmake_minimum_required(VERSION 3.31)
project(lab_progressbar)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(test)

set(SOURCE_FILES main.cpp
        Subject.h
        Observer.h
        FileLoader.cpp
        FileLoader.h
        ProgressBar.cpp
        ProgressBar.h
        SourceFile.cpp
        SourceFile.h
        global_functions.h
        global_functions.cpp)

add_executable(lab_progressbar
        main.cpp
        FileLoader.cpp
        SourceFile.cpp
        ProgressBar.cpp
        global_functions.cpp
)

add_library(core ${SOURCE_FILES})
target_link_libraries(lab_progressbar core)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

find_library(NCURSES_LIB ncurses)
target_link_libraries(lab_progressbar ${NCURSES_LIB} core)