#pragma once
#include "../../vm.hpp"

namespace willvm::vm
{

class PC
{
  public:
    PC();
    uint32_t tick;
    void next_tick();
};

} // namespace willvm::vm
