#include "registers.hpp"

namespace willvm::vm
{

Registers::Registers() {}

uint16_t Registers::read(uint16_t addr)
{
    if (addr >= 64 || addr == 0)
        return 0;
    return registers[addr].val;
}

void Registers::write(uint16_t addr, uint16_t val)
{
    // r0 should always be 0
    if (addr >= 64 || addr == 0)
        return;
    registers[addr].val = val;
}

} // namespace willvm::vm