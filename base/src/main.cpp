#include "transmitter.h"

int main()
{
	Transmitter* transmitter = new Transmitter();
	int handle = transmitter->GetHandle();
	Controller* controller = transmitter->GetController();

  signed char xByte = 0;
  signed char yByte = 0;
  bool isRunning = true;

  while(1)
  {
    if(controller->getActions())
    {
      xByte = controller->getRightTriggerValue();
      serialPutchar(handle, xByte);
      yByte = controller->getLeftTriggerValue();
      serialPutchar(handle, yByte);
    }
  }
  return 0;
}
