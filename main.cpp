
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <algorithm>
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
    init_conventional_register();
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
            // check for comments & remove them
            if (line.find('#') != std::string::npos) {
                int i = line.find('#');
                line = line.substr(0, i);
            }
            // check for empty lines (after removing comments)
            if(line.find_first_not_of(' ') != std::string::npos) 
            {
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
        rd = parse_register(line.substr(line.find_first_not_of(' '), line.find(',')));
        line = line.substr(line.find(',')+1);
        rs1 = parse_register(line.substr(line.find_first_not_of(' '), line.find(',')-1));
        line = line.substr(line.find(',')+1);
        string temp = "";
        for(int i=0; i<line.length(); i++)
            if(isalnum(line[i]))
                temp += line[i];
        rs2 = parse_register(temp);
        cout<<"add "<<rd<<", "<<rs1<<", "<<rs2<<endl;
        Rtype::ADD(rd, rs1, rs2);
        Rtype:: print_Rtype_machine_code (51, rd, 0, rs1, rs2, 0);
    }
    else if (opcode == "sub")
    {
        int rs1, rs2, rd;
        rd = parse_register(line.substr(line.find_first_not_of(' '), line.find(',')));
        line = line.substr(line.find(',')+1);
        rs1 = parse_register(line.substr(line.find_first_not_of(' '), line.find(',')-1));
        line = line.substr(line.find(',')+1);
        string temp = "";
        for(int i=0; i<line.length(); i++)
            if(isalnum(line[i]))
                temp += line[i];
        rs2 = parse_register(temp);        
        Rtype::SUB(rd, rs1, rs2);
        Rtype:: print_Rtype_machine_code (51, rd, 0, rs1, rs2, 32);
    } 
    else if (opcode == "sll")
    {
        int rs1, rs2, rd;
        rd = parse_register(line.substr(line.find_first_not_of(' '), line.find(',')));
        line = line.substr(line.find(',')+1);
        rs1 = parse_register(line.substr(line.find_first_not_of(' '), line.find(',')-1));
        line = line.substr(line.find(',')+1);
        string temp = "";
        for(int i=0; i<line.length(); i++)
            if(isalnum(line[i]))
                temp += line[i];
        rs2 = parse_register(temp);  
        Rtype::SLL(rd, rs1, rs2);
        Rtype:: print_Rtype_machine_code (51, rd, 1, rs1, rs2, 0);

    }
    else if (opcode == "slt")
    {
        int rs1, rs2, rd;
        rd = parse_register(line.substr(line.find_first_not_of(' '), line.find(',')));
        line = line.substr(line.find(',')+1);
        rs1 = parse_register(line.substr(line.find_first_not_of(' '), line.find(',')-1));
        line = line.substr(line.find(',')+1);
        string temp = "";
        for(int i=0; i<line.length(); i++){
            if(isalnum(line[i]))
                temp += line[i];}
        rs2 = parse_register(temp);  
        Rtype::SLT(rd, rs1, rs2);
        Rtype:: print_Rtype_machine_code (51, rd, 2, rs1, rs2, 0);
    }
    else if (opcode == "sltu")
    {
        int rs1, rs2, rd;
        rd = parse_register(line.substr(line.find_first_not_of(' '), line.find(',')));
        line = line.substr(line.find(',')+1);
        rs1 = parse_register(line.substr(line.find_first_not_of(' '), line.find(',')-1));
        line = line.substr(line.find(',')+1);
        string temp = "";
        for(int i=0; i<line.length(); i++)
            if(isalnum(line[i]))
                temp += line[i];
        rs2 = parse_register(temp);  
        Rtype::SLTU(rd, rs1, rs2);
        Rtype:: print_Rtype_machine_code (51, rd, 3, rs1, rs2, 0);
    }
    else if (opcode == "xor")
    {
        int rs1, rs2, rd;
        rd = parse_register(line.substr(line.find_first_not_of(' '), line.find(',')));
        line = line.substr(line.find(',')+1);
        rs1 = parse_register(line.substr(line.find_first_not_of(' '), line.find(',')-1));
        line = line.substr(line.find(',')+1);
        string temp = "";
        for(int i=0; i<line.length(); i++)
            if(isalnum(line[i]))
                temp += line[i];
        rs2 = parse_register(temp);  
        Rtype::XOR(rd, rs1, rs2);
        Rtype:: print_Rtype_machine_code (51, rd, 4, rs1, rs2, 0);
    }
    else if (opcode == "srl")
    {
        int rs1, rs2, rd;
        rd = parse_register(line.substr(line.find_first_not_of(' '), line.find(',')));
        line = line.substr(line.find(',')+1);
        rs1 = parse_register(line.substr(line.find_first_not_of(' '), line.find(',')-1));
        line = line.substr(line.find(',')+1);
        string temp = "";
        for(int i=0; i<line.length(); i++)
            if(isalnum(line[i]))
                temp += line[i];
        rs2 = parse_register(temp);  
        Rtype::SRL(rd, rs1, rs2);
        Rtype:: print_Rtype_machine_code (51, rd, 5, rs1, rs2, 0);
    }
    else if (opcode == "sra")
    {
        int rs1, rs2, rd;
        rd = parse_register(line.substr(line.find_first_not_of(' '), line.find(',')));
        line = line.substr(line.find(',')+1);
        rs1 = parse_register(line.substr(line.find_first_not_of(' '), line.find(',')-1));
        line = line.substr(line.find(',')+1);
        string temp = "";
        for(int i=0; i<line.length(); i++)
            if(isalnum(line[i]))
                temp += line[i];
        rs2 = parse_register(temp);  
        Rtype::SRA(rd, rs1, rs2);
        Rtype:: print_Rtype_machine_code (51, rd, 5, rs1, rs2, 32);
    }
    else if (opcode == "or")
    {
        int rs1, rs2, rd;
        rd = parse_register(line.substr(line.find_first_not_of(' '), line.find(',')));
        line = line.substr(line.find(',')+1);
        rs1 = parse_register(line.substr(line.find_first_not_of(' '), line.find(',')-1));
        line = line.substr(line.find(',')+1);
        string temp = "";
        for(int i=0; i<line.length(); i++)
            if(isalnum(line[i]))
                temp += line[i];
        rs2 = parse_register(temp);  
        Rtype::OR(rd, rs1, rs2);
        Rtype:: print_Rtype_machine_code (51, rd, 6, rs1, rs2, 0);
    }
    else if (opcode == "and")
    {
        int rs1, rs2, rd;
        rd = parse_register(line.substr(line.find_first_not_of(' '), line.find(',')));
        line = line.substr(line.find(',')+1);
        rs1 = parse_register(line.substr(line.find_first_not_of(' '), line.find(',')-1));
        line = line.substr(line.find(',')+1);
        string temp = "";
        for(int i=0; i<line.length(); i++)
            if(isalnum(line[i]))
                temp += line[i];
        rs2 = parse_register(temp);  
        Rtype::AND(rd, rs1, rs2);
        Rtype:: print_Rtype_machine_code (51, rd, 7, rs1, rs2, 0);
    }
    else if(opcode == "jalr")
    {
        //jalr rd, 0(rs1)
        int rs1, rd, imm;
        rd = parse_register(line.substr(line.find_first_not_of(' '), line.find(',')));
        line = line.substr(line.find(',')+1);
        imm = stoi(line.substr(line.find_first_not_of(' '), line.find('(')));
        line = line.substr(line.find('(')+1, line.find(')'));
        rs1 = parse_register(line);
        Itype::JALR(rd, rs1, imm);
        Itype::print_Itype_machine_code(103, rd, 0, rs1, imm);
    }
    else if(opcode == "lb")
    {
        int rs1, rd, imm;
        rd = parse_register(line.substr(line.find_first_not_of(' '), line.find(',')));
        line = line.substr(line.find(',')+1);
        imm = stoi(line.substr(line.find_first_not_of(' '), line.find('(')));
        line = line.substr(line.find('(')+1, line.find(')'));
        rs1 = parse_register(line);
        Itype::LB(rd, rs1, imm);
        Itype::print_Itype_machine_code(3, rd, 0, rs1, imm);
    }
    else if(opcode == "lh")
    {
        int rs1, rd, imm;
        rd = parse_register(line.substr(line.find_first_not_of(' '), line.find(',')));
        line = line.substr(line.find(',')+1);
        imm = stoi(line.substr(line.find_first_not_of(' '), line.find('(')));
        line = line.substr(line.find('(')+1, line.find(')'));
        rs1 = parse_register(line);
        Itype::LH(rd, rs1, imm);
        Itype::print_Itype_machine_code(3, rd, 1, rs1, imm);
    }
    else if(opcode == "lw")
    {
        int rs1, rd, imm;
        rd = parse_register(line.substr(line.find_first_not_of(' '), line.find(',')));
        line = line.substr(line.find(',')+1);
        imm = stoi(line.substr(line.find_first_not_of(' '), line.find('(')));
        line = line.substr(line.find('(')+1);
        line = line.substr(0, line.find(')')); // check this here
        rs1 = parse_register(line);
        Itype::LW(rd, rs1, imm);
        cout<<"lw "<<rd<<", "<<imm<<"("<<rs1<<")"<<endl;
        Itype::print_Itype_machine_code(3, rd, 2, rs1, imm);
    }
    else if(opcode == "lbu")
    {
        int rs1, rd, imm;
        rd = parse_register(line.substr(line.find_first_not_of(' '), line.find(',')));
        line = line.substr(line.find(',')+1);
        imm = stoi(line.substr(line.find_first_not_of(' '), line.find('(')));
        line = line.substr(line.find('(')+1, line.find(')'));
        rs1 = parse_register(line);
        Itype::LBU(rd, rs1, imm);

    }
    else if(opcode == "lhu")
    {
        int rs1, rd, imm;
        rd = parse_register(line.substr(line.find_first_not_of(' '), line.find(',')));
        line = line.substr(line.find(',')+1);
        imm = stoi(line.substr(line.find_first_not_of(' '), line.find('(')));
        line = line.substr(line.find('(')+1, line.find(')'));
        rs1 = parse_register(line);
        Itype::LHU(rd, rs1, imm);
        Itype:: print_Itype_machine_code (3, rd, 3, rs1, imm);

    }
    else if (opcode == "addi")
    {
        int rs1, rd;
        int imm;
        rd = parse_register(line.substr(line.find_first_not_of(' '), line.find(',')));
        line = line.substr(line.find(',')+1);
        rs1 = parse_register(line.substr(line.find_first_not_of(' '), line.find(',')-1));
        line = line.substr(line.find(',')+1);
        imm = stoi(line);
        cout<<"addi "<<rd<<", "<<rs1<<", "<<imm<<endl;
        Itype::ADDI(rd, rs1, imm);
        Itype::print_Itype_machine_code(19, rd, 0, rs1, imm);
    }
    else if (opcode == "slti")
    {
        int rs1, rd;
        int imm;
        rd = parse_register(line.substr(line.find_first_not_of(' '), line.find(',')));
        line = line.substr(line.find(',')+1);
        rs1 = parse_register(line.substr(line.find_first_not_of(' '), line.find(',')-1));
        line = line.substr(line.find(',')+1);
        imm = stoi(line);
        Itype::SLTI(rd, rs1, imm);
        Itype::print_Itype_machine_code(19, rd, 2, rs1, imm);
    } 
    else if (opcode == "sltiu")
    {
        int rs1, rd;
        int imm;
        rd = parse_register(line.substr(line.find_first_not_of(' '), line.find(',')));
        line = line.substr(line.find(',')+1);
        rs1 = parse_register(line.substr(line.find_first_not_of(' '), line.find(',')-1));
        line = line.substr(line.find(',')+1);
        imm = stoi(line);
        Itype::SLTIU(rd, rs1, imm);
        Itype::print_Itype_machine_code(19, rd, 3, rs1, imm);
    } 
    else if (opcode == "xori")
    {
        int rs1, rd;
        int imm;
        rd = parse_register(line.substr(line.find_first_not_of(' '), line.find(',')));
        line = line.substr(line.find(',')+1);
        rs1 = parse_register(line.substr(line.find_first_not_of(' '), line.find(',')-1));
        line = line.substr(line.find(',')+1);
        imm = stoi(line);
        Itype::XORI(rd, rs1, imm);
        Itype::print_Itype_machine_code(19, rd, 4, rs1, imm);
    } 
    else if (opcode == "ori")
    {
        int rs1, rd;
        int imm;
        rd = parse_register(line.substr(line.find_first_not_of(' '), line.find(',')));
        line = line.substr(line.find(',')+1);
        rs1 = parse_register(line.substr(line.find_first_not_of(' '), line.find(',')-1));
        line = line.substr(line.find(',')+1);
        imm = stoi(line);
        Itype::ORI(rd, rs1, imm);
        Itype::print_Itype_machine_code(19, rd, 6, rs1, imm);
    } 
    else if (opcode == "andi")
    {
        int rs1, rd;
        int imm;
        rd = parse_register(line.substr(line.find_first_not_of(' '), line.find(',')));
        line = line.substr(line.find(',')+1);
        rs1 = parse_register(line.substr(line.find_first_not_of(' '), line.find(',')-1));
        line = line.substr(line.find(',')+1);
        imm = stoi(line);
        Itype::ANDI(rd, rs1, imm);
        Itype::print_Itype_machine_code(19, rd, 7, rs1, imm);
    } 
    else if (opcode == "slli")
    {
        int rs1, rd;
        int imm;
        rd = parse_register(line.substr(line.find_first_not_of(' '), line.find(',')));
        line = line.substr(line.find(',')+1);
        rs1 = parse_register(line.substr(line.find_first_not_of(' '), line.find(',')-1));
        line = line.substr(line.find(',')+1);
        imm = stoi(line);
        Itype::SLLI(rd, rs1, imm);
        Itype::print_Itype_machine_code(19, rd, 1, rs1, imm);
    } 
    else if (opcode == "srli")
    {
        int rs1, rd;
        int imm;
        rd = parse_register(line.substr(line.find_first_not_of(' '), line.find(',')));
        line = line.substr(line.find(',')+1);
        rs1 = parse_register(line.substr(line.find_first_not_of(' '), line.find(',')-1));
        line = line.substr(line.find(',')+1);
        imm = stoi(line);
        Itype::SRLI(rd, rs1, imm);
        Itype::print_Itype_machine_code(19, rd, 5, rs1, imm);
    } 
    else if (opcode == "srai")
    {
        int rs1, rd;
        int imm;
        rd = parse_register(line.substr(line.find_first_not_of(' '), line.find(',')));
        line = line.substr(line.find(',')+1);
        rs1 = parse_register(line.substr(line.find_first_not_of(' '), line.find(',')-1));
        line = line.substr(line.find(',')+1);
        imm = stoi(line);
        Itype::SRAI(rd, rs1, imm);
        Itype::print_Itype_machine_code(19, rd, 5, rs1, imm);
    }
    else if (opcode == "sb")
    {
        int rs1, rs2;
        int imm;
        rs1 = parse_register(line.substr(line.find_first_not_of(' '), line.find(',')));
        line = line.substr(line.find(',')+1);
        imm = stoi(line.substr(0, line.find('(')));
        line = line.substr(line.find('(')+1);
        rs2 = parse_register(line.substr(line.find_first_not_of(' '), line.find(')')));
        Stype::SB(rs1, rs2, imm);
        Stype::print_Stype_machine_code(35, 0, rs1, rs2, imm);
    }
    else if (opcode == "sh")
    {
        int rs1, rs2;
        int imm;
        rs1 = parse_register(line.substr(line.find_first_not_of(' '), line.find(',')));
        line = line.substr(line.find(',')+1);
        imm = stoi(line.substr(line.find_first_not_of(' '), line.find('(')));
        line = line.substr(line.find('(')+1);
        rs2 = parse_register(line.substr(line.find_first_not_of(' '), line.find(')')));
        Stype::SH(rs1, rs2, imm);
        Stype::print_Stype_machine_code(35, 1, rs1, rs2, imm);
    }
    else if (opcode == "sw")
    {
        int rs1, rs2;
        int imm;
        rs1 = parse_register(line.substr(line.find_first_not_of(' '), line.find(',')));
        line = line.substr(line.find(',')+1);
        imm = stoi(line.substr(line.find_first_not_of(' '), line.find('(')));
        line = line.substr(line.find('(')+1);
        rs2 = parse_register(line.substr(line.find_first_not_of(' '), line.find(')')));
        Stype::SW(rs1, rs2, imm);
        Stype::print_Stype_machine_code(35, 2, rs1, rs2, imm);
    }
    else if (opcode == "lui")
    {
        int rd, imm;
        rd = parse_register(line.substr(line.find_first_not_of(' '), line.find(',')));
        line = line.substr(line.find(',')+1);
        imm = stoi(line);
        Utype::LUI(rd, imm);
        Utype::print_Utype_machine_code(55, rd, imm);
    }
    else if (opcode == "auipc")
    {
        int rd, imm;
        rd = parse_register(line.substr(line.find_first_not_of(' '), line.find(',')));
        line = line.substr(line.find(',')+1);
        imm = stoi(line);
        Utype::AUIPC(rd, imm);
        Utype::print_Utype_machine_code(23, rd, imm);
    }
    else if (opcode == "jal")
    {
        string label;
        int rd;
        int imm;
        rd = parse_register(line.substr(line.find_first_not_of(' '), line.find(',')));
        label = line.substr(line.find(',')+1);
        imm = labels[label] - PC;
        Jtype::JAL(rd, imm);
        Jtype::print_Jtype_machine_code(111, rd, imm);

     }
    else if (opcode == "jalr")
    {
        int rd, rs1; string label;
        int imm;
        rd = parse_register(line.substr(line.find_first_not_of(' '), line.find(',')));
        line = line.substr(line.find(',')+1);
        imm = stoi(line.substr(line.find_first_not_of(' '), line.find('(')));
        line = line.substr(line.find('(')+1);
        rs1 = parse_register(line.substr(line.find_first_not_of(' '), line.find(')')));
        Itype::JALR(rd, rs1, imm);
        Itype::print_Itype_machine_code(111, rd, 0, rs1, imm);
    }
    else if (opcode == "beq")
    {
        int rs1, rs2;
        string label;
        int imm;
        rs1 = parse_register(line.substr(line.find_first_not_of(' '), line.find(',')));
        line = line.substr(line.find(',')+1);
        rs2 = parse_register(line.substr(line.find_first_not_of(' '), line.find(',')));
        label =line.substr(line.find(',')+1);
        imm = labels[label] - PC;
        Btype::BEQ(rs1, rs2, imm);
        
    }
    else if (opcode == "bne")
    {
        int rs1, rs2;
        string label;
        int imm;
        rs1 = parse_register(line.substr(line.find_first_not_of(' '), line.find(',')));
        line = line.substr(line.find(',')+1);
        rs2 = parse_register(line.substr(line.find_first_not_of(' '), line.find(',')));
        label =line.substr(line.find(',')+1);
        imm = labels[label] - PC;
        Btype::BNE(rs1, rs2, imm);
    }
    else if (opcode == "blt")
    {
        int rs1, rs2;
        string label;
        int imm;
        rs1 = parse_register(line.substr(line.find_first_not_of(' '), line.find(',')));
        line = line.substr(line.find(',')+1);
        rs2 = parse_register(line.substr(line.find_first_not_of(' '), line.find(',')));
        label =line.substr(line.find(',')+1);
        imm = labels[label] - PC;
        Btype::BLT(rs1, rs2, imm);
    }
    else if (opcode == "bge")
    {
        int rs1, rs2;
        string label;
        int imm;
        rs1 = parse_register(line.substr(line.find_first_not_of(' '), line.find(',')));
        line = line.substr(line.find(',')+1);
        rs2 = parse_register(line.substr(line.find_first_not_of(' '), line.find(',')));
        label =line.substr(line.find(',')+1);
        imm = labels[label] - PC;
        Btype::BGE(rs1, rs2, imm);
    }
    else if (opcode == "bltu")
    {
        int rs1, rs2;
        string label;
        int imm;
        rs1 = parse_register(line.substr(line.find_first_not_of(' '), line.find(',')));
        line = line.substr(line.find(',')+1);
        rs2 = parse_register(line.substr(line.find_first_not_of(' '), line.find(',')));
        label =line.substr(line.find(',')+1);
        imm = labels[label] - PC;
        Btype::BLTU(rs1, rs2, imm);
    }
    else if (opcode == "bgeu")
    {
        int rs1, rs2;
        string label;
        int imm;
        rs1 = parse_register(line.substr(line.find_first_not_of(' '), line.find(',')));
        line = line.substr(line.find(',')+1);
        rs2 = parse_register(line.substr(line.find_first_not_of(' '), line.find(',')));
        label =line.substr(line.find(',')+1);
        imm = labels[label] - PC;
        Btype::BGEU(rs1, rs2, imm);
    }




}        
