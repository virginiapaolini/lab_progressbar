# test/CMakeLists.txt

cmake_minimum_required(VERSION 3.12)

set(GOOGLETEST_VERSION 1.15.2)
add_subdirectory(./lib/googletest)
set(gtest_SOURCE_DIR ./lib/googletest/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(SOURCE_TEST_FILES
        runAllTest.cpp
        FileLoaderTest.cpp
        SourceFileTest.cpp
)

set(SOURCE_FILES
        ../Subject.h
        ../Observer.h
        ../FileLoader.cpp
        ../FileLoader.h
        ../ProgressBar.cpp
        ../ProgressBar.h
        ../SourceFile.cpp
        ../SourceFile.h
        ../global_functions.h
        ../global_functions.cpp
)

add_executable(runProgressBarTests ${SOURCE_TEST_FILES} ${SOURCE_FILES})

add_compile_definitions(UNIT_TEST)
target_compile_definitions(runProgressBarTests PRIVATE UNIT_TEST)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

find_library(NCURSES_LIB ncurses)
target_link_libraries(runProgressBarTests gtest gtest_main ${NCURSES_LIB})


