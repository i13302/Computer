
#include "CPU.hpp"
#include "DEBUG.hpp"
#include "TYPE.hpp"

void CPU::clock(WORD value)
{
	OPRATE oprate = CPU::getOPRate(value);
	OPRAND oprand = CPU::getOPRand(value);

	DEBUG_PRINT("OPRATE", oprate);
	DEBUG_PRINT("OPRAND", oprand);
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
