#include "Jtype.h"

void Jtype::JAL(int rd, int imm)
{
    // jal rd, imm
    registers[rd] = PC + 4;
    PC = PC + imm;
}