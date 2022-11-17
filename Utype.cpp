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
string binary_codee1=convert_to_binary(machine_code, 32).substr(0,8);
string binary_codee2=convert_to_binary(machine_code, 32).substr(8,8);
string binary_codee3=convert_to_binary(machine_code, 32).substr(16,8);
string binary_codee4=convert_to_binary(machine_code, 32).substr(24,8);



instructions_code.insert({PC-4, binary_codee4});
instructions_code.insert({PC-3, binary_codee3});
instructions_code.insert({PC-2, binary_codee2});
instructions_code.insert({PC-1, binary_codee1});
}
#endif