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
  start = false;
  currentlyRunning = false;

  horizontal = 0;
  vertical = 0;

  a_button = false;
  a_OnOff = false;

  b_button = false;
  b_OnOff = false;

  x_button = false;
  y_button = false;

  left_bump = false;
  right_bump = false;
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
					horizontal = -1; // left
				else if(ie.value == 1)
					horizontal = 1; // right
				else
					horizontal = 0;
				commandType = Horizontal;
				break;
			case _vertical:
				if(ie.value == -1)
					vertical = 1; // up
				else if(ie.value == 1)
					vertical = -1; // down
				else
					vertical = 0;
				commandType = Vertical;
				break;
			case _a:
				a_button = ie.value;
				if(a_button && a_OnOff)
					a_OnOff = false;
				else if(a_button && !a_OnOff)
					a_OnOff = true;
				if(a_button)
					commandType = A;
				break;
			case _b:
				b_button = ie.value;
				if(b_button && b_OnOff)
					b_OnOff = false;
				else if(a_button && !b_OnOff)
					b_OnOff = true;
				if(b_button)
					commandType = B;
				break;
			case _x:
				x_button = ie.value;
				if(x_button)
					commandType = X;
				break;
			case _y:
				y_button = ie.value;
				if(y_button)
					commandType = Y;
				break;
			case _lb:
				left_bump = ie.value;
				if(left_bump)
					commandType = LB;
				break;
			case _rb:
				right_bump = ie.value;
				if(right_bump)
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

bool Controller::isRunning()
{
	return currentlyRunning;
}

CommandType Controller::determineStartStop(bool pressed)
{
	CommandType type = NO_COMMAND;
	if(start && back)
	{
		if(!currentlyRunning)
		{
			type = Start;
			currentlyRunning = true;
		}
		else
		{
			type = Stop;
			currentlyRunning = false;
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
	switch(vertical)
	{
		case 0:
			returnVal = _VERTICAL_RELEASED_;
			break;
		case -1:
			returnVal = _VERTICAL_DOWN_;
			break;
		case 1:
			returnVal = _VERTICAL_UP_;
			break;
		default:
			break;
	}
	return returnVal;
}

char Controller::getHorizontalByte()
{
	char returnVal = 0;
	switch(horizontal)
	{
		case 0:
			returnVal = _HORIZ_RELEASED_;
			break;
		case -1:
			returnVal = _HORIZ_LEFT_;
			break;
		case 1:
			returnVal = _HORIZ_RIGHT_;
			break;
		default:
			break;
	}
	return returnVal;
}

char Controller::getAbyte()
{
	if(a_OnOff)
		return _A_PRESSED_;
	else
		return _A_RELEASED_;
}

char Controller::getBbyte()
{
	if(b_OnOff)
		return _B_PRESSED_;
	else
		return _B_RELEASED_;
}

char Controller::getXbyte()
{
	if(x_button)
		return _X_PRESSED_;
	else
		return _X_RELEASED_;
}

char Controller::getYbyte()
{
	if(y_button)
		return _Y_PRESSED_;
	else
		return _Y_RELEASED_;
}

char Controller::getLeftBumperByte()
{
	if(left_bump)
		return _L_BUMP_PRESSED_;
	else
		return _L_BUMP_RELEASED_;
}

char Controller::getRightBumperByte()
{
	if(right_bump)
		return _R_BUMP_PRESSED_;
	else
		return _R_BUMP_RELEASED_;
}

char Controller::getStartByte() { return _START_; }

char Controller::getStopByte() { return _STOP_; }
