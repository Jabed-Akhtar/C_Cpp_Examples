# C/C++ Examples

## Examples
| Examples                 | Infos         |
|--------------------------|---------------|
|HelloWorld_ConsoleApp     |IDE: VS        |
|Add-Two-Numbers_UserInput_ConsoleApp |IDE: VS        |
|Pointer_basic_ConsoleApp  |IDE: VS        |
|HelloWorld_CMake_basic    |IDE: VS        |
|File_Handling             |IDE: VS        |
|Projs_Basic               |CMake Project  |
|Proj_Basic_LibNSubDirs    |CMake Project  |
|Proj_GTest-N-CMake        |CMake Project  |
|Proj_GTest-N-WordSearchInScripts|CMake Project  |
|Proj_Intermediate-1|CMake Project  |
|Proj_Intermediate-2|CMake Project  |
|Proj_WordSearchInScripts  |CMake Project  |

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

