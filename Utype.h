#ifndef UTYPE_H
#define UTYPE_H
#include "global.h"
class Utype
{
    public:
        static void LUI(int rd, int imm);
        static void AUIPC(int rd, int imm);
};

#endif