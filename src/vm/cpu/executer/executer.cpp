#include "executer.hpp"

namespace willvm::vm
{

Executer::Executer(ALU &alu, Registers &regs, Memory &mem, PC &pc,
                   bool &running)
    : _alu(alu), _regs(regs), _memory(mem), _pc(pc), _running(running)
{
    _flags = {false, false, false};
}

uint16_t Executer::get_operand_val(uint16_t raw_val, bool is_imm)
{
    return is_imm ? raw_val : _regs.read(raw_val);
}

void Executer::execute(uint16_t raw_opcode, uint16_t raw_operand_1,
                       uint16_t raw_operand_2, uint16_t raw_operand_3)
{
    uint16_t opcode_val = raw_opcode & OPCODE_MASK;
    Instruction type = static_cast<Instruction>(opcode_val);

    bool op1_imm = (raw_opcode & FLAG_OP1_IMM) != 0;
    bool op2_imm = (raw_opcode & FLAG_OP2_IMM) != 0;
    bool op3_imm = (raw_opcode & FLAG_OP3_IMM) != 0;

    switch (type)
    {
    case Instruction::NONE:
        break;

    case Instruction::IMM:
        _regs.write(raw_operand_3, get_operand_val(raw_operand_1, op1_imm));
        break;

    case Instruction::ADD:
    {
        uint16_t res = _alu._add(get_operand_val(raw_operand_1, op1_imm),
                                 get_operand_val(raw_operand_2, op2_imm));
        _regs.write(raw_operand_3, res);
        break;
    }

    case Instruction::SUB:
    {
        uint16_t res = _alu._sub(get_operand_val(raw_operand_1, op1_imm),
                                 get_operand_val(raw_operand_2, op2_imm));
        _regs.write(raw_operand_3, res);
        break;
    }

    case Instruction::AND:
        _regs.write(raw_operand_3,
                    _alu._and(get_operand_val(raw_operand_1, op1_imm),
                              get_operand_val(raw_operand_2, op2_imm)));
        break;

    case Instruction::OR:
        _regs.write(raw_operand_3,
                    _alu._or(get_operand_val(raw_operand_1, op1_imm),
                             get_operand_val(raw_operand_2, op2_imm)));
        break;

    case Instruction::NOT:
        _regs.write(raw_operand_3,
                    _alu._not(get_operand_val(raw_operand_1, op1_imm)));
        break;

    case Instruction::NAND:
        _regs.write(raw_operand_3,
                    _alu._nand(get_operand_val(raw_operand_1, op1_imm),
                               get_operand_val(raw_operand_2, op2_imm)));
        break;

    case Instruction::NOR:
        _regs.write(raw_operand_3,
                    _alu._nor(get_operand_val(raw_operand_1, op1_imm),
                              get_operand_val(raw_operand_2, op2_imm)));
        break;

    case Instruction::XOR:
        _regs.write(raw_operand_3,
                    _alu._xor(get_operand_val(raw_operand_1, op1_imm),
                              get_operand_val(raw_operand_2, op2_imm)));
        break;

    case Instruction::CMP:
    {
        uint16_t v1 = get_operand_val(raw_operand_1, op1_imm);
        uint16_t v2 = get_operand_val(raw_operand_2, op2_imm);
        _flags.zero = (v1 == v2);
        _flags.greater = (v1 > v2);
        _flags.less = (v1 < v2);
        break;
    }

    case Instruction::JMP:
    {
        uint32_t addr =
            (static_cast<uint32_t>(get_operand_val(raw_operand_2, op2_imm))
             << 16) |
            get_operand_val(raw_operand_1, op1_imm);
        _pc.tick = addr;
        _pc.tick -= 4;
        break;
    }

    case Instruction::BEQ:
    {
        if (_flags.zero)
        {
            uint32_t addr =
                (static_cast<uint32_t>(get_operand_val(raw_operand_2, op2_imm))
                 << 16) |
                get_operand_val(raw_operand_1, op1_imm);
            _pc.tick = addr - 4;
        }
        break;
    }

    case Instruction::BNE:
    {
        if (!_flags.zero)
        {
            uint32_t addr =
                (static_cast<uint32_t>(get_operand_val(raw_operand_2, op2_imm))
                 << 16) |
                get_operand_val(raw_operand_1, op1_imm);
            _pc.tick = addr - 4;
        }
        break;
    }

    case Instruction::BGT:
    {
        if (_flags.greater)
        {
            uint32_t addr =
                (static_cast<uint32_t>(get_operand_val(raw_operand_2, op2_imm))
                 << 16) |
                get_operand_val(raw_operand_1, op1_imm);
            _pc.tick = addr - 4;
        }
        break;
    }

    case Instruction::BLT:
    {
        if (_flags.less)
        {
            uint32_t addr =
                (static_cast<uint32_t>(get_operand_val(raw_operand_2, op2_imm))
                 << 16) |
                get_operand_val(raw_operand_1, op1_imm);
            _pc.tick = addr - 4;
        }
        break;
    }

    case Instruction::LOAD:
    {
        uint32_t addr =
            (static_cast<uint32_t>(get_operand_val(raw_operand_2, op2_imm))
             << 16) |
            get_operand_val(raw_operand_1, op1_imm);
        _regs.write(raw_operand_3, _memory.read(addr));
        break;
    }

    case Instruction::STORE:
    {
        uint32_t addr =
            (static_cast<uint32_t>(get_operand_val(raw_operand_2, op2_imm))
             << 16) |
            get_operand_val(raw_operand_1, op1_imm);
        _memory.write(addr, get_operand_val(raw_operand_3, op3_imm));
        break;
    }

    case Instruction::HLT:
        _running = false;
        break;

    default:
        break;
    }
}

} // namespace willvm::vm