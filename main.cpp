#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <bits/stdc++.h>
#include "global.h" 
#include "Btype.cpp"
#include "Itype.cpp"
#include "Jtype.cpp"
#include "Rtype.cpp"
#include "Stype.cpp"
#include "Utype.cpp"

using namespace std;

// function definitions 
void load_memory(string);
void load_code(string, int);
void parse_code(int);

int main()
{  
    string choice;
    int pc_start;
    cout<<"Welcome to RISC-V Simulator"<<endl;

    // loading code 
    cout<<"Please input code filename with full absolute path: ";
    cin>>choice;
    cout<<"Please input Program Start Address: ";
    cin>>pc_start;
    PC = pc_start;
    load_code(choice,pc_start);
    for (auto i : instructions)
        cout << i.first << " -> " << i.second << endl;

    // loading data to memory
    cout<<"Do you like to load data into memory from file? (y or n): ";
    cin>>choice;
    if(choice=="y")
    {
        cout<<"Please input filename with full absolute path: ";
        cin>>choice;
        load_memory(choice);
        for (auto i : memory)
            cout << i.first << " -> " << i.second<< endl;
    }

    // initializing registers to zeros
    for(int i=0; i<32; i++)
        registers[i] = 0;

    // parse code
    while(instructions.find(PC)!=instructions.end())
    {
        parse_code(PC);
        print_updates();
    }
}

void load_memory(string file)
{
    ifstream memory_file;
    string line, key, value;
    memory_file.open(file);
    if ( memory_file.is_open() ) {
        while ( memory_file ) {
            memory_file>>key; memory_file>>value;
            memory[stoi(key)] = stoi(value);
        }
    } else {
        cout<<"Error: Memory File couldn't be opened."<<endl;
    }
}

void load_code(string file, int start_pos)
{
    ifstream code_file;
    string line;
    code_file.open(file);
    if ( code_file.is_open() ) {
        // read line by line from file
        while ( getline(code_file, line) ) {
            if (line.find(':') != string::npos)
            {
                // if line contains label
                string label = line.substr(0, line.find(':'));
                labels.insert(pair<string, int>(label, start_pos));
                line = line.substr(line.find(':')+1);
                if(line.find_first_not_of(' ') != std::string::npos)
                {
                    instructions.insert(pair<int, string>(start_pos, line));
                    start_pos += 4;
                }
            }
            else
            {
                instructions.insert(pair<int, string>(start_pos, line));
                start_pos += 4;
            }
        }
    } else {
        cout<<"Error: Code File couldn't be opened."<<endl;
    }
}  

void parse_code(int address) 
{
    string line = instructions[address];
    cout<<"Running: "<<line<<endl;
    string opcode = line.substr(0, line.find(' '));
    transform(opcode.begin(), opcode.end(), opcode.begin(), ::tolower);
    line = line.substr(line.find(' ')+1);
    if(opcode=="add")
    {
        int rs1, rs2, rd;
        rd = parse_register(line.substr(0, line.find(',')));
        line = line.substr(line.find(',')+1);
        rs1 = parse_register(line.substr(0, line.find(',')));
        line = line.substr(line.find(',')+1);
        rs2 = parse_register(line);
        Rtype::ADD(rd, rs1, rs2);
    }
    else if (opcode == "sub")
    {
        int rs1, rs2, rd;
        rd = parse_register(line.substr(0, line.find(',')));
        line = line.substr(line.find(',')+1);
        rs1 = parse_register(line.substr(0, line.find(',')));
        line = line.substr(line.find(',')+1);
        rs2 = parse_register(line);
        Rtype::SUB(rd, rs1, rs2);
    } 
    else if (opcode == "sll")
    {
        int rs1, rs2, rd;
        rd = parse_register(line.substr(0, line.find(',')));
        line = line.substr(line.find(',')+1);
        rs1 = parse_register(line.substr(0, line.find(',')));
        line = line.substr(line.find(',')+1);
        rs2 = parse_register(line);
        Rtype::SLL(rd, rs1, rs2);
    }
    else if (opcode == "slt")
    {
        int rs1, rs2, rd;
        rd = parse_register(line.substr(0, line.find(',')));
        line = line.substr(line.find(',')+1);
        rs1 = parse_register(line.substr(0, line.find(',')));
        line = line.substr(line.find(',')+1);
        rs2 = parse_register(line.substr(0, line.find(';')));
        Rtype::SLT(rd, rs1, rs2);
    }
    else if (opcode == "sltu")
    {
        int rs1, rs2, rd;
        rd = parse_register(line.substr(0, line.find(',')));
        line = line.substr(line.find(',')+1);
        rs1 = parse_register(line.substr(0, line.find(',')));
        line = line.substr(line.find(',')+1);
        rs2 = parse_register(line);
        Rtype::SLTU(rd, rs1, rs2);
    }
    else if (opcode == "xor")
    {
        int rs1, rs2, rd;
        rd = parse_register(line.substr(0, line.find(',')));
        line = line.substr(line.find(',')+1);
        rs1 = parse_register(line.substr(0, line.find(',')));
        line = line.substr(line.find(',')+1);
        rs2 = parse_register(line);
        Rtype::XOR(rd, rs1, rs2);
    }
    else if (opcode == "srl")
    {
        int rs1, rs2, rd;
        rd = parse_register(line.substr(0, line.find(',')));
        line = line.substr(line.find(',')+1);
        rs1 = parse_register(line.substr(0, line.find(',')));
        line = line.substr(line.find(',')+1);
        rs2 = parse_register(line);
        Rtype::SRL(rd, rs1, rs2);
    }
    else if (opcode == "sra")
    {
        int rs1, rs2, rd;
        rd = parse_register(line.substr(0, line.find(',')));
        line = line.substr(line.find(',')+1);
        rs1 = parse_register(line.substr(0, line.find(',')));
        line = line.substr(line.find(',')+1);
        rs2 = parse_register(line);
        Rtype::SRA(rd, rs1, rs2);
    }
    else if (opcode == "or")
    {
        int rs1, rs2, rd;
        rd = parse_register(line.substr(0, line.find(',')));
        line = line.substr(line.find(',')+1);
        rs1 = parse_register(line.substr(0, line.find(',')));
        line = line.substr(line.find(',')+1);
        rs2 = parse_register(line);
        Rtype::OR(rd, rs1, rs2);
    }
    else if (opcode == "and")
    {
        int rs1, rs2, rd;
        rd = parse_register(line.substr(0, line.find(',')));
        line = line.substr(line.find(',')+1);
        rs1 = parse_register(line.substr(0, line.find(',')));
        line = line.substr(line.find(',')+1);
        rs2 = parse_register(line);
        Rtype::AND(rd, rs1, rs2);
    }
    else if (opcode == "addi")
    {
        int rs1, rd;
        int imm;
        rd = parse_register(line.substr(0, line.find(',')));
        line = line.substr(line.find(',')+1);
        rs1 = parse_register(line.substr(0, line.find(',')));
        line = line.substr(line.find(',')+1);
        imm = stoi(line);
        Itype::ADDI(rd, rs1, imm);
    }
    else if (opcode == "slti")
    {
        int rs1, rd;
        int imm;
        rd = parse_register(line.substr(0, line.find(',')));
        line = line.substr(line.find(',')+1);
        rs1 = parse_register(line.substr(0, line.find(',')));
        line = line.substr(line.find(',')+1);
        imm = stoi(line);
        Itype::SLTI(rd, rs1, imm);
    } 
    else if (opcode == "sltiu")
    {
        int rs1, rd;
        int imm;
        rd = parse_register(line.substr(0, line.find(',')));
        line = line.substr(line.find(',')+1);
        rs1 = parse_register(line.substr(0, line.find(',')));
        line = line.substr(line.find(',')+1);
        imm = stoi(line);
        Itype::SLTIU(rd, rs1, imm);
    } 
    else if (opcode == "xori")
    {
        int rs1, rd;
        int imm;
        rd = parse_register(line.substr(0, line.find(',')));
        line = line.substr(line.find(',')+1);
        rs1 = parse_register(line.substr(0, line.find(',')));
        line = line.substr(line.find(',')+1);
        imm = stoi(line);
        Itype::XORI(rd, rs1, imm);
    } 
    else if (opcode == "ori")
    {
        int rs1, rd;
        int imm;
        rd = parse_register(line.substr(0, line.find(',')));
        line = line.substr(line.find(',')+1);
        rs1 = parse_register(line.substr(0, line.find(',')));
        line = line.substr(line.find(',')+1);
        imm = stoi(line);
        Itype::ORI(rd, rs1, imm);
    } 
    else if (opcode == "andi")
    {
        int rs1, rd;
        int imm;
        rd = parse_register(line.substr(0, line.find(',')));
        line = line.substr(line.find(',')+1);
        rs1 = parse_register(line.substr(0, line.find(',')));
        line = line.substr(line.find(',')+1);
        imm = stoi(line);
        Itype::ANDI(rd, rs1, imm);
    } 
    else if (opcode == "slli")
    {
        int rs1, rd;
        int imm;
        rd = parse_register(line.substr(0, line.find(',')));
        line = line.substr(line.find(',')+1);
        rs1 = parse_register(line.substr(0, line.find(',')));
        line = line.substr(line.find(',')+1);
        imm = stoi(line);
        Itype::SLLI(rd, rs1, imm);
    } 
    else if (opcode == "srli")
    {
        int rs1, rd;
        int imm;
        rd = parse_register(line.substr(0, line.find(',')));
        line = line.substr(line.find(',')+1);
        rs1 = parse_register(line.substr(0, line.find(',')));
        line = line.substr(line.find(',')+1);
        imm = stoi(line);
        Itype::SRLI(rd, rs1, imm);
    } 
    else if (opcode == "srai")
    {
        int rs1, rd;
        int imm;
        rd = parse_register(line.substr(0, line.find(',')));
        line = line.substr(line.find(',')+1);
        rs1 = parse_register(line.substr(0, line.find(',')));
        line = line.substr(line.find(',')+1);
        imm = stoi(line);
        Itype::SRAI(rd, rs1, imm);
    } 
}        