#ifndef TRANSMITVALUES_H
#define TRANSMITVALUES_H

enum CommandType {
	LSx,
	LSy,
	RSx,
	RSy,
	LT,
	RT,
	Vertical,
	Horizontal,
	A,
	B,
	X,
	Y,
	LB,
	RB,
	Start,
	Stop,
	NO_COMMAND
};

// Start & Stop commands
#define _START_ 231
#define _STOP_ 153

// Left stick
#define _LEFT_ST_X_MIN_ 5
#define _LEFT_ST_X_ZERO_ 21
#define _LEFT_ST_X_MAX_ 37
#define _LEFT_ST_Y_MIN_ 38
#define _LEFT_ST_Y_ZERO_ 54
#define _LEFT_ST_Y_MAX_ 70

// Right stick
#define _RIGHT_ST_X_MIN_ 71
#define _RIGHT_ST_X_ZERO_ 87
#define _RIGHT_ST_X_MAX_ 103
#define _RIGHT_ST_Y_MIN_ 104
#define _RIGHT_ST_Y_ZERO_ 120
#define _RIGHT_ST_Y_MAX_ 136

// Right trigger
#define _RT_MIN_ 157
#define _RT_MAX_ 188

// Left trigger
#define _LT_MIN_ 189
#define _LT_MAX_ 220

// Keypad
#define _UP_RELEASED_ 137
#define _UP_PRESSED_ 138
#define _DOWN_RELEASED_ 139
#define _DOWN_PRESSED_ 140
#define _LEFT_RELEASED_ 141
#define _LEFT_PRESSED_ 142
#define _RIGHT_RELEASED_ 143
#define _RIGHT_PRESSED_ 144

// Buttons
#define _A_BUTTON_ 221
#define _B_BUTTON_ 222
#define _X_BUTTON_ 223
#define _Y_BUTTON_ 224

// Bumpers
#define _LEFT_BUMPER_ 145
#define _RIGHT_BUMPER_ 146

#endif
