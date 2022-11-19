#pragma once
#ifndef BTYPE_CPP
#define BTYPE_CPP

#include "global.h"
#include <string>
using namespace std;

class Btype
{
public:
    static void BEQ(int rs1, int rs2, int imm);
    static void BNE(int rs1, int rs2, int imm);
    static void BLT(int rs1, int rs2, int imm);
    static void BGE(int rs1, int rs2, int imm);
    static void BLTU(int rs1, int rs2, int imm);
    static void BGEU(int rs1, int rs2, int imm);
    static void print_Btype_machine_code(int opcode, int rs1, int rs2, int funct3, int imm);
};

void Btype::BEQ(int rs1, int rs2, int imm)
{
    // beq rs1, rs2, imm
    if(registers[rs1]==registers[rs2])
        PC = PC + imm;
    else
        PC += 4;
}

void Btype::BNE(int rs1, int rs2, int imm)
{
    //bne rs1, rs2, imm
    if(registers[rs1]!=registers[rs2])
        PC = PC + imm;
    else
        PC += 4;
}

void Btype::BLT(int rs1, int rs2, int imm)
{
    //blt rs1, rs2, imm
    if(registers[rs1]<registers[rs2])
        PC = PC + imm;
    else
        PC += 4;
}

void Btype::BGE(int rs1, int rs2, int imm)
{
    //bge rs1, rs2, imm
    if(registers[rs1]>=registers[rs2])
        PC = PC + imm;
    else
        PC += 4;
}

void Btype::BLTU(int rs1, int rs2, int imm)
{
    //bltu rs1, rs2, imm
    uint32_t temp1 = registers[rs1];
    uint32_t temp2 = registers[rs2]; 
    if (temp1 < temp2)
        PC = PC + imm;
    else
        PC += 4;
}

void Btype::BGEU(int rs1, int rs2, int imm)
{
    //bgeu rs1, rs2, imm
    uint32_t temp1 = registers[rs1];
    uint32_t temp2 = registers[rs2];    
    if (temp1 >= temp2)
        PC = PC + imm;
    else
        PC += 4;
}
void Btype::print_Btype_machine_code(int opcode, int rs1, int rs2, int funct3, int imm)
{
    int first_imm= stoi(convert_to_binary(imm,12).substr(0,1));
    int second_imm= stoi(convert_to_binary(imm,12).substr(5,6));
    int third_imm= stoi(convert_to_binary(imm,12).substr(1,4));
    int fourth_imm= stoi(convert_to_binary(imm,12).substr(11,1));
    int machine_code = (first_imm<<31) | (second_imm<<25) | (third_imm<<8) | (rs2<<20) | (rs1<<15) | (funct3<<12) | (fourth_imm<<7) | opcode;

    cout<<"Machine code: "<<convert_to_binary(machine_code,32)<<endl;
    
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