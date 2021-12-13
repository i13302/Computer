#pragma once

#include "TYPE.hpp"

#define REGISTER_SIZE 4

class CPU
{
	
private:
	int registers[REGISTER_SIZE];
	int pc = 0;

	OPRATE operate[OPRATE_SIZE];
	OPRATE getOPRate(WORD value);
	OPRAND getOPRand(WORD value);

public:
	void clock(WORD value);
	
};
