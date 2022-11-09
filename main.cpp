#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <sstream>
using namespace std;

string registers[32];
unordered_map<string, string> memory;
unordered_map <string, int> conventional_registers;

void load_memory(string);
void init_conventional_registers()
void convert_register (string A, string B);

int main()
{
    string choice;
    cout<<"Welcome to RISC-V Simulator"<<endl;

    // loading data to memory
    cout<<"Do you like to load data into memory from file? (y or n): ";
    cin>>choice;
    if(choice=="y")
    {
        cout<<"Please input filename with full absolute path: ";
        cin>>choice;
        load_memory(choice);
        for (auto i : memory)
            cout << i.first << "->" << i.second<< endl;
    }

    // initializing registers to zeros
    for(int i=0; i<32; i++)
        registers[i] = "00000000000000000000000000000000";
}

void load_memory(string file)
{
    ifstream memory_file;
    string line, key, value;
    memory_file.open(file);
    if ( memory_file.is_open() ) {
        while ( memory_file ) {
            memory_file>>key; memory_file>>value;
            memory[key] = value;
        }
    } else {
        cout<<"Error: Memory File couldn't be opened."<<endl;
    }
}
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
    conventional_registers ["s11"]= 27;
    conventional_registers ["t3"]= 28;
    conventional_registers ["t4"]= 29;
    conventional_registers ["t5"]= 30;
    conventional_registers ["t6"]= 31;

   
};
int convert_register (string A)// function that takes the name of the register and finds out if it is named conventianlly, if yes return the key to the number ot the register
{


}