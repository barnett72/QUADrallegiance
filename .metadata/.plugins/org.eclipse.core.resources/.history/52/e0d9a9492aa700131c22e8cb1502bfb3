#ifndef STICK_H
#define STICK_H

#define STICK_THRESHOLD 7168

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
  private:
    int normalizeValues(int value);
    int x;
    int y;
    bool pressed;
};

#endif