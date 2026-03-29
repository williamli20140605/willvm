#pragma once
#include <cstdint>

namespace willvm::vm
{
enum class Instruction : uint16_t
{
    NONE = 0x00,
    IMM = 0x01,
    ADD = 0x02,
    SUB = 0x03,
    AND = 0x04,
    OR = 0x05,
    NOT = 0x06,
    NAND = 0x07,
    NOR = 0x08,
    XOR = 0x09,
    LOAD = 0x0A,  // read memory
    STORE = 0x0B, // write memory
    CMP = 0x0C,   // compare
    JMP = 0x0D,   // jump to address
    BEQ = 0x0E,   // branch if equal
    BNE = 0x0F,   // branch if not equal
    BGT = 0x10,   // branch if greater
    BLT = 0x11,   // branch if less
    HLT = 0xFF,
};
} // namespace willvm::vm