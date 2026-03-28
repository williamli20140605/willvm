# WillVM

WillVM is a custom virtual machine implemented in C++. It features a modular architecture with key components including a CPU, Arithmetic Logic Unit (ALU), memory management (RAM/ROM), and a set of custom instructions.

## Architecture

The virtual machine is built with the following core components:

- **CPU**: Manages the execution flow using a decoder and ALU.
- **ALU**: Performs arithmetic and logic operations (ADD, SUB, AND, OR, XOR, etc.).
- **Decoder**: Decodes raw opcodes into executable instructions.
- **Memory**: Supports both RAM and ROM modules.
- **Registers**: A set of 64 general-purpose registers.

## Getting Started

### Prerequisites

- C++ Compiler (supporting C++17 or later)
- CMake (optional, for build management)

### Project Structure

```text
.
├── src/
│   ├── main.cpp          # Entry point
│   └── vm/               # VM core logic
│       ├── cpu/          # CPU implementation
│       ├── memory/       # RAM and ROM
│       └── vm.hpp        # Core definitions
└── README.md             # Project documentation
```

## License

This project is licensed under the MIT License.
