#pragma once
#include "../../vm.hpp"
#include "../instructions.hpp"

namespace willvm::vm
{

class Decoder
{
  public:
    Decoder();
    Instruction decode(uint16_t raw_opcode);
};

} // namespace willvm::vm
