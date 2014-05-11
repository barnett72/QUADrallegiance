#include <pthread.h>
#include "transmitter.h"
#include "transmitValues.h"

#define TRANS_EVERY_US 20000

Transmitter* transmitter;
Controller* controller;
int handle;

void* periodic_transmit(void*);

int main()
{
	transmitter = new Transmitter();
	handle = transmitter->GetHandle();
	controller = transmitter->GetController();

	pthread_t transmitThread;
	pthread_create(&transmitThread, NULL, &periodic_transmit, NULL);

	while(1)
	{
		controller->getActions();
	}

    return 0;
}

void* periodic_transmit(void*)
{
    while(1)
    {
    	usleep(TRANS_EVERY_US);
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
			serialPutchar(handle, controller->getAbyte());
			serialPutchar(handle, controller->getBbyte());
			serialPutchar(handle, controller->getXbyte());
			serialPutchar(handle, controller->getYbyte());
		}
	}
    return (void *) 0;
}
