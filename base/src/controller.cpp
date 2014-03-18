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

  back = false;
  down = false;
  horizontal_release = false;
  isRunning = false;
  left = false;
  right = false;
  start = false;
  up = false;
  vertical_release = false;
}

CommandType Controller::getActions()
{
	CommandType commandType = NO_COMMAND;
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
				commandType = LSx;
				break;
			case _LSy:
				temp = lStick->getY();
				lStick->setY(ie.value);
				if(temp == lStick->getY())
					break;
				commandType = LSy;
				break;
			case _RSx:
				temp = rStick->getX();
				rStick->setX(ie.value);
				if(temp == rStick->getX())
					break;
				commandType = RSx;
				break;
			case _RSy:
				temp = rStick->getY();
				rStick->setY(ie.value);
				if(temp == rStick->getY())
					break;
				commandType = RSy;
				break;
			case _rt:
				temp = rTrigger->getValue();
				rTrigger->setValue(ie.value);
				if(temp == rTrigger->getValue())
					break;
				commandType = RT;
				break;
			case _lt:
				temp = lTrigger->getValue();
				lTrigger->setValue(ie.value);
				if(temp == lTrigger->getValue())
					break;
				commandType = LT;
				break;
			case _horizontal:
				if(ie.value == -1)
					left = true;
				else if(ie.value == 1)
					right = true;
				else
					horizontal_release = true;
				commandType = Horizontal;
				break;
			case _vertical:
				if(ie.value == -1)
					up = true;
				else if(ie.value == 1)
					down = true;
				else
					vertical_release = true;
				commandType = Vertical;
				break;
			case _a:
				if(ie.value)
					commandType = A;
				break;
			case _b:
				if(ie.value)
					commandType = B;
				break;
			case _x:
				if(ie.value)
					commandType = X;
				break;
			case _y:
				if(ie.value)
					commandType = Y;
				break;
			case _lb:
				if(ie.value)
					commandType = LB;
				break;
			case _rb:
				if(ie.value)
					commandType = RB;
				break;
			case _start:
				start = ie.value;
				commandType = determineStartStop(start);
				break;
			case _back:
				back = ie.value;
				commandType = determineStartStop(back);
				break;
			default:
				break;
		}
	}
	return commandType;
}

CommandType Controller::determineStartStop(bool pressed)
{
	CommandType type = NO_COMMAND;
	if(start && back)
	{
		if(!isRunning)
		{
			type = Start;
			isRunning = true;
		}
		else
		{
			type = Stop;
			isRunning = false;
		}
	}
	else if(pressed == false)
	{
		start = false;
		back = false;
	}
	return type;
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

char Controller::getVerticalByte()
{
	char returnVal = 0;
	if(vertical_release && up)
	{
		returnVal = _UP_RELEASED_;
		vertical_release = false;
		up = false;
	}
	else if(vertical_release && down)
	{
		returnVal = _DOWN_RELEASED_;
		vertical_release = false;
		down = false;
	}
	else if(up)
		returnVal = _UP_PRESSED_;
	else if(down)
		returnVal = _DOWN_PRESSED_;
	return returnVal;
}

char Controller::getHorizontalByte()
{
	char returnVal = 0;
	if(horizontal_release && left)
	{
		returnVal = _LEFT_RELEASED_;
		horizontal_release = false;
		left = false;
	}
	else if(horizontal_release && right)
	{
		returnVal = _RIGHT_RELEASED_;
		horizontal_release = false;
		right = false;
	}
	else if(left)
		returnVal = _LEFT_PRESSED_;
	else if(right)
		returnVal = _RIGHT_PRESSED_;
	return returnVal;
}

char Controller::getAbyte() { return _A_BUTTON_; }

char Controller::getBbyte() { return _B_BUTTON_; }

char Controller::getXbyte() { return _X_BUTTON_; }

char Controller::getYbyte() { return _Y_BUTTON_; }

char Controller::getLeftBumperByte() { return _LEFT_BUMPER_; }

char Controller::getRightBumperByte() { return _RIGHT_BUMPER_; }

char Controller::getStartByte() { return _START_; }

char Controller::getStopByte() { return _STOP_; }
