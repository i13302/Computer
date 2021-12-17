#include "RomProg.hpp"
#include "DEBUG.hpp"
#include "MEMORY.hpp"
#include "TYPE.hpp"
#include <fstream>
#include <iostream>

WORD RomProg::convert_to_word(char *data)
{
	WORD _w;
	SET_WORD(_w, (int)strtol(data, NULL, 16));
	return _w;
}

void RomProg::import_to_memory(MEMORY *mem, const char *fname)
{
	printf("import_to_memory from %s\n", fname);

	char buf[WORD_NOD_plus1] = {0x0};
	WORD word[WORD_SIZE]     = {0x0};

	std::ifstream ifs(fname);
	if (ifs.fail()) {
		std::cerr << "Failed to open file." << std::endl;
		return;
	}

	for (int i = 0; ifs.getline(buf, WORD_NOD_plus1); i++) {
		puts(buf);
		word[i] = this->convert_to_word(buf);
		DEBUG_PRINT("MEMORY", word[i]);
	}

	mem->direct_write(WORD_SIZE, word);
}
