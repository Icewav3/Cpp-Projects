cmake_minimum_required(VERSION 4.0)
project(Cpp_Projects)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(A1PA)
include_directories(A1PB)

add_executable(Cpp_Projects
        A1PA/main.cpp
        A1PA/main.hpp
        A1PB/main.cpp
        A1PB/main.hpp)
