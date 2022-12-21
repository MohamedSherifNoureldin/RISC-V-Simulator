# RISC-V RV32I Simulator
RISC-V RV32I Assembly Simulator is a C++ program that allows one to test and simulate assembly programs by showing the contents of registers along with the memory after each instruction execution. This program was written as a project for the Computer Organization and Assembly Language Programming course (CSCE2303). This readme file contains a short summary of the project and how to use it. For more details, please refer to the "Report.pdf" file.

## Features
- Simulate the RISC-V RV32I Assembly instructions
- Take initial memory values from a file
- Show the instruction being executed in machine code
- Show the values of the registers and memory after each instruction execution
- Output the values in Binary, Hex and Decimal

## Input
As the program runs, it prompts the user to provide the following:
- Code file path to be loaded and simulated
- Program selected starting address to load the instructions starting this address in memory
- Initial Memory file path. This file should contain the initial memory values to start with, where each line has a memory address in decimal separated with a " " (space) from the actual memory content which is also given as an integer in decimal.

## Output
After providing the required files. The program outputs the following for each instruction:
- The machine code of the instruction being executed (similar to an assembler)
- Value of the Program Counter (PC) as Binary, Hex and Decimal
- Values of the 32 Registers as Binary, Hex and Decimal
- Content of Memory (Each filled address along with its contained value) as Binary, Hex and Decimal

## Test Cases
In the "Test Cases" folder, there are 3 test cases:

- "test1.txt" along with "test1_memory.txt". This is a simple test program that loops ten times before testing different types of loads.
- "test2.txt". This is a test program that multiplies 3 (held in x12) by 3 (held in x13) and stores the result in a0 using a loop instead of using the M extension.
- "test3.txt" along with "test3_memory.txt". This is a test program that clears an array stored in the memory. The array starting address is held in a0, and the array size is held in a1. 

## Team Members
The project was done by the following team members:
- Mohamed Sherif - https://github.com/MohamedSherifNoureldin
- Sara Mohamed - https://github.com/saraa-mohamedd
- Roaa Bahaa - https://github.com/Roaabahaa 