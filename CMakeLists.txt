cmake_minimum_required(VERSION 3.10)
project(Cpp_Projects)

set(CMAKE_CXX_STANDARD 20)

# Find raylib (vcpkg toolchain is set by CMakePresets.json)
find_package(raylib CONFIG REQUIRED)

# Reusable function for raylib projects
function(add_raylib_executable TARGET_NAME)
    cmake_parse_arguments(ARG "" "RESOURCES" "SOURCES" ${ARGN})

    # Create executable
    add_executable(${TARGET_NAME} ${ARG_SOURCES})

    # Link raylib
    target_link_libraries(${TARGET_NAME} PRIVATE raylib)

    # Windows-specific libraries
    if (WIN32)
        target_link_libraries(${TARGET_NAME} PRIVATE winmm)
    endif()

    # Handle resources if specified
    if (ARG_RESOURCES)
        set(RELEASE_RESOURCE_DIR "${CMAKE_CURRENT_BINARY_DIR}/bin/${TARGET_NAME}_${PROJECT_VERSION}/resources/")
        set(DEBUG_RESOURCE_DIR "${CMAKE_CURRENT_BINARY_DIR}/resources/")

        target_compile_definitions(
                ${TARGET_NAME}
                PUBLIC
                RESOURCES_PATH=$<IF:$<CONFIG:Release>,"./resources/","${DEBUG_RESOURCE_DIR}">
        )

        add_custom_command(
                TARGET ${TARGET_NAME}
                POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy_directory
                "${CMAKE_CURRENT_SOURCE_DIR}/${ARG_RESOURCES}"
                $<IF:$<CONFIG:Release>,"${RELEASE_RESOURCE_DIR}","${DEBUG_RESOURCE_DIR}">
        )
    endif()
endfunction()

# Add all subprojects
add_subdirectory(A1PA)
add_subdirectory(A1PB)
add_subdirectory(A2PA)
add_subdirectory(A2PB)
add_subdirectory(A3PA)
add_subdirectory(ReactorSim)