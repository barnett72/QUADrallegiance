#include "stick.h"

Stick::Stick()
{
	x = 0;
	y = 0;
	pressed = false;
}

void Stick::setX(int x)
{
  this -> x = normalizeValues(x);
}

void Stick::setY(int y)
{
  this -> y = (-1)*normalizeValues(y);
}

void Stick::setPressed(bool pressed)
{
  this -> pressed = pressed;
}

signed char Stick::getX()
{
	return x;
}

signed char Stick::getY()
{
	return y;
}

char Stick::getTransmitX(char zeroOffset)
{
	return zeroOffset +  x;
}

char Stick::getTransmitY(char zeroOffset)
{
	return zeroOffset + y;
}

bool Stick::isPressed()
{
	return pressed;
}

signed char Stick::normalizeValues(int value)
{
	if(value > STICK_THRESHOLD)
	{
		int normalized = (value - STICK_THRESHOLD + STICK_DIVISOR)/STICK_DIVISOR;
		if(normalized > MAX_VALUE)
			normalized = MAX_VALUE;
		return normalized;
	}
	else if((-1)*(value) > STICK_THRESHOLD)
	{
		int normalized = (value + STICK_THRESHOLD - STICK_DIVISOR + 1)/STICK_DIVISOR;
		if((-1*normalized) > MAX_VALUE)
			normalized = -MAX_VALUE;
		return normalized;
	}
	else
	{
		return 0;
	}
}
