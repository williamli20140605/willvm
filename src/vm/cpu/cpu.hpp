#pragma once
#include "alu/alu.hpp"
#include "decoder/decoder.hpp"
#include "registers/registers.hpp"
#include "timer/timer.hpp"

namespace willvm::vm
{

class CPU
{
  public:
    CPU();
    Timer timer;
    ALU alu;
    Decoder decoder;
    Registers regs;

    void execute(uint16_t raw_opcode, uint16_t operand1, uint16_t operand2,
                 uint16_t operand3);
};

} // namespace willvm::vm
