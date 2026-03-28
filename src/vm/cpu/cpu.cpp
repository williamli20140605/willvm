#include "cpu.hpp"

namespace willvm::vm
{

CPU::CPU() {}

void CPU::execute(uint16_t raw_opcode, uint16_t operand1, uint16_t operand2,
                  uint16_t operand3)
{
    Instruction instruction = decoder.decode(raw_opcode);
    // regular: op1 operate op2 -> op3
    switch (instruction)
    {
    case Instruction::NONE:
        break;
    case Instruction::IMM:
        regs.write(operand3, operand1);
        break;
    case Instruction::ADD:
        regs.write(operand3,
                   alu._add(regs.read(operand1), regs.read(operand2)));
        break;
    case Instruction::SUB:
        regs.write(operand3,
                   alu._sub(regs.read(operand1), regs.read(operand2)));
        break;
    case Instruction::AND:
        regs.write(operand3,
                   alu._and(regs.read(operand1), regs.read(operand2)));
        break;
    case Instruction::OR:
        regs.write(operand3, alu._or(regs.read(operand1), regs.read(operand2)));
        break;
    case Instruction::NOT:
        regs.write(operand3, alu._not(regs.read(operand1)));
        break;
    case Instruction::NAND:
        regs.write(operand3,
                   alu._nand(regs.read(operand1), regs.read(operand2)));
        break;
    case Instruction::NOR:
        regs.write(operand3,
                   alu._nor(regs.read(operand1), regs.read(operand2)));
        break;
    case Instruction::XOR:
        regs.write(operand3,
                   alu._xor(regs.read(operand1), regs.read(operand2)));
        break;
    case Instruction::HLT:
        break; // nothing yet
    default:
        break;
    }
}

} // namespace willvm::vm