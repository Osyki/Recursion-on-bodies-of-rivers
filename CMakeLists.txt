cmake_minimum_required(VERSION 3.20)
project(rivers2)

set(CMAKE_CXX_STANDARD 14)
include_directories(c:/cxxtest-4.4)

set(CXXTEST_INCLUDE_DIR c:/cxxtest-4.4)
set(CXXTEST_PYTHON_TESTGEN_EXECUTABLE c:/cxxtest-4.4/bin/cxxtestgen)

find_package(CxxTest REQUIRED)

if(CXXTEST_FOUND)

    enable_testing()
    # set(SOURCE_FILES runner.cpp Triangle.cpp)
    CXXTEST_ADD_TEST(unittest  #name
            runner.cpp  # THIS IS GENERATED BUT YOU NEED TO ADD IT HERE
            ${CMAKE_CURRENT_SOURCE_DIR}/Rivers.cpp  # add source files
            ${CMAKE_CURRENT_SOURCE_DIR}/testRivers.h
            )
endif()
add_executable(rivers2 main.cpp Rivers.cpp testRivers.h)
