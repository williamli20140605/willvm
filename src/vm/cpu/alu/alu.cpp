#include "alu.hpp"

namespace willvm::vm
{

ALU::ALU() {}

uint16_t ALU::_and(uint16_t a, uint16_t b) { return a & b; }
uint16_t ALU::_or(uint16_t a, uint16_t b) { return a | b; }
uint16_t ALU::_not(uint16_t a) { return ~a; }
uint16_t ALU::_nand(uint16_t a, uint16_t b) { return ~(a & b); }
uint16_t ALU::_xor(uint16_t a, uint16_t b) { return a ^ b; }
uint16_t ALU::_nor(uint16_t a, uint16_t b) { return ~(a | b); }

uint16_t ALU::_set(uint16_t a, uint16_t p, bool val)
{
    uint16_t shift = p & 0xF;
    return (val == true) ? (a | (1 << shift)) : (a & ~(1 << shift));
}

uint16_t ALU::_add(uint16_t a, uint16_t b)
{
    uint16_t ans = 0;
    uint16_t c = 0;

    for (int i = 0; i < 16; i++)
    {
        uint16_t bit_a = (a >> i) & 1;
        uint16_t bit_b = (b >> i) & 1;
        FullAdderResult sum = _add_1_bit(bit_a, bit_b, c);
        ans |= (sum.s << i);
        c = sum.c;
    }

    return ans;
}

uint16_t ALU::_sub(uint16_t a, uint16_t b) { return _add(a, _add(_not(b), 1)); }

FullAdderResult ALU::_add_1_bit(uint16_t a, uint16_t b, uint16_t carry)
{
    a &= 1;
    b &= 1;
    carry &= 1;

    uint16_t s = (a ^ b) ^ carry;
    uint16_t c = (a & b) | (a & carry) | (b & carry);

    return FullAdderResult{s, c};
}

} // namespace willvm::vm