#include "timer.hpp"

namespace willvm::vm {

Timer::Timer() : time(0) {}

void Timer::next_tick() { time += 1; }

} // namespace willvm::vm