cmake_minimum_required(VERSION 3.21)

project(AppWithParameters 
    VERSION			1.02.0
    DESCRIPTION		"Application With Parameters"
    LANGUAGES		CXX	C
)

add_executable(AppWithParameters
    "main.cpp")

target_compile_features(AppWithParameters PRIVATE cxx_std_17)

target_include_directories(AppWithParameters 
        PUBLIC ./)