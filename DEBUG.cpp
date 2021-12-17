#include <iostream>

#include "DEBUG.hpp"
#include "TYPE.hpp"

void DEBUG_PRINT(const char *str, bit4 value)
{
	std::printf("%s: %02x\n", str, GET_WORD(value));
}
