#include <iostream>
#include <unistd.h>

#include "BUS.hpp"
#include "CPU.hpp"
#include "MEMORY.hpp"
#include "TYPE.hpp"

int main(void)
{
	BUS  memBUS;
	PORT ports[PORT_SIZE];

	CPU    cpu    = CPU();
	MEMORY memory = MEMORY();

	cpu.connect_BUS(&memBUS, &ports[0]);
	memory.connect_BUS(&memBUS, &ports[1]);

	printf("start computer\n");
	cpu.reset();
	for (int clock = 0; 1; clock++) {
		// printf("clock: %d\n", clock);
		getchar();
		cpu.clock();
		memory.Sync(&memBUS);
		sleep(1);
	}

	printf("end computer\n");
	return 0;
}
