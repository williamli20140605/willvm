#include "vm/cpu/cpu.hpp"
#include "vm/memory/memory.hpp"
#include <iostream>

using namespace willvm::vm;

int main()
{
    Memory mem(
        32768,
        {
            0x8001, 0, 0, 1, // 0: IMM 0 -> R1
            0x4002, 1, 1, 1, // 4: ADDI R1, R1, 1
            0x400C, 1, 5, 0, // 8: CMP R1, 5 (op1=R1, op2=5_imm)
            0x8011, 4, 0, 0, // 12: BLT 4 (op1=4_imm, op2=0_imm -> Addr 4)
            0x00FF, 0, 0, 0  // 16: HLT
        });

    CPU cpu(mem);
    while (cpu.running)
    {
        cpu.tick();
    }

    std::cout << "Reg1 value: " << cpu.regs.read(1) << std::endl
              << "Reg2 value: " << cpu.regs.read(2) << std::endl;
    return 0;
}