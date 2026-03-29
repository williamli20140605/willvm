#pragma once
#include <cstdint>
#include <unordered_map>
#include <vector>

namespace willvm::vm
{

class Memory
{
  private:
    static constexpr uint32_t PAGE_SIZE_WORDS = 2048;
    static constexpr uint32_t PAGE_MASK = PAGE_SIZE_WORDS - 1;

    std::unordered_map<uint32_t, std::vector<uint16_t>> _pages;
    uint32_t _rom_size;

  public:
  public:
    Memory(uint32_t rom_size = 32768, const std::vector<uint16_t> &rom_content = {});
    uint16_t read(uint32_t addr);
    void write(uint32_t addr, uint16_t val);
};

} // namespace willvm::vm
