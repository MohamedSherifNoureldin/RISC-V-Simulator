#pragma once
#ifndef JYPE_CPP
#define JTYPE_CPP
#include "global.h"

class Jtype
{
public:
    static void JAL(int rd, int imm);
};

void Jtype::JAL(int rd, int imm)
{
    // jal rd, imm
    registers[rd] = PC + 4;
    PC = PC + imm;
}

#endif