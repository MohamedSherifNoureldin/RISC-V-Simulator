#include "Rtype.h"
Rtype:: Rtype () {
    dest_register = "00000";
    src_register1 = "00000";
    src_register2 = "00000";
    //funct3 = "000";
    //funct7 = "0000000";
    //opcode = "0110011";
    //instruction = "00000000000000000000000000000000";
}
/*Rtype:: Rtype (string src_register1, string src_register2, string dest_register){
    this->set_src_register1( src_register1);
    this->set_src_register2( src_register2);
    this->set_dest_register( dest_register);
  }

void Rtype::set_dest_register(string dest_register){
    this->dest_register = dest_register;
}
void Rtype::set_src_register1(string src_register1){
    this->src_register1 = src_register1;
}
void Rtype::set_src_register2(string src_register2){
    this->src_register2 = src_register2;
}



string Rtype:: get_dest_register(){
    return this->dest_register;
}
string Rtype:: get_src_register1(){
    return this->src_register1;
}
string Rtype:: get_src_register2(){
    return this->src_register2;
}

void Rtype:: add (){
   string x=registers[ convert_register (this->src_register1)];
   int sorce_1= stoi(x);
    string y=registers[ convert_register (this->src_register2)];
    int sorce_2= stoi(y);
    int result= sorce_1 + sorce_2;
    registers[ convert_register (this->dest_register)]= to_string(result);
    cout <<     "the result is" << result << "in register "<< convert_register (this->dest_register) << endl;
}*/
