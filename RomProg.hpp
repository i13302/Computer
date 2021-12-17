#pragma once
#include "MEMORY.hpp"
#include "TYPE.hpp"

class RomProg
{
private:
	WORD convert_to_word(char *data);

public:
	void import_to_memory(MEMORY *mem, const char *fname);
};
