#pragma once
#include "BUS.hpp"
#include "TYPE.hpp"

class MEMORY
{
private:
	WORD  memory[WORD_SIZE];
	BUS * memBUS;
	PORT *memPORT;

	void debug_print();

public:
	MEMORY();

	void Sync();
	void connect_BUS(BUS *bus, PORT *port);
};
