#include "controller.h"

const char* EventPath = "/dev/input/event0";

Controller::Controller()
{
  rStick = new Stick();
  lStick = new Stick();
  rTrigger = new Trigger();
  lTrigger = new Trigger();

  fd = 0;
  
  for(int i=0;i<100;i++)
  {
    if((fd = open(EventPath, O_RDONLY) == -1))
    {
      if(i>99)
      {
        std::cerr << "could not open xboxdrv process, timed out after 100 seconds" << std::endl;
        exit(EXIT_FAILURE);
      }
      else
      {
        std::cout << "trying to open xboxdrv process after " << i << "seconds" << std::endl;
        sleep(1);
      }
    }
    else
    {
      std::cout << "opened xboxdrv process id successfully" << std::endl;
      fd = _fd; // assign to process id '3', fd i c++ gets assigned '3'
      break;
    }
  }
}

bool Controller::getActions()
{
	bool updatedAction = false;
	char temp = 0;

	read(fd, &ie, sizeof(struct input_event));

	if(!((ie.code==0)&&(ie.type!=3)))
	{
		switch(ie.code)
		{
			case _LSx:
				temp = lStick->getX();
				lStick->setX(ie.value);
				if(temp == lStick->getX())
					break;
				updatedAction = true;
				break;
			case _LSy:
				temp = lStick->getY();
				lStick->setY(ie.value);
				if(temp == lStick->getY())
					break;
				updatedAction = true;
				break;
			case _RSx:
				temp = rStick->getX();
				rStick->setX(ie.value);
				if(temp == rStick->getX())
					break;
				updatedAction = true;
				break;
			case _RSy:
				temp = rStick->getY();
				rStick->setY(ie.value);
				if(temp == rStick->getY())
					break;
				updatedAction = true;
				break;
			case _rt:
				temp = rTrigger->getValue();
				rTrigger->setValue(ie.value);
				if(temp == rTrigger->getValue())
					break;
				updatedAction = true;
				break;
			case _lt:
				temp = lTrigger->getValue();
				lTrigger->setValue(ie.value);
				if(temp == lTrigger->getValue())
					break;
				updatedAction = true;
				break;
			case _lb:
				lb = ie.value;
				updatedAction = true;
				break;
			case _rb:
				rb = ie.value;
				updatedAction = true;
				break;
			case _a:
				a = ie.value;
				updatedAction = true;
				break;
			case _b:
				b = ie.value;
				updatedAction = true;
				break;
			case _start:
				start = ie.value;
				updatedAction = true;
				break;
			case _back:
				back = ie.value;
				updatedAction = true;
				//exit(EXIT_FAILURE);
				break;
			default:
				//std::cout << "code: " << ie.code << std::endl;
				break;
		}
	}
	return updatedAction;
}

char Controller::getLeftStickXByte()
{
	return (char)(lStick->getTransmitX(_LEFT_ST_X_ZERO_));
}

char Controller::getLeftStickYByte()
{
	return (char)(lStick->getTransmitY(_LEFT_ST_Y_ZERO_));
}

char Controller::getRightStickXByte()
{
	return (char)(rStick->getTransmitX(_RIGHT_ST_X_ZERO_));
}

char Controller::getRightStickYByte()
{
	return (char)(rStick->getTransmitY(_RIGHT_ST_Y_ZERO_));
}

char Controller::getLeftTriggerValue()
{
	return lTrigger->getTransmitValue(_RT_MIN_);
}

char Controller::getRightTriggerValue()
{
	return rTrigger->getTransmitValue(_LT_MIN_);
}

bool Controller::getA()
{
  return a;
}

bool Controller::getB()
{
  return b;
}

void Controller::printDebug()
{
  std::cout << "lt:" << lt << "\tlb:" << lb << "\trt:" << rt << "\trb" << rb << "\tstart:" << start << "\t(" << lStick->getX() << ", " << lStick->getY() << ")" << std::endl;
}
