#include <iostream>

#include "DEBUG.hpp"
#include "TYPE.hpp"

void DEBUG_PRINT(const char *str, WORD value)
{
	std::cout << str << ": " << GET_WORD(value) << std::endl;
}

void DEBUG_PRINT(const char *str, DATA value)
{
	std::cout << str << ": " << GET_DATA(value) << std::endl;
}
