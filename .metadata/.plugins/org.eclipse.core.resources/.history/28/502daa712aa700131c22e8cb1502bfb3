#include "transmitter.h"

Transmitter::Transmitter()
{
	controller = new Controller();
	
	std::cout << "attempting to open /dev/xbee" << std::endl;
	handle = serialOpen("/dev/ttyUSB0", BAUD_RATE_XBEE);
	std::cout << "sucessfully opened /dev/xbee" << std::endl;
}

int Transmitter::GetHandle()
{
	return handle;
}

Controller* Transmitter::GetController()
{
	return controller;
}