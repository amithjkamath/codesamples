cmake_minimum_required(VERSION 3.5)
project(queue)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Node.cpp Node.h Queue.cpp Queue.h)
add_executable(queue ${SOURCE_FILES})