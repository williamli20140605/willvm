#pragma once
#include "../../vm.hpp"
#include <array>
#include <cstdint>

namespace willvm::vm
{

class Registers
{
  private:
    struct Register
    {
        uint16_t val = 0;
    };

    std::array<Register, 64> registers;

  public:
    Registers();
    uint16_t read(uint16_t addr);
    void write(uint16_t addr, uint16_t val);
};

} // namespace willvm::vm
