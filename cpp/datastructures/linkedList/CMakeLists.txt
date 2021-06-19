cmake_minimum_required(VERSION 3.5)
project(linkedList)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Node.cpp Node.h List.cpp List.h)
add_executable(linkedList ${SOURCE_FILES})