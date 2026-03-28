#include "rom.hpp"

namespace willvm::vm
{

ROM::ROM(size_t size) : _data(size, 0) {}

uint16_t ROM::read(uint64_t addr)
{
    if (addr >= _data.size())
        return 0;
    return _data[addr];
}

void ROM::load(const std::vector<uint16_t> &content)
{
    for (size_t i = 0; i < content.size() && i < _data.size(); ++i)
    {
        _data[i] = content[i];
    }
}

} // namespace willvm::vm
