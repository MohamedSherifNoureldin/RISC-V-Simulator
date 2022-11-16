#include "Rtype.h"
#include "global.h"
void Rtype::ADD(int rd, int rs1, int rs2)
{
    registers[rd] = registers[rs1] + registers[rs2];
}
void Rtype::SUB(int rd, int rs1, int rs2)
{
    registers[rd] = registers[rs1] - registers[rs2];
}
void Rtype::SLL(int rd, int rs1, int rs2)
{
    registers[rd] = registers[rs1] << registers[rs2];
}
void Rtype::SLT(int rd, int rs1, int rs2)
{
    registers[rd] = registers[rs1] < registers[rs2];
}
void Rtype::SLTU(int rd, int rs1, int rs2)
{
    registers[rd] = (unsigned int)registers[rs1] < (unsigned int)registers[rs2];
}
void Rtype::XOR(int rd, int rs1, int rs2)
{
    registers[rd] = registers[rs1] ^ registers[rs2];
}
void Rtype::SRL(int rd, int rs1, int rs2)
{
    registers[rd] = (unsigned int)registers[rs1] >> registers[rs2];
}
void Rtype::SRA(int rd, int rs1, int rs2)
{
    registers[rd] = registers[rs1] >> registers[rs2];
}
void Rtype::OR(int rd, int rs1, int rs2)
{
    registers[rd] = registers[rs1] | registers[rs2];
}
void Rtype::AND(int rd, int rs1, int rs2)
{
    registers[rd] = registers[rs1] & registers[rs2];
}
