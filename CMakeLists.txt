cmake_minimum_required(VERSION 3.10)
project(multiple_pattern)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)
set(TEST_DIR ${CMAKE_SOURCE_DIR}/test)
set(MAIN_DIR ${CMAKE_SOURCE_DIR}/main)


set(SOURCES
    ${SOURCE_DIR}/trie.cpp
)

include_directories(${SOURCE_DIR})