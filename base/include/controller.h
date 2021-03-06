#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include <stdexcept>
#include <string>
#include <cstring>
#include <sstream>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <linux/input.h>
#include <cmath>
#include <ctime>
#include <unistd.h>
#include <pthread.h>

#include "stick.h"
#include "trigger.h"
#include "transmitValues.h"

#define _RSx 3
#define _RSy 4
#define _RSpressed 318
#define _LSx 0
#define _LSy 1
#define _LSpressed 317
#define _rt 10
#define _lt 9
#define _rb 311
#define _lb 310
#define _a 304
#define _b 305
#define _x 307
#define _y 308
#define _left 16
#define _horizontal 16
#define _vertical 17
#define _back 314
#define _start 315
#define _guide 316
#define _fd 3

class Controller
{
  public:
    Controller();
    CommandType getActions();
    char getLeftStickXByte();
    char getLeftStickYByte();
    char getRightStickXByte();
    char getRightStickYByte();
    char getLeftTriggerValue();
    char getRightTriggerValue();
    char getVerticalByte();
    char getHorizontalByte();
    char getAbyte();
    char getBbyte();
    char getXbyte();
    char getYbyte();
    char getLeftBumperByte();
    char getRightBumperByte();
    char getStartByte();
    char getStopByte();
    bool isRunning();
  private:
    Stick* rStick;
    Stick* lStick;
    Trigger* rTrigger;
    Trigger* lTrigger;
    int8_t vertical;
    int8_t horizontal;
    bool back;
    bool start;
    bool a_button;
    bool a_OnOff;
    bool b_button;
    bool b_OnOff;
    bool x_button;
    bool y_button;
    bool left_bump;
    bool right_bump;
    int fd;
    struct input_event ie;
    bool currentlyRunning;
    CommandType determineStartStop(bool pressed);
};

#endif
