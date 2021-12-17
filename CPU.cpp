
#include "CPU.hpp"
#include "DEBUG.hpp"
#include "TYPE.hpp"

void CPU::reset()
{
	SET_DATA(this->PC, 0x0);
	SET_DATA(this->TIMING, 0x0);
	SET_WORD(this->NULLWORD, 0xF);
}

void CPU::clock()
{
	OPRATE oprate;
	DEBUG_PRINT("case", this->TIMING);
	switch (GET_DATA(this->TIMING)) {
	case 0:
		COPY_DATA(this->MAR, this->PC);
		this->setBUS(memBUS, this->MAR, NULLWORD, MODE_READ);
		break;
	case 1:
		oprate = (OPRATE)this->readBus(memBUS);
		COPY_DATA(this->MBR, oprate);
		INC_DATA(this->PC);
		DEBUG_PRINT("oprate", oprate);
		break;
	case 2:
		COPY_DATA(this->IR, this->MBR);
		break;
	default:
		decode();
		break;
	}
	this->debug_print();

	if (this->timing_reset) {
		SET_DATA(this->TIMING, 0x0);
		this->timing_reset = false;
		return;
	}
	INC_DATA(this->TIMING);
}

OPRATE CPU::getOPRate(WORD value)
{
	OPRATE _value;
	SET_OPRATE(_value, (GET_WORD(value) >> OPRAND_SIZE));

	return _value;
}

OPRAND CPU::getOPRand(WORD value)
{
	OPRAND _value;
	SET_OPRAND(_value, GET_WORD(value));

	return _value;
}

void CPU::decode()
{
	switch (GET_OPRATE(IR)) {
	case OparateTable::LDI:
		Ins_LDI();
		break;
	case OparateTable::LOAD:
		Ins_LOAD();
		break;
	case OparateTable::STORE:
		Ins_STORE();
		break;
	case OparateTable::JUMP:
		Ins_JUMP();
		break;
	default:
		break;
	}
}

void CPU::Ins_LDI()
{
	OPRAND oprand;

	switch (GET_DATA(this->TIMING)) {
	case 3:
		COPY_DATA(this->MAR, this->PC);
		this->setBUS(memBUS, this->MAR, NULLWORD, MODE_READ);
		break;
	case 4:
		oprand = (OPRAND)this->readBus(memBUS);
		COPY_DATA(this->MBR, oprand);
		INC_DATA(this->PC);
		break;
	case 5:
		COPY_DATA(this->REGISTERS[0], this->MBR);
		this->timing_reset = true;
		break;
	}
}

void CPU::Ins_LOAD()
{
}

void CPU::Ins_STORE()
{
}

void CPU::Ins_JUMP()
{
}

void CPU::connect_memory_BUS(BUS *bus, PORT *port)
{
	this->memBUS  = bus;
	this->memPORT = port;
	PTR_SET_DATA(this->memPORT, 0x1);
}

void CPU::setBUS(BUS *bus, ADDR _addr, WORD _word, MODE _mode)
{

	COPY_DATA(bus->addr, _addr);
	COPY_DATA(bus->word, _word);
	bus->mode = _mode;
}

WORD CPU::readBus(BUS *bus)
{
	return bus->word;
}

void CPU::debug_print()
{
	DEBUG_PRINT("TIMING", this->TIMING);
	DEBUG_PRINT("PC", this->PC);
	DEBUG_PRINT("IR", this->IR);
	DEBUG_PRINT("REGISTERS[0]", this->REGISTERS[0]);
	DEBUG_PRINT("MAR", this->MAR);
	DEBUG_PRINT("MBR", this->MBR);
}
