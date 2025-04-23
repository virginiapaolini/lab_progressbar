cmake_minimum_required(VERSION 3.12)

set(GOOGLETEST_VERSION 1.15.2)

add_subdirectory(./lib/googletest)
project(test)

set(gtest_SOURCE_DIR, ./lib/googletest/)
include_directories(${gtest_SOURCE_DIR}/include
        ${gtest_SOURCE_DIR})

set(SOURCE_TEST_FILES runAllTests.cpp FileLoaderTest.cpp SourceFileTest.cpp)
add_executable(runProgressBarTests ${SOURCE_TEST_FILES})
target_link_libraries(runProgressBarTests gtest gtest_main core)


