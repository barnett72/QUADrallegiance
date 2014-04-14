#include <iostream>

#include "receiver.h"

int main()
{
	Receiver* receiver = new Receiver();

	while(1)
	{
		int8_t c = receiver->readChar();
		if(!((c>255)||(c<0)))
		{
			std::cout << c << std::endl;
		}
	}

	return 0;
}
