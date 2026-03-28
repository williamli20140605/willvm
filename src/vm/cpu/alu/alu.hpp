#pragma once
#include "../../vm.hpp"

namespace willvm::vm
{

struct FullAdderResult
{
    uint16_t s;
    uint16_t c;
};

class ALU
{
  public:
    ALU();
    uint16_t _and(uint16_t a, uint16_t b);
    uint16_t _or(uint16_t a, uint16_t b);
    uint16_t _not(uint16_t a);
    uint16_t _nand(uint16_t a, uint16_t b);
    uint16_t _xor(uint16_t a, uint16_t b);
    uint16_t _nor(uint16_t a, uint16_t b);
    uint16_t _set(uint16_t a, uint16_t p, bool val);
    uint16_t _add(uint16_t a, uint16_t b);
    uint16_t _sub(uint16_t a, uint16_t b);

  private:
    FullAdderResult _add_1_bit(uint16_t a, uint16_t b, uint16_t carry);
};

} // namespace willvm::vm