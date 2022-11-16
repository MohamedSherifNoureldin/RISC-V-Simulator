#include "global.h"

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
};