#include "MEMORY.hpp"
#include "BUS.hpp"
#include "DEBUG.hpp"
#include "TYPE.hpp"

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

void MEMORY::direct_write(int n, WORD *data)
{
	for (int i = 0; i < n; i++) {
		this->memory[i] = data[i];
		DEBUG_PRINT("MEMORY", data[i]);
	}
}
