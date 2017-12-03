cmake_minimum_required(VERSION 3.8)
project(IMS)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-pedantic -Wall -lm -lsimlib")

set(SOURCE_FILES main.cpp debug.h counters.cpp counters.h constants.h)

add_executable(IMS ${SOURCE_FILES})

find_library(lib_path simlib)
target_link_libraries(IMS "${lib_path}")
