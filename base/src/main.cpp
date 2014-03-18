#include "transmitter.h"
#include "transmitValues.h"

int main()
{
	Transmitter* transmitter = new Transmitter();
	int handle = transmitter->GetHandle();
	Controller* controller = transmitter->GetController();
	bool isRunning = false;

  while(1)
  {
	  CommandType commandType = controller->getActions();
	  if(isRunning)
	  {
		  if(commandType != NO_COMMAND)
		  {
			  switch(commandType)
			  {
			  	  case LSx:
			  		  serialPutchar(handle, controller->getLeftStickXByte());
			  		  break;
			  	  case LSy:
			  		  serialPutchar(handle, controller->getLeftStickYByte());
			  		  break;
			  	  case RSx:
			  		  serialPutchar(handle, controller->getRightStickXByte());
			  		  break;
			  	  case RSy:
			  		  serialPutchar(handle, controller->getRightStickYByte());
			  		  break;
			  	  case LT:
			  		  serialPutchar(handle, controller->getLeftTriggerValue());
			  		  break;
			  	  case RT:
			  		  serialPutchar(handle, controller->getRightTriggerValue());
			  		  break;
			  	  case Vertical:
			  		  serialPutchar(handle, controller->getVerticalByte());
			  		  break;
			  	  case Horizontal:
			  		  serialPutchar(handle, controller->getHorizontalByte());
			  		  break;
			  	  case A:
			  		  serialPutchar(handle, controller->getAbyte());
			  		  break;
			  	  case B:
			  		  serialPutchar(handle, controller->getBbyte());
			  		  break;
			  	  case X:
			  		  serialPutchar(handle, controller->getXbyte());
			  		  break;
			  	  case Y:
			  		  serialPutchar(handle, controller->getYbyte());
			  		  break;
			  	  case LB:
			  		  serialPutchar(handle, controller->getLeftBumperByte());
			  		  break;
			  	  case RB:
			  		  serialPutchar(handle, controller->getRightBumperByte());
			  		  break;
			  	  case Stop:
			  		  serialPutchar(handle, controller->getStopByte());
			  		  isRunning = false;
			  		  break;
			  	  default:
			  		  break;
			  }
		  }
	  }
	  else
	  {
		  if(commandType == Start)
		  {
			  serialPutchar(handle, controller->getStartByte());
			  isRunning = true;
		  }
	  }
  }
  return 0;
}
