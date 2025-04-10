**GMake Commands Basics**

Commands/Scripting basic (Work can be seen in file '<project-root-folder>/CMakeLists.txt')  

## Contents  
- Project setup
- Messaging
- Variables
- Basic Operations
- Control Flows
- Basic targets

**Steps:**
1. Generate Build Files
    ```bash
    cmake -S . -B build -G "Visual Studio 16 2019"
    ```

2. Build the Executable
    ```bash
    cmake --build build
    ```

3. Run the App  
    ```bash
    .build/Debug/HelloWorld_CMake_basic.exe
    ```

**Result:**  
On *generating build files*:  
<img src="imgs/CMake_1_CMake-Cmds-1_result_1.png" alt="CMake_1_CMake-Cmds-1_result_1" style="width:600px;"/>

On *building executables*:  
<img src="imgs/CMake_1_CMake-Cmds-1_result_2.png" alt="CMake_1_CMake-Cmds-1_result_2" style="width:600px;"/>

On *running executable*:  
<img src="imgs/CMake_1_CMake-Cmds-1_result_3.png" alt="CMake_1_CMake-Cmds-1_result_3" style="width:500px;"/>
