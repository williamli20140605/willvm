#include "vm/cpu/cpu.hpp"
#include "vm/memory/memory.hpp"
#include <iostream>

using namespace willvm::vm;

int main()
{
    Memory mem(32768, {0x01, 0x05, 0x00, 0x01, 0xFF, 0x00, 0x00, 0x00, 0x01,
                       0x06, 0x00, 0x02});

    CPU cpu(mem);
    while (cpu.running)
    {
        cpu.tick();
    }

    std::cout << "Reg1 value: " << cpu.regs.read(1) << std::endl
              << "Reg2 value: " << cpu.regs.read(2) << std::endl;
    return 0;
}