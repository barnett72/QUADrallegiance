/*
 * receiver.h
 *
 *  Created on: Mar 8, 2014
 *      Author: matt
 */

#ifndef RECEIVER_H_
#define RECEIVER_H_

#include <stdio.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <wiringSerial.h>

#define BAUD_RATE_XBEE 57600

class Receiver
{
	public:
		Receiver();
		int8_t readChar();
	private:
		int handle;
};

#endif /* RECEIVER_H_ */
