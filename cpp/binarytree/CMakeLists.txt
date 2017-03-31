cmake_minimum_required(VERSION 3.5)
project(binarytree)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Node.cpp Node.h Tree.cpp Tree.h)
add_executable(binarytree ${SOURCE_FILES})