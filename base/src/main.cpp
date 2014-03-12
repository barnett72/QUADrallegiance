#include "transmitter.h"
/*
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
      xByte = controller->getLeftStickXByte();
      yByte = controller->getLeftStickYByte();    
      if(controller->getA())
      {
        for(int i=0;i<5;i++)
        {
          serialPutchar(handle,'a');
          isRunning = true;
          usleep(10);
        }
      }
      else if(controller->getB())
      {
        for(int i=0;i<5;i++)
        {
          serialPutchar(handle,'b');
          isRunning = false;
          usleep(10);
        }
      }
      else if(isRunning)
      {
        if(xByte==0)
        {
          xByte=1;
        }
        else if((xByte==97)||(xByte==98))
        {
          xByte = 100;
        }
        if(yByte==0)
        {
          yByte=1;
        }
        else if((yByte==97)||(yByte==98))
        {
          yByte = 100;
        }
        serialPutchar(handle,'d');
        serialPutchar(handle,xByte);
        serialPutchar(handle,yByte);
      }
    }
    else if(isRunning)
    {
      serialPutchar(handle,'d');
      serialPutchar(handle,xByte);
      serialPutchar(handle,yByte);
    }
  }
  return 0;
}
*/

int main()
{
	Stick* stick = new Stick();
	std::cout << "-32768 : " << stick -> normalizeValues(-32768) << std::endl;

	return 0;
}
