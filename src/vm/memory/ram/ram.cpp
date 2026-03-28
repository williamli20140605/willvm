#include "ram.hpp"

namespace willvm::vm
{

RAM::RAM(size_t size) : _data(size, 0) {}

uint16_t RAM::read(uint64_t addr)
{
    if (addr >= _data.size())
        return 0;
    return _data[addr];
}

void RAM::write(uint64_t addr, uint16_t val)
{
    if (addr >= _data.size())
        return;
    _data[addr] = val;
}

} // namespace willvm::vm
