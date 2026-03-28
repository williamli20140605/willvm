#pragma once
#include "../../vm.hpp"

namespace willvm::vm {

class Timer
{
  public:
    Timer();
    uint64_t time;
    void next_tick();
};

} // namespace willvm::vm
