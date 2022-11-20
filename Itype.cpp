#pragma once
#ifndef ITYPE_CPP
#define ITYPE_CPP
#include "global.h"
#include <iostream>
using namespace std;

class Itype
{
public:
    static void JALR(int rd, int rs1, int imm);
    static void LB(int rd, int rs1, int imm);
    static void LH(int rd, int rs1, int imm);
    static void LW(int rd, int rs1, int imm);
    static void LBU(int rd, int rs1, int imm);
    static void LHU(int rd, int rs1, int imm);
    static void ADDI(int rd, int rs1, int imm);
    static void SLTI(int rd, int rs1, int imm);
    static void SLTIU(int rd, int rs1, int imm);
    static void XORI(int rd, int rs1, int imm);
    static void ORI(int rd, int rs1, int imm);
    static void ANDI(int rd, int rs1, int imm);
    static void SLLI(int rd, int rs1, int imm);
    static void SRLI(int rd, int rs1, int imm);
    static void SRAI(int rd, int rs1, int imm);
    static void print_Itype_machine_code(int opcode, int rd, int funct3, int rs1, int imm);
};

void Itype::JALR(int rd, int rs1, int imm)
{
    // jalr rd, imm(rs1)
    PC = registers[rs1] + imm;
    update_register(rd, PC+4);
}

void Itype::LH(int rd, int rs1, int imm)
{
    // lh rd, imm(rs1)
    if(memory.find(registers[rs1] + imm)!=memory.end())
    {
        int temp = (char)memory[registers[rs1] + imm];
        char temp2 = (char)memory[registers[rs1] + imm + 1];
        short int temp3 = (temp << 8) | temp2;
        update_register(rd, temp3);
    }
 
    else
        update_register(rd, 0);
    PC += 4;
}

void Itype::LB(int rd, int rs1, int imm)
{
    // lb rd, imm(rs1)
    if(memory.find(registers[rs1] + imm)!=memory.end())
        update_register(rd, (char)memory[registers[rs1] + imm]);
    else
        update_register(rd, 0);
    PC += 4;
}

void Itype::LW(int rd, int rs1, int imm)
{
    // lw rd, imm(rs1)
    if(memory.find(registers[rs1] + imm)!=memory.end())
    {
        int temp = (char)memory[registers[rs1] + imm];
        char temp2 = (char)memory[registers[rs1] + imm + 1];
        short int temp3 = (temp << 8) | temp2;
        int temp4 = (char)memory[registers[rs1] + imm];
        char temp5 = (char)memory[registers[rs1] + imm + 1];
        short int temp6 = (temp4 << 8) | temp5;
        int temp7 = (temp3) | temp6;       
        update_register(rd, temp7);
    }
    else
        update_register(rd, 0);
    PC += 4;
}

void Itype::LBU(int rd, int rs1, int imm)
{
    // lbu rd, imm(rs1)
    if(memory.find(registers[rs1] + imm)!=memory.end())
        update_register(rd, (unsigned char)memory[registers[rs1] + imm]);
    else
        update_register(rd, 0);
    PC += 4;
}

void Itype::LHU(int rd, int rs1, int imm)
{
    // lh rd, imm(rs1)
    if(memory.find(registers[rs1] + imm)!=memory.end())
    {
        int temp = (unsigned char)memory[registers[rs1] + imm];
        unsigned char temp2 = (unsigned char)memory[registers[rs1] + imm + 1];
        unsigned short int temp3 = (temp << 8) | temp2;
        update_register(rd, temp3);
    }
    else
        update_register(rd, 0);
    PC += 4;
}

void Itype::ADDI(int rd, int rs1, int imm)
{
    // addi rd, rs1, imm
    update_register(rd, registers[rs1] + imm);
    PC += 4;
}

void Itype::SLTI(int rd, int rs1, int imm)
{
    // slti rd, rs1, imm
    if(registers[rs1] < imm)
        update_register(rd, 1);
    else
        update_register(rd, 0);
    PC += 4;
}

void Itype::SLTIU(int rd, int rs1, int imm)
{
    // sltiu rd, rs1, imm
    if((unsigned int)registers[rs1] < (unsigned int)imm)
        update_register(rd, 1);
    else
        update_register(rd, 0);
    PC += 4;
}

void Itype::XORI(int rd, int rs1, int imm)
{
    // xori rd, rs1, imm
    update_register(rd, registers[rs1] ^ imm);
    PC += 4;
}

void Itype::ORI(int rd, int rs1, int imm)
{
    // ori rd, rs1, imm
    update_register(rd, registers[rs1] | imm);
    PC += 4;
}

void Itype::ANDI(int rd, int rs1, int imm)
{
    // andi rd, rs1, imm
    update_register(rd, registers[rs1] & imm);
    PC += 4;
}

void Itype::SLLI(int rd, int rs1, int imm)
{
    // slli rd, rs1, imm
    update_register(rd, registers[rs1] << imm);
    PC += 4;
}

void Itype::SRLI(int rd, int rs1, int imm)
{
    // srli rd, rs1, imm
    update_register(rd, (unsigned int)registers[rs1] >> imm);
    PC += 4;
}

void Itype::SRAI(int rd, int rs1, int imm)
{
    // srai rd, rs1, imm
    update_register(rd, registers[rs1] >> imm);
    PC += 4;
}

void Itype:: print_Itype_machine_code(int opcode, int rd, int funct3, int rs1, int imm)
{
    int machine_code = (imm<<20) + (rs1<<15) + (funct3<<12) + (rd<<7) + opcode;
    
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