# ************************************************
# @file             : CMakeLists.txt
# @file-Location    : <project-root-folder>
# @author           : Jabed-Akhtar
# @Date             : 15.08.2022
# ************************************************

cmake_minimum_required(VERSION 3.22)
project(ProjGTstNWorSear
    VERSION 1.0.0
    DESCRIPTION "A Project to search for GTest-Macros with CMake"
    LANGUAGES C CXX
)

#set(CMAKE_EXECUTABLE "${CMake_BIN_DIR}/cmake")

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_subdirectory(src)
add_subdirectory(tst)
add_subdirectory(lib/googletest)

file(GLOB OUTPUT_VAR *.cxx)

add_test(NAME myDBTest COMMAND testDb)




# Scripting basics *******************************



# **************** END OF FILE *******************