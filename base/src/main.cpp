#include "transmitter.h"
#include "transmitValues.h"

#define TRANS_EVERY_US 20000

int main()
{
	Transmitter* transmitter = new Transmitter();
	int handle = transmitter->GetHandle();
	Controller* controller = transmitter->GetController();

    timeval a;
    timeval b;
    unsigned long difference;
//    unsigned char character = 0;

    while(1)
    {
        gettimeofday(&a, 0);

        bool waitForTransmit = true;
        while(waitForTransmit)
        {
            controller->getActions();

            gettimeofday(&b, 0);
            difference = (1000000*(b.tv_sec - a.tv_sec) + b.tv_usec) - a.tv_usec;

            if(difference > TRANS_EVERY_US)
            {
//            	serialPutchar(handle, character++);
//            	if(character > 255)
//            		character = 0;
            	if(controller->isRunning())
            	{
            		serialPutchar(handle, controller->getStartByte());

					serialPutchar(handle, controller->getLeftStickXByte());
					serialPutchar(handle, controller->getLeftStickYByte());

					serialPutchar(handle, controller->getRightStickXByte());
					serialPutchar(handle, controller->getRightStickYByte());

					serialPutchar(handle, controller->getLeftTriggerValue());
					serialPutchar(handle, controller->getRightTriggerValue());

					serialPutchar(handle, controller->getVerticalByte());
					serialPutchar(handle, controller->getHorizontalByte());

					serialPutchar(handle, controller->getAbyte());
					serialPutchar(handle, controller->getBbyte());
					serialPutchar(handle, controller->getXbyte());
					serialPutchar(handle, controller->getYbyte());

					serialPutchar(handle, controller->getLeftBumperByte());
					serialPutchar(handle, controller->getRightBumperByte());
            	}
            	else
            	{
            		serialPutchar(handle, controller->getStopByte());
            	}
            	waitForTransmit = false;
            }
        }

    }
    return 0;
}
