#include "decoder.hpp"

namespace willvm::vm
{

Decoder::Decoder() {}

Instruction Decoder::decode(uint16_t raw_opcode)
{
    uint16_t opcode = raw_opcode & 0x00FF;
    return static_cast<Instruction>(opcode);
}

} // namespace willvm::vm