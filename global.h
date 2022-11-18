#pragma once
#include <string>
#include <unordered_map>
#include <map>
#include <iostream>
using namespace std;

int registers[32];
map <int, char> memory;
unordered_map <string, int> conventional_registers; 
unordered_map <string, int> labels;
map <int, string> instructions;
map <int, string> instructions_code;
int PC;
string convert_to_binary(int n, int bits){
    string s = "";
    while(n){
        s = (n%2==0 ? "0" : "1") + s;
        n /= 2;
    }
    while(s.length() < bits)
        s = "0" + s;
    return s;
}
void init_conventional_register() 
{
    conventional_registers["zero"]= 0;
    conventional_registers ["ra"] = 1;
    conventional_registers ["sp"] = 2; 
    conventional_registers ["gp"] = 3;
    conventional_registers ["tp"] = 4;
    conventional_registers ["t0"] = 5;
    conventional_registers ["t1"] = 6;
    conventional_registers ["t2"] = 7;
    conventional_registers ["s0"] = 8;
    conventional_registers ["s1"] = 9;
    conventional_registers ["a0"] = 10;
    conventional_registers ["a1"] = 11;
    conventional_registers ["a2"] = 12;
    conventional_registers ["a3"] = 13;
    conventional_registers ["a4"] = 14;
    conventional_registers ["a5"] = 15;
    conventional_registers ["a6"] = 16;
    conventional_registers ["a7"] = 17;
    conventional_registers ["s2"] = 18;
    conventional_registers ["s3"] = 19;
    conventional_registers ["s4"] = 20;
    conventional_registers ["s5"] = 21;
    conventional_registers ["s6"] = 22;
    conventional_registers ["s7"] = 23;
    conventional_registers ["s8"] = 24;
    conventional_registers ["s9"] = 25;
    conventional_registers ["s10"] = 26;
    conventional_registers ["s11"] = 27;
    conventional_registers ["t3"] = 28;
    conventional_registers ["t4"] = 29;
    conventional_registers ["t5"] = 30;
    conventional_registers ["t6"] = 31;
}

int parse_register(string reg)
{
    if(reg.find('x') != std::string::npos) {
        int i = reg.find('x');
        reg = reg.substr(i+1);
        return stoi(reg);
    }
    else if (conventional_registers.find(reg)!=conventional_registers.end()) {
        return conventional_registers[reg];
    } else {
        return -1;
    }
}

void print_registers()
{
    for(int i=0; i<32; i++)
    {
        cout<<"x"<<i<<" = "<<registers[i];
        if(i<31)
            cout<<", ";
    }
    cout<<endl;
}

void print_memory()
{
    for(auto i: memory)
    {
        cout<<i.first<<" = "<<(int)(i.second)<<", "<<endl;
    }
}

void print_updates()
{
    cout<<"PC = "<<PC<<endl;
    print_registers();
    print_memory();
}