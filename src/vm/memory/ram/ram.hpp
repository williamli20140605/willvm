#pragma once
#include "../../vm.hpp"
#include <vector>

namespace willvm::vm
{

class RAM
{
  public:
    RAM(size_t size = 65536);
    uint16_t read(uint64_t addr);
    void write(uint64_t addr, uint16_t val);

  private:
    std::vector<uint16_t> _data;
};

} // namespace willvm::vm
