/*
 * receiver.cpp
 *
 *  Created on: Mar 8, 2014
 *      Author: matt
 */

#include "receiver.h"

Receiver::Receiver()
{
	std::cout << "Receiver attempting to open /dev/xbee" << std::endl;
	handle = serialOpen("/dev/ttyUSB0", BAUD_RATE_XBEE);
	std::cout << "Receiver sucessfully opened /dev/xbee" << std::endl;
}


int8_t Receiver::readChar()
{
	  int8_t x ;

	  if (read (handle, &x, 1) != 1)
	    return -1;

	  return ((int8_t)x) & 0xFF ;
}
