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
        static void print_Stype_machine_code(int opcode, int funct3, int rs1, int rs2, int imm);
};

void Stype::SB(int rs1, int rs2, int imm)
{
    // sb rs1, imm(rs2)	
    char temp = (char)registers[rs1];
    memory[registers[rs2] + imm] = temp;
    PC += 4;
}
void Stype::SH(int rs1, int rs2, int imm)
{
    // sh rs1, imm(rs2)
    short int temp = (short int)registers[rs1];
    char lower = (char)temp;
    char upper = (char)temp >> 8;
    memory[registers[rs2] + imm] = lower;
    memory[registers[rs2] + imm + 1] = upper;
    PC += 4;
}  
void Stype::SW(int rs1, int rs2, int imm)
{
    // sw rs1, imm(rs2)
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
void Stype::print_Stype_machine_code(int opcode, int funct3, int rs1, int rs2, int imm)
{
 // to calculate the machine code of s type
 int first_imm= stoi(convert_to_binary(imm,12).substr(0,5));
 int second_imm= stoi(convert_to_binary(imm,12).substr(5,7));
 int machine_code = (first_imm << 25) + (rs2 << 20) + (rs1 << 15) + (funct3 << 12) + (second_imm << 7) + opcode;
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