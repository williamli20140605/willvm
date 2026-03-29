#include "cpu.hpp"

namespace willvm::vm
{

CPU::CPU(Memory &mem) : memory(mem), executer(alu, regs, memory, pc, running)
{
    running = true;
}

void CPU::tick()
{
    if (!running)
        return;
    // Fetch-Decode-Execute tick
    uint16_t opcode, operand1, operand2, operand3;
    opcode = fetch(pc.tick);
    operand1 = fetch(pc.tick + 1);
    operand2 = fetch(pc.tick + 2);
    operand3 = fetch(pc.tick + 3);
    executer.execute(opcode, operand1, operand2, operand3);
    pc.next_tick();
}

uint16_t CPU::fetch(uint32_t tick) { return memory.read(tick); }

} // namespace willvm::vm