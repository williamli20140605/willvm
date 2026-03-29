#include "memory.hpp"

namespace willvm::vm
{

Memory::Memory(uint32_t rom_size, const std::vector<uint16_t> &rom_content)
    : _rom_size(rom_size)
{
    for (uint32_t i = 0; i < rom_content.size(); i++)
    {
        uint32_t page_id = i / PAGE_SIZE_WORDS;
        uint32_t offset = i % PAGE_SIZE_WORDS;

        auto &page = _pages[page_id];
        if (page.empty())
        {
            page.resize(PAGE_SIZE_WORDS, 0);
        }
        page[offset] = rom_content[i];
    }
}

uint16_t Memory::read(uint32_t addr)
{
    uint32_t page_id = addr / PAGE_SIZE_WORDS;
    uint32_t offset = addr % PAGE_SIZE_WORDS;

    auto it = _pages.find(page_id);
    if (it != _pages.end())
    {
        return it->second[offset];
    }
    return 0;
}

void Memory::write(uint32_t addr, uint16_t val)
{
    if (addr < _rom_size)
    {
        return;
    }

    uint32_t page_id = addr / PAGE_SIZE_WORDS;
    uint32_t offset = addr % PAGE_SIZE_WORDS;

    auto &page = _pages[page_id];
    if (page.empty())
    {
        page.resize(PAGE_SIZE_WORDS, 0);
    }
    page[offset] = val;
}

} // namespace willvm::vm
