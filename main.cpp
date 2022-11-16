#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include "global.h"
using namespace std;

// function definitions 
void load_memory(string);

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