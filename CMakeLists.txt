cmake_minimum_required(VERSION 3.10)
project(WillVM VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Source files
set(SOURCES
    src/main.cpp
    src/vm/cpu/cpu.cpp
    src/vm/cpu/alu/alu.cpp
    src/vm/cpu/executer/executer.cpp
    src/vm/cpu/pc/pc.cpp
    src/vm/cpu/registers/registers.cpp
    src/vm/memory/memory.cpp
)

# Header include path
include_directories(src)

# Create executable
add_executable(willvm ${SOURCES})
