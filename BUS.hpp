#pragma once
#include "TYPE.hpp"

#define MODE_READ 0
#define MODE_WRITE 1

typedef bool MODE;
typedef struct {
	WORD word;
	ADDR addr;
	MODE mode;
} BUS;
