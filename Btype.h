#ifndef BTYPE_H
#define BTYPE_H

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
};

#endif