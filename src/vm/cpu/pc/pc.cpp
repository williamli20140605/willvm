#include "pc.hpp"

namespace willvm::vm
{

PC::PC() : tick(0) {}

void PC::next_tick() { tick += 4; }

} // namespace willvm::vm