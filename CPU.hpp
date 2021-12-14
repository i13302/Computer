#pragma once

#include "TYPE.hpp"

#define REGISTER_SIZE 1

class CPU
{

private:
	WORD REGISTERS[REGISTER_SIZE];
	DATA PC; // Program Counter

	OPRATE IR;       // Instruction Register
	OPRAND MAR; // Memory Address Register
	WORD MBR;		// Memory Buffer Register
	WORD MEM;

	OPRATE operate[OPRATE_SIZE];
	OPRATE getOPRate(WORD value);
	OPRAND getOPRand(WORD value);

	enum OparateTable { LDI, LOAD, STORE, JUMP };

	bit4 timing;

	// void
	void decode();

	void Ins_LDI();   // Load Immediate to Register from Operand
	void Ins_LOAD();  // Load to Register from Memory
	void Ins_STORE(); // Store from Register to Memory
	void Ins_JUMP();  // Jump to Memory

public:
	void reset();
	void clock(WORD value);
	
	void debug_print();
};
