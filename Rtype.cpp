#pragma once
#ifndef RTYPE_CPP
#define RTYPE_CPP

#include "global.h"

class Rtype
{
   public:
    static void ADD(int rd, int rs1, int rs2);
    static void SUB(int rd, int rs1, int rs2);
    static void SLL(int rd, int rs1, int rs2);
    static void SLT(int rd, int rs1, int rs2);
    static void SLTU(int rd, int rs1, int rs2);
    static void XOR(int rd, int rs1, int rs2);
    static void SRL(int rd, int rs1, int rs2);
    static void SRA(int rd, int rs1, int rs2);
    static void OR(int rd, int rs1, int rs2);
    static void AND(int rd, int rs1, int rs2);
};

void Rtype::ADD(int rd, int rs1, int rs2)
{
    registers[rd] = registers[rs1] + registers[rs2];
    PC += 4;
}
void Rtype::SUB(int rd, int rs1, int rs2)
{
    registers[rd] = registers[rs1] - registers[rs2];
    PC += 4;
}
void Rtype::SLL(int rd, int rs1, int rs2)
{
    registers[rd] = registers[rs1] << registers[rs2];
    PC += 4;
}
void Rtype::SLT(int rd, int rs1, int rs2)
{
    registers[rd] = registers[rs1] < registers[rs2];
    PC += 4;
}
void Rtype::SLTU(int rd, int rs1, int rs2)
{
    registers[rd] = (unsigned int)registers[rs1] < (unsigned int)registers[rs2];
    PC += 4;
}
void Rtype::XOR(int rd, int rs1, int rs2)
{
    registers[rd] = registers[rs1] ^ registers[rs2];
    PC += 4;
}
void Rtype::SRL(int rd, int rs1, int rs2)
{
    registers[rd] = (unsigned int)registers[rs1] >> registers[rs2];
    PC += 4;
}
void Rtype::SRA(int rd, int rs1, int rs2)
{
    registers[rd] = registers[rs1] >> registers[rs2];
    PC += 4;
}
void Rtype::OR(int rd, int rs1, int rs2)
{
    registers[rd] = registers[rs1] | registers[rs2];
    PC += 4;
}
void Rtype::AND(int rd, int rs1, int rs2)
{
    registers[rd] = registers[rs1] & registers[rs2];
    PC += 4;
}

#endif