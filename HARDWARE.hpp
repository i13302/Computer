#pragma once
#include "BUS.hpp"
#include "TYPE.hpp"

class HARDWARE
{
private:
	BUS * bus;
	PORT *port;

protected:
	void connect_BUS(BUS *bus, PORT *port);
};
