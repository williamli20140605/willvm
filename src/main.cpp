#include "vm/cpu/cpu.hpp"
#include "vm/memory/ram/ram.hpp"
#include "vm/memory/rom/rom.hpp"
#include <iostream>

using namespace willvm::vm;

int main()
{
    CPU cpu;
    RAM ram(65536);
    ROM rom(65536);
    
    std::cout << "WillVM initialized successfully!" << std::endl;
    return 0;
}