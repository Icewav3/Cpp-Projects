# A1PA/CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(A1PA)

set(CMAKE_CXX_STANDARD 14)

# Include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Define the executable
add_executable(A1PA main.cpp)

# Optional: Additional dependencies
# target_link_libraries(A1PA some_library)
