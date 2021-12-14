#include "MEMORY.hpp"
#include "BUS.hpp"
#include "TYPE.hpp"

MEMORY::MEMORY()
{
	WORD i;
	for (SET_WORD(i, 0); GET_WORD(i) < 0x5; INC_WORD(i)) {
		SET_WORD(this->memory[GET_WORD(i)], 0x01 + GET_WORD(i));
	}
}

void MEMORY::Sync(BUS *bus)
{
	if (bus->mode == MODE_READ) {
		COPY_WORD(bus->word, this->memory[GET_DATA(bus->addr)]);
	} else if (bus->mode == MODE_WRITE) {
		COPY_WORD(this->memory[GET_DATA(bus->addr)], bus->word);
	}
}

void MEMORY::connect_BUS(BUS *bus, PORT *port)
{
	this->memBUS  = bus;
	this->memPORT = port;
	PTR_SET_DATA(this->memPORT, 1);
}
