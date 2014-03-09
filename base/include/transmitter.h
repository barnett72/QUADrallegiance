#ifndef TRANSMITTER_H
#define TRANSMITTER_H

#include <iostream>
#include <stdexcept>
#include <string>
#include <cstring>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <linux/input.h>
#include <unistd.h>
#include <wiringSerial.h>

#include "controller.h"
#include "transmitValues.h"

#define BAUD_RATE_XBEE 57600

class Transmitter
{
	public:
		Transmitter();
		int GetHandle();
		Controller* GetController();
	private:
		int handle;
		Controller* controller;
};

#endif