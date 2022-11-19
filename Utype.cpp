#pragma once
#ifndef UTYPE_H
#define UTYPE_H
#include "global.h"

class Utype
{
    public:
        static void LUI(int rd, int imm);
        static void AUIPC(int rd, int imm);
        static void print_Utype_machine_code(int opcode, int rd, int imm);
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
void Utype::print_Utype_machine_code(int opcode, int rd, int imm)
{
    int machine_code = (imm<<12) | (rd<<7) | opcode;

    cout << "Machine code: " << convert_to_binary(machine_code, 32) << endl;
    
    char lower = (char)machine_code;
    char upper = (char)(machine_code >> 8);
    char upper2 = (char)(machine_code >> 16);
    char upper3 = (char)(machine_code >> 24);

    memory.insert({ PC, lower });
    memory.insert({ PC + 1, upper });
    memory.insert({ PC + 2, upper2 });
    memory.insert({ PC + 3, upper3 });
}
#endif