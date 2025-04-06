# Define the 'hello' library
add_library(
    #say_hello SHARED
    say_hello STATIC
    src/hello/hello.cpp
    src/hello/hello.hpp
)

#message(STATUS "Source Dir: ${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(say_hello PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)
