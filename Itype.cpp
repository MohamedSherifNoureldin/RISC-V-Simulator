#include "Itype.h"

void Itype::JALR(int rd, int rs1, int imm)
{
    // jalr ra, 0(rd)
    PC = registers[rs1] + imm;
    registers[rd] = PC + 4;
}

void Itype::LH(int rd, int rs1, int imm)
{
    // lh rd, imm(rs1)
    if(memory.find(registers[rs1] + imm)!=memory.end())
        registers[rd] = (short int)memory[registers[rs1] + imm];
    else
        registers[rd] = 0;
}

void Itype::LB(int rd, int rs1, int imm)
{
    // lb rd, imm(rs1)
    if(memory.find(registers[rs1] + imm)!=memory.end())
        registers[rd] = (char)memory[registers[rs1] + imm];
    else
        registers[rd] = 0;
}

void Itype::LW(int rd, int rs1, int imm)
{
    // lw rd, imm(rs1)
    if(memory.find(registers[rs1] + imm)!=memory.end())
        registers[rd] = memory[registers[rs1] + imm];
    else
        registers[rd] = 0;
}

void Itype::LBU(int rd, int rs1, int imm)
{
    // lbu rd, imm(rs1)
    if(memory.find(registers[rs1] + imm)!=memory.end())
        registers[rd] = (unsigned char)memory[registers[rs1] + imm];
    else
        registers[rd] = 0;
}

void Itype::LHU(int rd, int rs1, int imm)
{
    // lh rd, imm(rs1)
    if(memory.find(registers[rs1] + imm)!=memory.end())
        registers[rd] = (unsigned short int)memory[registers[rs1] + imm];
    else
        registers[rd] = 0;
}

void Itype::ADDI(int rd, int rs1, int imm)
{
    // addi rd, rs1, imm
    registers[rd] = registers[rs1] + imm;
}

void Itype::SLTI(int rd, int rs1, int imm)
{
    // slti rd, rs1, imm
    if(registers[rs1] < imm)
        registers[rd] = 1;
    else
        registers[rd] = 0;
}

void Itype::SLTIU(int rd, int rs1, int imm)
{
    // sltiu rd, rs1, imm
    if((unsigned int)registers[rs1] < (unsigned int)imm)
        registers[rd] = 1;
    else
        registers[rd] = 0;
}

void Itype::XORI(int rd, int rs1, int imm)
{
    // xori rd, rs1, imm
    registers[rd] = registers[rs1] ^ imm;
}

void Itype::ORI(int rd, int rs1, int imm)
{
    // ori rd, rs1, imm
    registers[rd] = registers[rs1] | imm;
}

void Itype::ANDI(int rd, int rs1, int imm)
{
    // andi rd, rs1, imm
    registers[rd] = registers[rs1] & imm;
}

void Itype::SLLI(int rd, int rs1, int imm)
{
    // slli rd, rs1, imm
    registers[rd] = registers[rs1] << imm;
}

void Itype::SRLI(int rd, int rs1, int imm)
{
    // srli rd, rs1, imm
    registers[rd] = (unsigned int)registers[rs1] >> imm;
}

void Itype::SRAI(int rd, int rs1, int imm)
{
    // srai rd, rs1, imm
    registers[rd] = registers[rs1] >> imm;
}