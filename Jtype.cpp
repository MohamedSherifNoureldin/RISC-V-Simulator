#pragma once
#ifndef JYPE_CPP
#define JTYPE_CPP
#include "global.h"

class Jtype
{
public:
    static void JAL(int rd, int imm);
    static void print_Jtype_machine_code(int opcode, int rd, int imm);
};

void Jtype::JAL(int rd, int imm)
{
    // jal rd, imm
    registers[rd] = PC + 4;
    PC = PC + imm;
}
void Jtype::print_Jtype_machine_code(int opcode, int rd, int imm)
{

   int machine_code = (imm<<12) | (rd<<7) | opcode;
    cout << "Machine code: " << convert_to_binary(machine_code, 32) << endl;
    string binary_codee1 = convert_to_binary(machine_code, 32).substr(0, 8);
    string binary_codee2 = convert_to_binary(machine_code, 32).substr(8, 8);
    string binary_codee3 = convert_to_binary(machine_code, 32).substr(16, 8);
    string binary_codee4 = convert_to_binary(machine_code, 32).substr(24, 8);

    instructions_code.insert({PC - 4, binary_codee4});
    instructions_code.insert({PC - 3, binary_codee3});
    instructions_code.insert({PC - 2, binary_codee2});
    instructions_code.insert({PC - 1, binary_codee1});
}

#endif