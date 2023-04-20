cmake_minimum_required(VERSION 3.21)

project(AppWithParameters 
    VERSION			1.02.0
    DESCRIPTION		"Application With Parameters"
    LANGUAGES		CXX	C
)

# include CMake fetching module
include(FetchContent)

# Signal that we will statically link sfml
set(BUILD_SHARED_LIBS OFF)

#Get SFML lib
FetchContent_Declare(
    SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.5.1
)

FetchContent_MakeAvailable(SFML)

add_executable(AppWithParameters
    "main.cpp"
    "helpers.cpp"
    "game/Coordinate.cpp"
    "game/Player.cpp"
    "game/World.cpp"
    "game/Simulation.cpp"
    "graphics/graphicstest.cpp")

target_compile_features(AppWithParameters PRIVATE cxx_std_20)

target_include_directories(AppWithParameters 
        PUBLIC ./
        PRIVATE game
        PRIVATE graphics
        )

# Link external libs we need
target_link_libraries(AppWithParameters
    sfml-graphics
)