#pragma once
#ifndef STYPE_CPP
#define STYPE_CPP
#include "global.h"
using namespace std;

class Stype
{
    public:
        static void SB(int rs1, int rs2, int imm);
        static void SH(int rs1, int rs2, int imm);    
        static void SW(int rs1, int rs2, int imm);
};

void Stype::SB(int rs1, int rs2, int imm)
{
    char temp = (char)registers[rs1];
    memory[registers[rs2] + imm] = temp;
    PC += 4;
}
void Stype::SH(int rs1, int rs2, int imm)
{
    short int temp = (short int)registers[rs1];
    char lower = (char)temp;
    char upper = (char)temp >> 8;
    memory[registers[rs2] + imm] = lower;
    memory[registers[rs2] + imm + 1] = upper;
    PC += 4;
}  
void Stype::SW(int rs1, int rs2, int imm)
{
    int temp = registers[rs1];
    char lower = (char)temp;
    char upper = (char)temp >> 8;
    char upper2 = (char)temp >> 16;
    char upper3 = (char)temp >> 24;
    memory[registers[rs2] + imm] = lower;
    memory[registers[rs2] + imm + 1] = upper;
    memory[registers[rs2] + imm + 2] = upper2;
    memory[registers[rs2] + imm + 3] = upper3;
    PC += 4;
}

#endif