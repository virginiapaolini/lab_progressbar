cmake_minimum_required(VERSION 3.31)
project(lab_progressbar)

set(CMAKE_CXX_STANDARD 11)

add_executable(lab_progressbar main.cpp
        Subject.h
        Observer.h
        FileLoader.cpp
        FileLoader.h
        ProgressBar.cpp
        ProgressBar.h
        SourceFile.cpp
        SourceFile.h)

if(APPLE)
    target_compile_definitions(${PROJECT_NAME} PRIVATE __WXMAC__)
endif()
