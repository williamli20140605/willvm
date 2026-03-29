# WillVM Memory Model

WillVM implements a 32-bit address space with a sparse, paged memory model to optimize host resource usage.

## Address Space

- **Word Size**: 16 bits (all memory cells are `uint16_t`).
- **Address Range**: `0x00000000` to `0xFFFFFFFF` (4 Billion addresses).
- **Instruction Alignment**: 4 words (8 bytes).

## Paging System

Memory is divided into **4KB pages** (2048 words per page).
- **Dynamic Allocation**: Pages are created in host memory using `std::unordered_map` only when first accessed (Read/Write).
- **Efficiency**: Allows the VM to "support" 4GB of RAM while only consuming a few KB or MB of your actual hardware memory.

## ROM Protection

The VM supports a hardware-enforced ROM region at the start of the address space.
- **Default Size**: 32KB (`0x0000` to `0x7FFF`).
- **Protection**: `Memory::write` operations directed to this range are ignored.
- **Initialization**: Use `Memory` constructor provided `rom_content` to initialize firmware.

## Load and Store (32-bit Access)

Since registers are 16-bit, memory access instructions (`LOAD`, `STORE`) use **register pairs** or **immediates** to form a 32-bit address:
- `Address = (High_16_bits << 16) | Low_16_bits`
