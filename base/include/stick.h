#ifndef STICK_H
#define STICK_H

#include "transmitValues.h"

#define STICK_THRESHOLD 8192
#define STICK_DIVISOR 1536
#define MAX_VALUE 16

class Stick
{
  public:
    Stick();
    void setX(int x);
    void setY(int y);
    void setPressed(bool pressed);
    signed char getX();
    signed char getY();
    bool isPressed();
    char getTransmitX(char zeroOffset);
    char getTransmitY(char zeroOffset);
  private:
    signed char x;
    signed char y;
    bool pressed;
    signed char normalizeValues(int value);
};

#endif
