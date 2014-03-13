#include "trigger.h"

Trigger::Trigger()
{
	value = 0;
}

void Trigger::setValue(int rawValue)
{
	value = (char)(rawValue/TRIGGER_DIVISOR);
}

char Trigger::getValue()
{
	return value;
}

char Trigger::getTransmitValue(int zeroOffset)
{
	return zeroOffset + value;
}

