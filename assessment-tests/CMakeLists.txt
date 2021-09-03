cmake_minimum_required(VERSION 3.10)
project(assessment-tests)

set(CMAKE_CXX_STANDARD 11)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(assessment-tests
        main.cpp
        tests.h
        ../RulesManager.h
        ../RulesManager.cpp
        ../SentenceParser.h
        ../SentenceParser.cpp)

TARGET_LINK_LIBRARIES(assessment-tests ${GTEST_LIBRARIES} pthread)
