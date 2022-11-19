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

    int first_imm= stoi(convert_to_binary(imm,20).substr(0,1));
    int second_imm= stoi(convert_to_binary(imm,20).substr(1,10));
    int third_imm= stoi(convert_to_binary(imm,20).substr(11,1));
    int fourth_imm= stoi(convert_to_binary(imm,20).substr(12,8));
    int machine_code = (first_imm<<31) | (second_imm<<21) | (third_imm<<20) | (fourth_imm<<12) | (rd<<7) | opcode;
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