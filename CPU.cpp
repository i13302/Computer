
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
