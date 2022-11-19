#pragma once
#ifndef RTYPE_CPP
#define RTYPE_CPP

#include "global.h"

class Rtype
{
   public:
    int rd, rs1, rs2, funct3, funct7;
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
    static void print_Rtype_machine_code(int opcode, int rd, int funct3, int rs1, int rs2, int funct7);
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
void Rtype::print_Rtype_machine_code(int opcode, int rd, int funct3, int rs1, int rs2, int funct7)
{
    // to print the code of the R type instruction in binary
    //cout << convert_to_binary(funct7, 7) << " " << convert_to_binary(rs2, 5) << " " << convert_to_binary(rs1, 5) << " " << convert_to_binary(funct3, 3) << " " << convert_to_binary(rd, 5) << " " << convert_to_binary(opcode, 7) << endl;

       // to calculate the machine code of the R type instruction in decimal
    int machine_code = (funct7 << 25) + (rs2 << 20) + (rs1 << 15) + (funct3 << 12) + (rd << 7) + opcode;

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