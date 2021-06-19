cmake_minimum_required(VERSION 3.5)
project(stack)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Node.cpp Node.h Stack.cpp Stack.h)
add_executable(stack ${SOURCE_FILES})