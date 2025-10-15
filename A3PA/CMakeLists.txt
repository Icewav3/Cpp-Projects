# A1PB/CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(A3PA)

set(CMAKE_CXX_STANDARD 20)

# Find raylib package
find_package(raylib CONFIG REQUIRED)

# Include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(RELEASE_RESOURCE_DIR "${CMAKE_CURRENT_BINARY_DIR}/bin/A3PA_${PROJECT_VERSION}/resources/")
set(DEBUG_RESOURCE_DIR "${CMAKE_CURRENT_BINARY_DIR}/resources/")


# Define the executable
add_executable(A3PA frog_and_toads.cpp

        ../A1PB/Utility.hpp
        FrogAndToadFiles/ansi_view.cpp
        FrogAndToadFiles/board_model.cpp
        FrogAndToadFiles/console_controller.cpp
        FrogAndToadFiles/raylib_controller.cpp
        FrogAndToadFiles/raylib_view.cpp
        FrogAndToadFiles/console_view.cpp)

set(RELEASE_RESOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/bin/\
A3PA_${CMAKE_PROJECT_VERSION}/resources/"
)
set(DEBUG_RESOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/resources/")
target_compile_definitions(
        A3PA
        PUBLIC
        RESOURCES_PATH=$<IF:$<CONFIG:Release>,"./resources/","${DEBUG_RESOURCE_DIR}">
)



# Link raylib
target_link_libraries(A3PA PRIVATE raylib)

# On Windows, link additional system libraries that raylib needs
if (WIN32)
    target_link_libraries(A3PA PRIVATE winmm)
endif ()

add_custom_command(
        TARGET A3PA
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_CURRENT_SOURCE_DIR}/resources"
        $<IF:$<CONFIG:Release>,"${RELEASE_RESOURCE_DIR}","${DEBUG_RESOURCE_DIR}">
)
