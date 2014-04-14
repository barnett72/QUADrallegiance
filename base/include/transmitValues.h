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
#define _VERTICAL_UP_ 137
#define _VERTICAL_RELEASED_ 138
#define _VERTICAL_DOWN_ 139
#define _HORIZ_LEFT_ 140
#define _HORIZ_RELEASED_ 141
#define _HORIZ_RIGHT_ 142

// Buttons
#define _A_PRESSED_ 234
#define _A_RELEASED_ 235
#define _B_PRESSED_ 236
#define _B_RELEASED_ 237
#define _X_PRESSED_ 238
#define _X_RELEASED_ 239
#define _Y_PRESSED_ 240
#define _Y_RELEASED_ 241

// Bumpers
#define _L_BUMP_PRESSED_ 145
#define _L_BUMP_RELEASED_ 146
#define _R_BUMP_PRESSED_ 147
#define _R_BUMP_RELEASED_ 148

#endif
