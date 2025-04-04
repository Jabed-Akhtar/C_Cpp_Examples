# ************************************************
# @file             : CMakeLists.txt
# @file-Location    : <project-root-folder>/test
# @author           : Jabed-Akhtar
# @Date             : 22.08.2022
# ************************************************

cmake_minimum_required(VERSION 3.22)

set(This ExampleTests)

set(Sources
    ExampleTests.cpp
)

add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC
    gtest_main
    Example
)

add_test(
    NAME ${This}
    COMMAND ${This}
)


# **************** END OF FILE *******************