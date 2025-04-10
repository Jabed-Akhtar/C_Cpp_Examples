# ************************************************
# @file             : CMakeLists.txt
# @file-Location    : <project-root-folder>
# @author           : Jabed-Akhtar (github)
# @date-of-creation : 2022.08.15
# ************************************************

# Project setup **********************************
# Set the min. CMake version needed
cmake_minimum_required(VERSION 3.22)

# Define project name, version and languages
project(CMake_Cmds_Basics
    VERSION 1.0.0
    LANGUAGES C CXX)

# Messaging **************************************
message(STATUS "-------------------------------------------")
message(STATUS ">>>>> Cmake Commands/Scripting Basics <<<<<")
message(STATUS "Message from CMakeLists.txt from root project folder!")

message(STATUS "-------------------------------------------")

# Variables **************************************
message(STATUS "----->>> Variables ---------------")
message(STATUS "Project: ${PROJECT_NAME} ... version ${PROJECT_VERSION}.")
set(var1 "var-string")
message(STATUS "The var1 value is: ${var1}")

message(STATUS "-------------------------------------------")

# Basic Operations *******************************
message(STATUS "----->>> Basic operations ---------------")
# String operations ---------------
# Concatenate strings
string(CONCAT my_string "Hello, " "CMake!")
message(STATUS "Concatenated string: ${my_string}")

# Get string length
string(LENGTH "${my_string}" my_string_length)
message(STATUS "Length of string: ${my_string_length}")

# List operations ---------------
# Create and append to a list
set(my_list "apple" "banana")
list(APPEND my_list "cherry" "date")
message(STATUS "My list: ${my_list}")

# Get list length
list(LENGTH my_list list_length)
message(STATUS "Length of list: ${list_length}")

# Math operations ---------------
math(EXPR sum "1 + 2 + 3")
message(STATUS "Sum = ${sum}")

math(EXPR power "2 * 2 * 2")
message(STATUS "2 to the power 3 = ${power}")

message(STATUS "-------------------------------------------")

# Control Flows **********************************
message(STATUS "----->>> Control Flows ---------------")
# if()/elseif()/els()/endif() ---------------
message(STATUS "---> 2. Control-Flow and Auto-deferencing ->")
set(varBool TRUE)
if(NOT varBool)  # varBool = "${varBool}"
    message(STATUS "If condition was met!")
else()
    message(STATUS "If condition failed!") # for this change condition to FALSE
endif()

# Comparing two strings
set(str1 "This is string A.")
set(str2 "This is string B.")
set(str3 "This is string C.")
message(STATUS "Starting string comparisons...")
if(str1 STREQUAL str2)  # varBool = "${varBool}"
    message(STATUS "str1 and str2 are EQUAL.")
elseif(str1 STREQUAL str3)
message(STATUS "str1 and str3 are EQUAL.")
else()
    message(STATUS "No matches found between str1 and other strings.")
endif()

# Comparing two arithmentics
set(num1 1)
set(num2 1)
set(str3 "This is 3rd string.")
if(NOT num1 EQUAL num2)  # varBool = "${varBool}"
    message(STATUS "Numbers comparison condition met.")
elseif(str3 MATCHES "string.$")
    message(STATUS "str3 ends with word 'string.'")
else()
    message(STATUS "Numbers comparison condition not met.")
endif()

# Practical example: Feature flag for enabling tests
#set(ENABLE_TESTS TRUE)  # Change to FALSE to disable tests
#message(STATUS "Configuring project...")
#if(NOT ENABLE_TESTS)
#    message(STATUS "Tests are DISABLED")
#    # Skip test configuration
#else()
#    message(STATUS "Tests are ENABLED")
#    # Add test targets
#    enable_testing()
#    add_subdirectory(tests)
#endif()
#message(STATUS "Configuration complete.")

# Practical example: Checking compiler flags
#set(SUGGESTED_FLAG "-O2")  # The flag we want to check
#set(FLAG1 "-O1")           # Existing flag 1
#set(FLAG2 "-O2")           # Existing flag 2
#message(STATUS "Checking optimization flags...")
#if(SUGGESTED_FLAG STREQUAL FLAG1)
#    message(STATUS "Flag already set to -O1 (basic optimization)")
#elseif(SUGGESTED_FLAG STREQUAL FLAG2)
#    message(STATUS "Flag already set to -O2 (recommended optimization)")
#else()
#    message(STATUS "Applying new optimization flag: ${SUGGESTED_FLAG}")
#    add_compile_options(${SUGGESTED_FLAG})
#endif()

message(STATUS "-------------------------------------------")

# while()/endwhile() ---------------
set(numW 1)
while(numW LESS 5)
    message(STATUS "Value is ${numW}.")
    math(EXPR numW "${numW} + 1")
endwhile()

# Countdown from 3 to 1
set(count 3)
message(STATUS "Countdown starting:")
while(count GREATER 0)
    message(STATUS "Count: ${count}")
    math(EXPR count "${count} - 1")  # Decrement counter
endwhile()
message(STATUS "Done!")

# Practical example: Loop through modules and construct file list
#while(count GREATER 0)
#    set(SRC "module${count}.cpp")
#    list(APPEND SOURCES ${SRC})
#    message(STATUS "Added source: ${SRC}")
#    math(EXPR count "${count} - 1")
#endwhile()

message(STATUS "-------------------------------------------")

# foreach()/endforeach() ---------------
message(STATUS "Starting foreach loop...")
foreach(item IN ITEMS foo bar baz qux)
    message(STATUS "Item is: ${item}.")
endforeach()
message(STATUS "Loop finished!")

foreach(idx RANGE 1 5 1) # parameters: starts-from, ends-at, steps
    message(STATUS "Index is: ${idx}.")
endforeach()

# Practical example
#foreach(program IN ITEMS server client tester)
#    add_executable(${program} ${program}.cpp)
#    target_link_libraries(${program} PRIVATE common_lib)
#endforeach()

# Basic targets ---------------
message(STATUS "----->>> Basic targets ---------------")
# Include header files -> Compiler will look for header files
include_directories(include)
# Create a static library -> Static library will be compiled into the executable
add_library(MyLib STATIC)
target_sources(MyLib PRIVATE src/greet.cpp)
# Create executable -> Executable namely MyApp will be generated
add_executable(MyApp)
target_sources(MyApp PRIVATE src/main.cpp)
# Link library with executable
target_link_libraries(MyApp PRIVATE MyLib)

# **************** END OF FILE *******************
