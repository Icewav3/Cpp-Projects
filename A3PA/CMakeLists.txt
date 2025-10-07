# A1PB/CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(A3PA)

set(CMAKE_CXX_STANDARD 20)

# Find raylib package
find_package(raylib CONFIG REQUIRED)

# Include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Define the executable
add_executable(A3PA frog_and_toads.cpp

        ../A1PB/Utility.hpp
        FrogAndToadFiles/ansi_view.cpp
        FrogAndToadFiles/board_model.cpp
        FrogAndToadFiles/console_controller.cpp
        FrogAndToadFiles/raylib_controller.cpp
        FrogAndToadFiles/raylib_view.cpp
        FrogAndToadFiles/console_view.cpp)

# Link raylib
target_link_libraries(A3PA PRIVATE raylib)

# On Windows, link additional system libraries that raylib needs
if (WIN32)
    target_link_libraries(A3PA PRIVATE winmm)
endif ()

