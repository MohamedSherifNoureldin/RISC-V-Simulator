#ifndef STYPE_H
#define STYPE_H
#include "global.h"
using namespace std;

class Stype
{
    static void SB(int rs1, int rs2, int imm);
    static void SH(int rs1, int rs2, int imm);    
    static void SW(int rs1, int rs2, int imm);
};

#endif