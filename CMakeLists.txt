cmake_minimum_required(VERSION 3.8)
project(IMS)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-pedantic -Wall")

set(SOURCE_FILES main.cpp debug.h)

link_libraries('simlib')
add_executable(IMS ${SOURCE_FILES})