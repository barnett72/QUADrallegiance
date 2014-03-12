#include "stick.h"

Stick::Stick(int x, int y, bool pressed)
{
  this -> x = x;
  this -> y = y;
  this -> pressed = pressed;
}

void Stick::setX(int x)
{
  this -> x = x;
}

void Stick::setY(int y)
{
  this -> y = y;
}

void Stick::setPressed(bool pressed)
{
  this -> pressed = pressed;
}

int Stick::getX()
{
  return (-1)*normalizeValues(x);
}

int Stick::getY()
{
  return normalizeValues(y);
}

bool Stick::isPressed() { return pressed; }

int Stick::normalizeValues(int value)
{
	if(value > STICK_THRESHOLD)
	{
		int normalized = (value - STICK_THRESHOLD + DIVISOR)/DIVISOR;
		if(normalized > MAX_VALUE)
			normalized = MAX_VALUE;
		return normalized;
	}
	else if((-1)*(value) > STICK_THRESHOLD)
	{
		int normalized = (value + STICK_THRESHOLD - DIVISOR + 1)/DIVISOR;
		if((-1*normalized) > MAX_VALUE)
			normalized = -MAX_VALUE;
		return normalized;
	}
	else
	{
		return 0;
	}
}
