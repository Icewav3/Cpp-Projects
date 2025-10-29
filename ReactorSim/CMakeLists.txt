file(GLOB_RECURSE CLASS_SOURCES "Classes/*.cpp")
file(GLOB_RECURSE CLASS_HEADERS "Classes/*.h")

add_raylib_executable(ReactorSim
        SOURCES
        main.cpp
        ${CLASS_SOURCES}
        ${CLASS_HEADERS}

)