# WillVM

WillVM is a custom 16/32-bit virtual machine implemented in C++. It features a modular architecture designed for flexibility and educational purposes.

## Key Features

- **32-bit Addressing**: Supports a 4GB virtual address space.
- **Paged Memory**: Sparse memory allocation using 4KB pages to minimize host RAM usage.
- **Unified Executer**: A streamlined architecture combining instruction decoding and execution.
- **Flexible ISA**:
    - **Immediate Operands**: Opcode-level bit-flags allow any operation (ADD, SUB, LOAD, etc.) to use raw constants directly.
    - **Control Flow**: Supports absolute jumps and conditional branching (`BEQ`, `BNE`, `BGT`, `BLT`) based on internal comparison flags.
- **Registers**: 64 general-purpose 16-bit registers.
- **Modern Build System**: Full CMake support for cross-platform development.

## Architecture

The virtual machine is built with the following core components:

- **CPU**: Manages the Fetch-Decode-Execute cycle.
- **ALU**: Performs arithmetic and logic operations (`ADD`, `SUB`, `AND`, `OR`, `XOR`, etc.).
- **Executer**: Decodes instructions (including bit-flag immediates) and executes logic.
- **Memory**: Paged sparse memory model with ROM protection.
- **PC (Program Counter)**: 32-bit instruction pointer.

## Getting Started

### Prerequisites

- C++ Compiler (supporting C++17 or later)
- CMake 3.10+

### Build & Run

```bash
mkdir build && cd build
cmake ..
make
./willvm
```

## Project Structure

```text
.
├── src/
│   ├── main.cpp          # Entry point & Test Program
│   └── vm/               # VM core logic
│       ├── cpu/          # CPU, ALU, Executer, Registers, PC
│       ├── memory/       # Paged Memory implementation
│       └── vm.hpp        # Core definitions
├── CMakeLists.txt        # Build configuration
└── README.md             # Project documentation
```

## License

This project is licensed under the MIT License.
