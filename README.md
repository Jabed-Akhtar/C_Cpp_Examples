# C/C++ Examples

## Examples
| Examples                             | Infos                                               |
| ------------------------------------ | --------------------------------------------------- |
| HelloWorld_ConsoleApp                | IDE: VS                                             |
| Add-Two-Numbers_UserInput_ConsoleApp | IDE: VS                                             |
| Pointer_basic_ConsoleApp             | IDE: VS                                             |
| File_Handling                        | IDE: VS                                             |
| CMake_0_HelloWorld                   | CMake Project                                       |
| CMake_1_CMake-Cmds-1                 | CMake Project                                       |
| CMake_2_CMake-Cmds-2                 | CMake Project, <span style="color: red;">TBD</span> |
| CMake_3_CMake-Cmds-3                 | CMake Project, <span style="color: red;">TBD</span> |
| CMake_4_WithHeaders                  | CMake Project                                       |
| CMake_5_Static_Library               | CMake Project                                       |
| CMake_6_LibNSubDirs                  | CMake Project                                       |
| CMake_7_GTest                        | CMake Project                                       |
| CMake_8_GTest-n-WordSearchInScripts  | CMake Project, <span style="color: red;">TBD</span> |
| Proj_WordSearchInScripts             | CMake Project                                       |

## Visual Studio Projects
IDE used: *Microsoft Visual Studio Community 2019*

## CMake Projects
### CMake commands
#### Window
- Generate Visual Studio project files: cmake -G "Visual Studio 17 2022" .  //  cmake -S . -B build/
- Build the project: cmake --build .

#### Linux
> make version: GNU Make 4.3
> cmake version: 3.22.1
> cmake generator: Unix Makefiles
> C compiler: GNU 11.4.0

##### Simple Commands
- Go to project folder with c-codes and CMakeFiles.txt
- create build folder: § mkdir build
- go to build folder: § cd build
- generate build files: § cmake ..
- create executable: § make
- Run App: § ./hello_world

##### Commands with flags and more
- Generate build files: § cmake -S . -B build/
- Go to build/ and: § make
- Run executable: § ./HelloWorld

Unsorted commands:
- cmake ..
- cmake --build .
- to run executable: $ ./cmake_main
- $ make -> also runs cmake for us

### Some helping commands
>> ldd <project name>    -> example $ ldd cmake_main

#### 'cmake ..' not working -> '-- Check for working C compiler: /usr/bin/cc - broken'
    -> sudo apt-get install build-essential

