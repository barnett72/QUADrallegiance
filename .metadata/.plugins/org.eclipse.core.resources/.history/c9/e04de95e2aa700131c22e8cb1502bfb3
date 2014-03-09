#include "controller.h"

const char* EventPath = "/dev/input/event0";

Controller::Controller()
{
  rStick = new Stick();
  lStick = new Stick();

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

  read(fd, &ie, sizeof(struct input_event));

  if(!((ie.code==0)&&(ie.type!=3)))
   {
    switch(ie.code)
    {
      case _LSx:
        if((abs(ie.value)<STICK_THRESHOLD)&&(_LSx0==true)) { break; }
        lStick -> setX(ie.value);
        if(lStick -> getX()==0) { _LSx0 = true; }
        else { _LSx0 = false; }
        updatedAction = true;
        break;
      case _LSy:
        if((abs(ie.value)<STICK_THRESHOLD)&&(_LSy0==true)) { break; }
        lStick -> setY(ie.value);
        if(lStick -> getY()==0) { _LSy0 = true; }
        else { _LSy0 = false; }
        updatedAction = true;
        break;
      case _rt:
        rt = ie.value;
        updatedAction = true;
        break;
      case _lt:
        lt = ie.value;
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

signed char Controller::getLeftStickXByte()
{
  return (signed char)((lStick->getX()-1)/2);
}

signed char Controller::getLeftStickYByte()
{
  return (signed char)((lStick->getY()-1)/2);
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

std::string Controller::getThrottleNumber()
{
  return convertInt(rt);
}

std::string Controller::getSampleString()
{
  return "(" + convertInt(lStick->getX()) + "," + convertInt(lStick->getY()) + ") " + convertInt(rt);
}

std::string Controller::convertInt(int number)
{
  std::stringstream ss;
  ss << number;
  return ss.str();
}