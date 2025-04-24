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
        SourceFile.h)

add_executable(lab_progressbar main.cpp)

add_library(core ${SOURCE_FILES})
target_link_libraries(lab_progressbar core)