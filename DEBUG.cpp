#include <iostream>

#include "DEBUG.hpp"
#include "TYPE.hpp"

void DEBUG_PRINT(const char *str, WORD value)
{
	std::printf("%s: %2x\n", str, GET_WORD(value));
}

void DEBUG_PRINT(const char *str, DATA value)
{
	std::printf("%s: %2x\n", str, GET_WORD(value));
}
