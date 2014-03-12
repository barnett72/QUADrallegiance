#ifndef STICK_H
#define STICK_H

#include "transmitValues.h"

#define STICK_THRESHOLD 8192
#define DIVISOR 1536
#define MAX_VALUE 16

class Stick
{
  public:
    Stick(int x=-1, int y=-1, bool pressed=false);
    void setX(int x);
    void setY(int y);
    void setPressed(bool pressed);
    int getX();
    int getY();
    bool isPressed();
    int normalizeValues(int value);
  private:
    int x;
    int y;
    bool pressed;
};

#endif
