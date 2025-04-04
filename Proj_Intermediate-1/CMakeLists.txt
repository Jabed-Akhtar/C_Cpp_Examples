# ************************************************
# @file             : CMakeLists.txt
# @file-Location    : <project-root-folder>
# @author           : Jabed-Akhtar
# @Date             : 15.08.2022
# ************************************************

cmake_minimum_required(VERSION 3.22)

project(ProjectInter1 VERSION 1.0.0)


# Scripting basics *******************************
message(STATUS "----->>> 1. Scripting basic ---> ----------")
message(STATUS "-------------------------------------------")
set(var1 "var-string")
message(STATUS "Message from CMakeLists.txt from root project folder!")
message(STATUS "The project name is: ${PROJECT_NAME} ... version ${PROJECT_VERSION}.")
message(STATUS "The var1 value is: ${var1}")
message(STATUS "-------------------------------------------")


# Control-Flow and Auto-deferencing **************
message(STATUS "---> 2. Control-Flow and Auto-deferencing ->")
message(STATUS "-------------------------------------------")
set(varBool TRUE)
if(NOT varBool)  # varBool = "${varBool}"
    message(STATUS "If condition was met!")
else()
    message(STATUS "If condition failed!") # for this change condition to FALSE
endif()

# Comparing two strings
message(STATUS "-------------------------------------------")
set(str1 "This is 1st string.")
set(str2 "This is 2nd string.")
if(NOT str1 STREQUAL str2)  # varBool = "${varBool}"
    message(STATUS "Strings comparison condition met.")
else()
    message(STATUS "Strings comparison condition not met.")
endif()

# Comparing two arithmentics
message(STATUS "-------------------------------------------")
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

# while-Loop
message(STATUS "-------------------------------------------")
set(numW 1)
while(numW LESS 5)
    message(STATUS "Value is ${numW}.")
    math(EXPR numW "${numW} + 1")
endwhile()

# for-Loop
message(STATUS "-------------------------------------------")
foreach(item IN ITEMS foo bar baz qux)
    message(STATUS "Item is: ${item}.")
endforeach()

message(STATUS "-------------------------------------------")
foreach(idx RANGE 1 5 1) # parameters: starts-from, ends-at, steps
    message(STATUS "Index is: ${idx}.")
endforeach()
message(STATUS "-------------------------------------------")


# ************************************************
message(STATUS "----->>> 3. Function, Scopes, ... ---> ----")
message(STATUS "-------------------------------------------")
set(list1 1 2 3)

set(target1 GLOBAL)
set_property(
    "${target1}" #-> GLOBAL > kinda enum angument same as STATUS inside message
    PROPERTY FOO1
    "${list1}"
)
get_cmake_property(foo_value1 FOO1)
message(STATUS "Values of FOO1 are: ${foo_value1}")

message(STATUS "-------------------------------------------")
set(target2 DIRECTORY)
set_property(
    "${target2}"
    PROPERTY FOO2
    "${list1}"
)
get_property(foo_value2 "${target2}" PROPERTY FOO2)
message(STATUS "Values of FOO2 are: ${foo_value2}")

message(STATUS "-------------------------------------------")
set(target3 DIRECTORY "${PROJECT_SOURCE_DIR}")
set_property(
    ${target3}
    PROPERTY FOO3
    "${list1}"
)
get_property(foo_value3 ${target2} PROPERTY FOO3)
message(STATUS "Values of FOO3 are: ${foo_value3}")

# A Function
message(STATUS "-------------------------------------------")
function(fun1 arg1)
    message(STATUS "Message from Function fun1 with argument: ${arg1}.")
endfunction()
fun1(1) # calling the function
fun1(1 2 3) # only arg 1 will be taken in account, all other will be neglected and the function only takes 1 arg

# Function with for-Loop inside
message(STATUS "-------------------------------------------")
function(fun2)
    foreach(arg2 IN LISTS ARGN)
        message(STATUS "Got argument in fun2: ${arg2}.")
    endforeach()
endfunction()
fun2(1 2 3 4)

message(STATUS "-------------------------------------------")
function(fun3 first second)
    foreach(arg3 IN LISTS ARGN) # ARGN is is bould to the argument not present, i.e. 3 4
        message(STATUS "Got ARGN in fun3: ${arg3}.")
    endforeach()
    foreach(arg4 IN LISTS ARGV) # ARGV is bould to all arguments, i.e. 1 2 3 4
        message(STATUS "Got ARGV in fun3: ${arg4}.")
    endforeach()
endfunction()
fun3(1 2 3 4)

# Global vars
message(STATUS "-------------------------------------------")
set(GLOBAL_VAR1 Jab)
function(fun4)
    message(STATUS "Value of global var is: ${GLOBAL_VAR1}")
endfunction()
fun4()

message(STATUS "-------------------------------------------")
function(fun4)
    message(STATUS "Value of global var is: ${GLOBAL_VAR1}")
    set(GLOBAL_VAR1 12)
    #set(GLOBAL_VAR1 12 PARENT_SCOPE) #-> this results in setting GLOBAL_VAR1 to 12 but will be only for outside the function
    message(STATUS "Value of global var is: ${GLOBAL_VAR1}")
endfunction()
set(GLOBAL_VAR1 Jab) # this replaces variable declaration which was done inside function
fun4()
message(STATUS "Value of global var is: ${GLOBAL_VAR1}")

# function for incrementing number
message(STATUS "-------------------------------------------")
function(fun_increment1 var2)
    message(STATUS "Value before increment is ${${var2}}")
    math(EXPR newVar2 "${${var2}} + 1")
    message(STATUS "Value after increment is ${newVar2}")
endfunction()
set(value2 14)
fun_increment1(value2)

message(STATUS "-------------------------------------------")
function(fun_increment2 var3)
    math(EXPR newVar3 "${${var3}} + 1")
    set("${var3}" "${newVar3}" PARENT_SCOPE)
endfunction()
set(value3 14)
fun_increment2(value3) #-> this will increment value once -> +1
fun_increment2(value3) #-> this will increment value once -> +1+1
fun_increment2(value3) #-> this will increment value once -> +1+1+1
message(STATUS "Final value is ${value3}")

# function for adding two numbers
message(STATUS "-------------------------------------------")
function(sum1 out a b)
    math(EXPR ret "${a} + ${b}")
    set("${out}" "${ret}" PARENT_SCOPE)
endfunction()
sum1(value4 2 3)
message(STATUS "Added value is ${value4}")
message(STATUS "-------------------------------------------")


# **************** END OF FILE *******************