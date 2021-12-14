#pragma once
#include "BUS.hpp"
#include "TYPE.hpp"

class MEMORY
{
private:
	WORD  memory[WORD_SIZE];
	BUS * memBUS;
	PORT *memPORT;

public:
	MEMORY();

	void Sync(BUS *bus);
	void connect_BUS(BUS *bus, PORT *port);
};
