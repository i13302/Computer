#include "BUS.hpp"
#include "CPU.hpp"
#include "MEMORY.hpp"
#include "RomProg.hpp"
#include "TYPE.hpp"
#include <iostream>

int main(void)
{
	BUS  memBUS;
	PORT ports[PORT_SIZE];

	RomProg romProg = RomProg();

	CPU    cpu    = CPU();
	MEMORY memory = MEMORY();

	romProg.import_to_memory(&memory, "Load/mem-1.txt");

	cpu.connect_memory_BUS(&memBUS, &ports[0]);
	memory.connect_BUS(&memBUS, &ports[1]);

	printf("start computer\n");
	cpu.reset();
	for (int clock = 0; 1; clock++) {
		// printf("clock: %d\n", clock);
		getchar();
		cpu.clock();
		memory.Sync();
	}

	printf("end computer\n");
	return 0;
}
