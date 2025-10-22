# ReactorSim/CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(ReactorSim)

set(CMAKE_CXX_STANDARD 20)

# Include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Define the executable
add_executable(ReactorSim main.cpp
        Classes/GameManager.cpp
        Classes/GameManager.h
)

# Optional: Additional dependencies
# target_link_libraries(ReactorSim some_library)
