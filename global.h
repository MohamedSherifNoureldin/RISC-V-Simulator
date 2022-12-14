#pragma once
#include <string>
#include <unordered_map>
#include <map>
#include <iostream>
#include <iomanip>
#include <bitset>

using namespace std;

int registers[32];
map <int, char> memory;
unordered_map <string, int> conventional_registers; 
unordered_map <string, int> labels;
map <int, string> instructions;
int PC;

string convert_to_binary(int n, int bits)
{
    string binary;
    if(bits==8)
    {
        binary = bitset<8>(n).to_string(); //to binary
    } else {
        binary = bitset<32>(n).to_string(); //to binary
    }
    return binary;
}

string convert_to_hex(int n, int bits)
{
    stringstream stream;
    stream << "0x" << setfill('0') << setw(bits/4) << hex << n;
    string s(stream.str());
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

void print_registers_decimal()
{
    for(int i=0; i<32; i++)
    {
        cout<<"x"<<i<<" = "<<registers[i];
        if(i<31)
            cout<<", ";
    }
}

void print_memory_decimal()
{
    for(auto i: memory)
    {
        cout<<i.first<<" = "<<(int)(i.second)<<", "<<endl;
    }
}

void print_updates_decimal()
{
    cout << "Registers: " << endl;
    cout<<"PC = "<<PC<<endl;
    print_registers_decimal();
    cout<<endl;
    cout<<"Memory: "<<endl;
    print_memory_decimal();
}

void print_registers_binary()
{
    for(int i=0; i<32; i++)
    {
        cout<<"x"<<i<<" = "<<convert_to_binary(registers[i], 32);
        if(i<31)
            cout<<", ";
    }
    cout<<endl;
}

void print_memory_binary()
{
    for(auto i: memory)
    {
        cout<<i.first<<" = "<<convert_to_binary((int)(i.second), 8)<<", "<<endl;
    }
}

void print_updates_binary()
{
    cout << "Registers: " << endl;
    cout<<"PC = "<<convert_to_binary(PC,32)<<endl;
    print_registers_binary();
    cout<<"Memory: "<<endl;
    print_memory_binary();
}

void print_registers_hex()
{
    for(int i=0; i<32; i++)
    {
        cout<<"x"<<i<<" = "<<convert_to_hex(registers[i], 32);
        if(i<31)
            cout<<", ";
    }
    cout<<endl;
}

void print_memory_hex()
{
    for(auto i: memory)
    {
        cout<<i.first<<" = "<<convert_to_hex((int)(i.second), 8)<<", "<<endl;
    }
}

void print_updates_hex()
{
    cout << "Registers: " << endl;
    cout<<"PC = "<<convert_to_hex(PC, 32)<<endl;
    print_registers_hex();
    cout<<"Memory: "<<endl;
    print_memory_hex();
}

void print_updates()
{
    cout<<"Decimal: "<<endl;
    print_updates_decimal();
    cout<<endl;
    cout<<"Binary: "<<endl;
    print_updates_binary();
    cout<<endl;
    cout<<"Hex: "<<endl;
    print_updates_hex();
}

int find_first_alphanum(string s)
{
    for(int i=0; i<s.length(); i++)
    {
        if(isalnum(s[i]))
            return i;
    }
    return -1;
}

int find_last_alphanum(string s)
{
    for(int i=s.length()-1; i>=0; i--)
    {
        if(isalnum(s[i]))
            return i;
    }
    return -1;
}

void update_register(int dest_reg, int value)
{
    if(dest_reg!=0)
        registers[dest_reg] = value;
    else
    {
        cout<<"Warning: trying to update x0"<<endl;
    }
}