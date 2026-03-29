#pragma once
#include "../../memory/memory.hpp"
#include "../../vm.hpp"
#include "../alu/alu.hpp"
#include "../instructions.hpp"
#include "../pc/pc.hpp"
#include "../registers/registers.hpp"
#include <vector>

namespace willvm::vm
{

class Executer
{
  private:
    ALU &_alu;
    Registers &_regs;
    Memory &_memory;
    PC &_pc;
    bool &_running;

    // Flags for comparison
    struct Flags
    {
        bool zero;
        bool greater;
        bool less;
    } _flags;

    // Flag bits in Opcode
    static constexpr uint16_t FLAG_OP1_IMM = 0x8000;
    static constexpr uint16_t FLAG_OP2_IMM = 0x4000;
    static constexpr uint16_t FLAG_OP3_IMM = 0x2000;
    static constexpr uint16_t OPCODE_MASK = 0x0FFF;

    struct InstructionInfo
    {
        Instruction type;
        bool op1_is_imm;
        bool op2_is_imm;
        bool op3_is_imm;
    };

    uint16_t get_operand_val(uint16_t raw_val, bool is_imm);

  public:
    Executer(ALU &alu, Registers &regs, Memory &mem, PC &pc, bool &running);
    void execute(uint16_t raw_opcode, uint16_t raw_operand_1,
                 uint16_t raw_operand_2, uint16_t raw_operand_3);
};

} // namespace willvm::vm