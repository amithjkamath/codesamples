cmake_minimum_required(VERSION 3.5)
project(sortingLib)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp sortalgo.h sortalgo.cpp List.cpp List.h Node.cpp Node.h)
add_executable(sortingLib ${SOURCE_FILES})