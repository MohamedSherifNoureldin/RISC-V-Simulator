#include "Utype.h"

void Utype::LUI(int rd, int imm)
{
    // lui rd, imm
    registers[rd] = imm << 12;
}

void Utype::AUIPC(int rd, int imm)
{
    // auipc rd, imm
    imm = imm << 12;
    registers[rd] = PC + imm;
}