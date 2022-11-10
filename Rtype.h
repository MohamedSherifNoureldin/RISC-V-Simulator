#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <stdlib.h>
using namespace std;
//#include "global.h"


class Rtype{
    private :
    string dest_register;
    string src_register1;
    string src_register2;
   // string funct3;
    //string funct7;
    //string opcode;
    //string instruction;
    public :
    //sets
    Rtype ();
   /* Rtype(string src_register1, string src_register2, string dest_register);
    void set_dest_register(string);
    void set_src_register1(string);
    void set_src_register2(string);
   // void set_funct3(string);
    //void set_funct7(string);
    //void set_opcode(string);
    //void set_instruction(string);
  

// gets
    string get_dest_register();
    string get_src_register1();
    string get_src_register2();
   // string get_funct3();
    //string get_funct7();
    //string get_opcode();
    //string get_instruction();

    void add();
    /*void sub();
    void sll();
    void slt();
    void sltu();
    void xor();
    void srl();
    void sra();
    void or();
    void and();


    void print();
    void execute();*/
};

