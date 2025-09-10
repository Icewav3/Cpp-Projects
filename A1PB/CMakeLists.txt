# A1PB/CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(A1PB)

set(CMAKE_CXX_STANDARD 14)

# Include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Define the executable
add_executable(A1PB main.cpp
        Utility.h)

# Optional: Additional dependencies
# target_link_libraries(A1PB some_library)
