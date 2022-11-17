#pragma once
#ifndef ITYPE_CPP
#define ITYPE_CPP
#include "global.h"

class Itype
{
public:
    static void JALR(int rd, int rs1, int imm);
    static void LB(int rd, int rs1, int imm);
    static void LH(int rd, int rs1, int imm);
    static void LW(int rd, int rs1, int imm);
    static void LBU(int rd, int rs1, int imm);
    static void LHU(int rd, int rs1, int imm);
    static void ADDI(int rd, int rs1, int imm);
    static void SLTI(int rd, int rs1, int imm);
    static void SLTIU(int rd, int rs1, int imm);
    static void XORI(int rd, int rs1, int imm);
    static void ORI(int rd, int rs1, int imm);
    static void ANDI(int rd, int rs1, int imm);
    static void SLLI(int rd, int rs1, int imm);
    static void SRLI(int rd, int rs1, int imm);
    static void SRAI(int rd, int rs1, int imm);
};

void Itype::JALR(int rd, int rs1, int imm)
{
    // jalr rd, imm(rs1)
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
    PC += 4;
}

void Itype::LB(int rd, int rs1, int imm)
{
    // lb rd, imm(rs1)
    if(memory.find(registers[rs1] + imm)!=memory.end())
        registers[rd] = (char)memory[registers[rs1] + imm];
    else
        registers[rd] = 0;
    PC += 4;
}

void Itype::LW(int rd, int rs1, int imm)
{
    // lw rd, imm(rs1)
    if(memory.find(registers[rs1] + imm)!=memory.end())
        registers[rd] = memory[registers[rs1] + imm];
    else
        registers[rd] = 0;
    PC += 4;
}

void Itype::LBU(int rd, int rs1, int imm)
{
    // lbu rd, imm(rs1)
    if(memory.find(registers[rs1] + imm)!=memory.end())
        registers[rd] = (unsigned char)memory[registers[rs1] + imm];
    else
        registers[rd] = 0;
    PC += 4;
}

void Itype::LHU(int rd, int rs1, int imm)
{
    // lh rd, imm(rs1)
    if(memory.find(registers[rs1] + imm)!=memory.end())
        registers[rd] = (unsigned short int)memory[registers[rs1] + imm];
    else
        registers[rd] = 0;
    PC += 4;
}

void Itype::ADDI(int rd, int rs1, int imm)
{
    // addi rd, rs1, imm
    registers[rd] = registers[rs1] + imm;
    PC += 4;
}

void Itype::SLTI(int rd, int rs1, int imm)
{
    // slti rd, rs1, imm
    if(registers[rs1] < imm)
        registers[rd] = 1;
    else
        registers[rd] = 0;
    PC += 4;
}

void Itype::SLTIU(int rd, int rs1, int imm)
{
    // sltiu rd, rs1, imm
    if((unsigned int)registers[rs1] < (unsigned int)imm)
        registers[rd] = 1;
    else
        registers[rd] = 0;
    PC += 4;
}

void Itype::XORI(int rd, int rs1, int imm)
{
    // xori rd, rs1, imm
    registers[rd] = registers[rs1] ^ imm;
    PC += 4;
}

void Itype::ORI(int rd, int rs1, int imm)
{
    // ori rd, rs1, imm
    registers[rd] = registers[rs1] | imm;
    PC += 4;
}

void Itype::ANDI(int rd, int rs1, int imm)
{
    // andi rd, rs1, imm
    registers[rd] = registers[rs1] & imm;
    PC += 4;
}

void Itype::SLLI(int rd, int rs1, int imm)
{
    // slli rd, rs1, imm
    registers[rd] = registers[rs1] << imm;
    PC += 4;
}

void Itype::SRLI(int rd, int rs1, int imm)
{
    // srli rd, rs1, imm
    registers[rd] = (unsigned int)registers[rs1] >> imm;
    PC += 4;
}

void Itype::SRAI(int rd, int rs1, int imm)
{
    // srai rd, rs1, imm
    registers[rd] = registers[rs1] >> imm;
    PC += 4;
}
#endif