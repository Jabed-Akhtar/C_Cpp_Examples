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
### CMake and Platforms
#### Window
- Generate Visual Studio project files: cmake -G "Visual Studio 17 2022" .  //  cmake -S . -B build/
- Build the project: cmake --build .

#### Linux
Tools used:  
> cmake version: 3.22.1  
> make version: GNU Make 4.3  
> C compiler: GNU 11.4.0  

### CMake commands
- Go to project root directory: `cd <path-to-root-directory>`
- Generate build files:
  - Generate build files with detecting tools automatically: `cmake -B build` (same as `mkdir build && cd build && cmake ..`)
  - Generate build files with flags: `cmake -S . -B build -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++`
    - `-S .`: source directory (current directory)
    - `-B build`: build directory (build)
    - `-G "Unix Makefiles"`: select generator (Makefile)
    - `-DCMAKE_BUILD_TYPE=Debug`: select build type
    - `-DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++`: force specific compiler
- Build project:
  - Build project: `cmake --build build` or `cd build && make`
  - Make + Install: `cmake --build build --target install`
  - Clean before build: `cmake --build build --clean-first`
- Run executable: `/build/<app-name>.exe`
- Clean/Remove build directory: `rm -rf build/`

### Some helping commands
- `ldd /build/<app-name>.exe`: LDD: List Dynamic Dependecies (shows all shared library dependencies of an executable)

### Debugs / Errors
#### 'cmake ..' not working in linux -> '-- Check for working C compiler: /usr/bin/cc - broken'
    -> sudo apt-get install build-essential
