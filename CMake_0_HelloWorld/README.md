Below it the available **build system (aka generator)**.

<img src="imgs/CMake_MSVC_BuildSystem.png" alt="CMake_MSVC_BuildSystem" style="width:600px;"/>

1. Generate Build Files
```bash
cmake -S . -B build -G "Visual Studio 16 2019"
```

1. Build the Executable
```bash
cmake --build build
```

1. Run the App  
```bash
.build/Debug/HelloWorld_CMake_basic.exe
```

Result:

<img src="imgs/HelloWorld_CMake_basic_1_result.png" alt="HelloWorld_CMake_basic_1_result" style="width:350px;"/>
