cmake_minimum_required(VERSION 3.12)
#project(test)

#enable_testing()

#istruzioni per compilare la lib gtest e per dsire in quali cartelle mi aspetto di trovare gli header di gtest
set(GOOGLETEST_VERSION 1.15.2)
add_subdirectory(./lib/googletest)
set(gtest_SOURCE_DIR, ./lib/googletest/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(SOURCE_TEST_FILES
        runAllTest.cpp FileLoaderTest.cpp SourceFileTest.cpp)

if(COMMAND cmake_policy)
    cmake_policy(SET CMP0003 NEW)
endif(COMMAND cmake_policy)

add_executable(runProgressBarTests ${SOURCE_TEST_FILES})
target_link_libraries(runProgressBarTests core gtest gtest_main ncurses)

