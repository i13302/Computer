#pragma once

#include "BUS.hpp"
#include "TYPE.hpp"

#define REGISTER_SIZE 1

class CPU
{

private:
	WORD REGISTERS[REGISTER_SIZE];
	DATA PC; // Program Counter

	OPRATE IR; // Instruction Register
	BUS *  memBUS;
	PORT * memPORT;
	OPRAND MAR; // Memory Address Register
	WORD   MBR; // Memory Buffer Register

	WORD NULLWORD;

	OPRATE operate[OPRATE_SIZE];
	OPRATE getOPRate(WORD value);
	OPRAND getOPRand(WORD value);

	enum OparateTable { LDI, LOAD, STORE, JUMP };

	bit4 TIMING;
	bool timing_reset=false;

	void setBUS(BUS *bus, ADDR _addr, WORD _word, MODE _mode);
	WORD readBus(BUS *bus);
	void decode();

	void Ins_LDI();   // Load Immediate to Register from Operand
	void Ins_LOAD();  // Load to Register from Memory
	void Ins_STORE(); // Store from Register to Memory
	void Ins_JUMP();  // Jump to Memory

public:
	void reset();
	void clock();
	void connect_BUS(BUS *bus, PORT *port);

	void debug_print();
};
