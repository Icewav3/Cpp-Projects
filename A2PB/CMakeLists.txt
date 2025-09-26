# A1PB/CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(A2PB)

set(CMAKE_CXX_STANDARD 14)

# Find raylib package
find_package(raylib CONFIG REQUIRED)

# Include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Define the executable
add_executable(A2PB Game.cpp
        ControlPanelWidget.cpp
        ControlPanelWidget.h)

# Link raylib
target_link_libraries(A2PB PRIVATE raylib)

# On Windows, link additional system libraries that raylib needs
if (WIN32)
    target_link_libraries(A2PB PRIVATE winmm)
endif ()

