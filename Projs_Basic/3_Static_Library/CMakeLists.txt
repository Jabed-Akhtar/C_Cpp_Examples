cmake_minimum_required(VERSION 3.10)

project(HelloStatic)

##################################################
# Create a library
##################################################
add_library(HelloStatic STATIC
    src/HelloStatic.cpp
)

target_include_directories(HelloStatic
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

##################################################
# Create executable
##################################################
add_executable(HelloApp
    src/main.cpp
)

# Link Library to the App
target_link_libraries(HelloApp
    PRIVATE
        HelloStatic
)
