# include "Btype.h"
# include "global.h"
#include <string>
using namespace std;

void Btype::BEQ(int rs1, int rs2, int imm)
{
    if(registers[rs1]==registers[rs2])
        PC = PC + imm;
}

void Btype::BNE(int rs1, int rs2, int imm)
{
    if(registers[rs1]!=registers[rs2])
        PC = PC + imm;
}

void Btype::BLT(int rs1, int rs2, int imm)
{
    if(registers[rs1]<registers[rs2])
        PC = PC + imm;
}

void Btype::BGE(int rs1, int rs2, int imm)
{
    if(registers[rs1]>=registers[rs2])
        PC = PC + imm;
}

void Btype::BLTU(int rs1, int rs2, int imm)
{
    uint32_t temp1 = registers[rs1];
    uint32_t temp2 = registers[rs2]; 
    if (temp1 < temp2)
        PC = PC + imm;
}

void Btype::BGEU(int rs1, int rs2, int imm)
{
    uint32_t temp1 = registers[rs1];
    uint32_t temp2 = registers[rs2];    
    if (temp1 >= temp2)
        PC = PC + imm;
}

// Path: Btype.h