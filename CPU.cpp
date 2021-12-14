
#include "CPU.hpp"
#include "DEBUG.hpp"
#include "TYPE.hpp"

void CPU::reset()
{
	SET_DATA(this->PC, 0x0);
	SET_DATA(this->timing, 0x0);
}

void CPU::clock(WORD value)
{
	this->debug_print();

	OPRATE oprate;
	this->MEM = value;

	INC_DATA(this->timing);

	switch (GET_DATA(this->timing)) {
	case 0:
		COPY_DATA(this->MAR, this->PC);
		break;
	case 1:
		oprate = CPU::getOPRate(value);
		COPY_DATA(this->MBR, oprate);
		INC_DATA(this->PC);
		break;
	case 2:
		COPY_DATA(this->IR, this->MBR);
		break;
	default:
		decode();
		break;
	}
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
	switch (GET_DATA(this->timing)) {
	case 3:
		COPY_DATA(this->MAR, this->PC);
		break;
	case 4:
		oprand = CPU::getOPRand(this->MEM);
		COPY_DATA(this->MBR, oprand);
		INC_DATA(this->PC);
		break;
	case 5:
		COPY_DATA(this->REGISTERS[0], this->MBR);
		RESET_DATA(this->timing);
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

void CPU::debug_print()
{
	DEBUG_PRINT("timing", this->timing);
	DEBUG_PRINT("PC", this->PC);
	DEBUG_PRINT("IR", this->IR);
	DEBUG_PRINT("REGISTERS[0]", this->REGISTERS[0]);
	DEBUG_PRINT("MEM", this->MEM);
	DEBUG_PRINT("MAR", this->MAR);
	DEBUG_PRINT("MBR", this->MBR);
}
