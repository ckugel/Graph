cmake_minimum_required(VERSION 3.20)
project(anotherGraph)

set(CMAKE_CXX_STANDARD 20)

add_executable(anotherGraph main.cpp Graph.h Graph.cpp Node.h Node.cpp)
