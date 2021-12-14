#include <iostream>
#include <unistd.h>

#include "CPU.hpp"
#include "TYPE.hpp"

int main(void)
{
	CPU cpu = CPU();

	WORD mem1;
	SET_WORD(mem1, 0x0F);

	printf("start computer\n");
	cpu.reset();
	for (int clock = 0; 1; clock++) {
		// printf("clock: %d\n", clock);
		getchar();
		cpu.clock(mem1);
		sleep(1);
		}

	printf("end computer\n");
	return 0;
}
