set(BINARY ${CMAKE_PROJECT_NAME})

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp)

set(SOURCES ${SOURCES})

add_executable(${BINARY}_run ${SOURCES})

add_library(${BINARY}_lib STATIC ${SOURCES})

# Function
FUNCTION(FindMacros)
    FOREACH(item faa foo bar)
        MESSAGE(STATUS "Item is: ${item}.")
    ENDFOREACH()
ENDFUNCTION()
FindMacros()


FILE(READ ${CMAKE_CURRENT_SOURCE_DIR}/GTest_Samples_Cpp/sample3_unittest.cc fileCont)
MESSAGE(STATUS fileCont)

FILE(GLOB SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/GTest_Samples_Cpp/*.cc")
