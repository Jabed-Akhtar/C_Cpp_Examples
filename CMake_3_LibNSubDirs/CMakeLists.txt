cmake_minimum_required(VERSION 3.22)
project(CMake_project_ws VERSION 1.0.0)

add_subdirectory(libs) # This must come first
add_subdirectory(src)
