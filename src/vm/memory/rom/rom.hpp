#pragma once
#include "../../vm.hpp"
#include <vector>

namespace willvm::vm
{

class ROM
{
  public:
    ROM(size_t size = 65536);
    uint16_t read(uint64_t addr);

    void load(const std::vector<uint16_t> &content);

  private:
    std::vector<uint16_t> _data;
};

} // namespace willvm::vm
