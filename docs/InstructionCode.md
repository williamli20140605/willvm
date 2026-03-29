# WillVM Instruction Set Architecture (ISA)

WillVM uses a 64-bit fixed-length instruction format (16-bit Opcode + 3x 16-bit Operands).

## Instruction Format

Each instruction is exactly 4 words (64 bits):
`| Opcode (16bit) | Operand 1 (16bit) | Operand 2 (16bit) | Operand 3 (16bit) |`

### Opcode Structure

The 16-bit Opcode includes bit-flags to determine if an operand is an **Immediate Value** or a **Register Index**.

- **Bit 15**: Operand 1 is Immediate (1) or Register (0).
- **Bit 14**: Operand 2 is Immediate (1) or Register (0).
- **Bit 13**: Operand 3 is Immediate (1) or Register (0).
- **Bits 0-11**: Instruction Type (Opcode Value).

## Opcodes Table

| Hex  | Name  | Description | Notes |
|------|-------|-------------|-------|
| 0x00 | NONE  | No operation | - |
| 0x01 | IMM   | Move value to register | Usually `MOV` with Bit 15 set |
| 0x02 | ADD   | Addition (op1 + op2 -> op3) | Supports `ADDI` via Flags |
| 0x03 | SUB   | Subtraction (op1 - op2 -> op3) | Supports `SUBI` via Flags |
| 0x04 | AND   | Bitwise AND | Supports `ANDI` |
| 0x05 | OR    | Bitwise OR | Supports `ORI` |
| 0x06 | NOT   | Bitwise NOT (op1 -> op3) | - |
| 0x07 | NAND  | Bitwise NAND | - |
| 0x08 | NOR   | Bitwise NOR | - |
| 0x09 | XOR   | Bitwise XOR | - |
| 0x0A | LOAD  | Load from Memory to Register | Address = `(op2 << 16) | op1` |
| 0x0B | STORE | Store Register to Memory | Address = `(op2 << 16) | op1` |
| 0x0C | CMP   | Compare values | Updates internal flags (Z, G, L) |
| 0x0D | JMP   | Absolute 32-bit Jump | Target = `(op2 << 16) | op1` |
| 0x0E | BEQ   | Branch if Equal (Z=1) | Target = `(op2 << 16) | op1` |
| 0x0F | BNE   | Branch if Not Equal (Z=0) | Target = `(op2 << 16) | op1` |
| 0x10 | BGT   | Branch if Greater (G=1) | Target = `(op2 << 16) | op1` |
| 0x11 | BLT   | Branch if Less (L=1) | Target = `(op2 << 16) | op1` |
| 0xFF | HLT   | Stop Execution | Sets `running = false` |

## Conditional Flags
Internal state managed by the `Executer`:
- **Z (Zero)**: Set if operands are equal.
- **G (Greater)**: Set if Operand 1 > Operand 2.
- **L (Less)**: Set if Operand 1 < Operand 2.
