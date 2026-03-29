#pragma once
#include "../memory/memory.hpp"
#include "alu/alu.hpp"
#include "executer/executer.hpp"
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
    Executer executer;
    Registers regs;
    bool running;

    void tick();
    uint16_t fetch(uint32_t tick);
};

} // namespace willvm::vm
