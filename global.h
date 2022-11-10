#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <stdlib.h>
using namespace std;

string registers[32]; 
unordered_map<string, string> memory;
unordered_map <string, int> conventional_registers; 
void init_conventional_registers(){
    conventional_registers["zero"]= 0;
    conventional_registers ["ra"]= 1;
    conventional_registers ["sp"]= 2; 
    conventional_registers ["gp"]= 3;
    conventional_registers ["tp"]= 4;
    conventional_registers ["t0"]= 5;
    conventional_registers ["t1"]= 6;
    conventional_registers ["t2"]= 7;
    conventional_registers ["s0"]= 8;
    conventional_registers ["s1"]= 9;
    conventional_registers ["a0"]= 10;
    conventional_registers ["a1"]= 11;
    conventional_registers ["a2"]= 12;
    conventional_registers ["a3"]= 13;
    conventional_registers ["a4"]= 14;
    conventional_registers ["a5"]= 15;
    conventional_registers ["a6"]= 16;
    conventional_registers ["a7"]= 17;
    conventional_registers ["s2"]= 18;
    conventional_registers ["s3"]= 19;
    conventional_registers ["s4"]= 20;
    conventional_registers ["s5"]= 21;
    conventional_registers ["s6"]= 22;
    conventional_registers ["s7"]= 23;
    conventional_registers ["s8"]= 24;
    conventional_registers ["s9"]= 25;
    conventional_registers ["s10"]= 26;
    conventional_registers ["s11"]=27;
    conventional_registers ["t3"]= 28;
    conventional_registers ["t4"]= 29;
    conventional_registers ["t5"]= 30;
    conventional_registers ["t6"]= 31;

   
};
int convert_register (string A) // function that takes the name of the register and finds out if it is named conventianlly, if yes return the key to the number ot the register, if no return the number of the register
 
{
    if (conventional_registers.find(A)!=conventional_registers.end())
    {
        return conventional_registers[A];
    }
    else
    {

        string index_string="";
       
        for ( int i= 0; i< A.length(); i++)
        {
            if (isdigit(A[i]))
            {
                index_string+=A[i];
               
            }
        }
    return stoi (index_string);
        }

        }