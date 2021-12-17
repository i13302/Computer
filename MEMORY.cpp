#include "MEMORY.hpp"
#include "BUS.hpp"
#include "DEBUG.hpp"
#include "TYPE.hpp"

MEMORY::MEMORY()
{
	SET_WORD(this->memory[0x0], 0x0);
	SET_WORD(this->memory[0x1], 0xA);
	SET_WORD(this->memory[0x2], 0x0);
	SET_WORD(this->memory[0x3], 0xB);
	SET_WORD(this->memory[0x4], 0x0);
	SET_WORD(this->memory[0x5], 0xC);
	SET_WORD(this->memory[0x6], 0x0);
	SET_WORD(this->memory[0x7], 0xD);
	SET_WORD(this->memory[0x8], 0x0);
	SET_WORD(this->memory[0x9], 0xE);
	SET_WORD(this->memory[0xA], 0x0);
	SET_WORD(this->memory[0xB], 0xF);
}

void MEMORY::Sync()
{
	this->debug_print();
	if (memBUS->mode == MODE_READ) {
		COPY_WORD(memBUS->word, this->memory[GET_DATA(memBUS->addr)]);
	} else if (memBUS->mode == MODE_WRITE) {
		COPY_WORD(this->memory[GET_DATA(memBUS->addr)], memBUS->word);
	}
}

void MEMORY::connect_BUS(BUS *bus, PORT *port)
{
	this->memBUS  = bus;
	this->memPORT = port;
	PTR_SET_DATA(this->memPORT, 1);
}

void MEMORY::debug_print()
{
	
	DEBUG_PRINT("memBUS addr", this->memBUS->addr);
	DEBUG_PRINT("memBUS word", this->memBUS->word);
	for (int i = 0; i < WORD_SIZE; i++) {
		DEBUG_PRINT("MEMORY", this->memory[i]);
	}
}
