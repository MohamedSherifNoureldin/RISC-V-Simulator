#pragma once
#ifndef UTYPE_H
#define UTYPE_H
#include "global.h"

class Utype
{
    public:
        static void LUI(int rd, int imm);
        static void AUIPC(int rd, int imm);
};

void Utype::LUI(int rd, int imm)
{
    // lui rd, imm
    registers[rd] = imm << 12;
    PC += 4;
}

void Utype::AUIPC(int rd, int imm)
{
    // auipc rd, imm
    imm = imm << 12;
    registers[rd] = PC + imm;
    PC += 4;
}

#endif