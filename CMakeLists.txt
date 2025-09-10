cmake_minimum_required(VERSION 3.10)
project(Cpp_Projects)

set(CMAKE_CXX_STANDARD 14)

# Set up vcpkg toolchain
if(DEFINED ENV{VCPKG_ROOT})
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")
endif()

# Add all subprojects
add_subdirectory(A1PA)
add_subdirectory(A1PB)
add_subdirectory(A2PA)
# Add more projects as needed

