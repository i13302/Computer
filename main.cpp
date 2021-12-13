#include <iostream>
#include <unistd.h>

#include "CPU.hpp"
#include "TYPE.hpp"

int main(void)
{
	CPU cpu = CPU();

	WORD mem1;
	SET_WORD(mem1, 0xF1);

	printf("start computer\n");

	for (int clock = 0; 1; clock++) {
		// printf("clock: %d\n", clock);
		cpu.clock(mem1);
		sleep(1);
	}

	printf("end computer\n");
	return 0;
}
