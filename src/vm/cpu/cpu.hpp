#pragma once
#include "../memory/memory.hpp"
#include "alu/alu.hpp"
#include "decoder/decoder.hpp"
#include "pc/pc.hpp"
#include "registers/registers.hpp"

namespace willvm::vm
{

class CPU
{
  public:
    CPU(Memory &mem);
    Memory &memory;
    PC pc;
    ALU alu;
    Decoder decoder;
    Registers regs;
    bool running;

    void tick();
    uint16_t fetch(uint32_t tick);
    void execute(uint16_t raw_opcode, uint16_t operand1, uint16_t operand2,
                 uint16_t operand3);
};

} // namespace willvm::vm
