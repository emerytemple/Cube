
#ifndef _INPUT_H_
#define _INPUT_H_

#include <SDL.h>

#define MAX_JOYSTICKS 5 // 4 joysticks + 1 keyboard as virtual joystick
#define MAX_JOYSTICK_AXES 6 // (2 axes * 2 thumbsticks) + 2 triggers
#define MAX_JOYSTICK_BUTTONS 11
#define JOYSTICK_HAT_INDEX 0 // only one hat per joystick

struct RawJoystick {
	int index;
	char *name;

	int num_buttons;
	int num_axes;
	int num_balls;
	int num_hats;

	Sint16 axis[MAX_JOYSTICK_AXES];
	Uint8 hat;
	Uint8 button[MAX_JOYSTICK_BUTTONS];
};

struct Joysticks {
	int num_joysticks;
	SDL_Joystick *joystick[MAX_JOYSTICKS];

	struct RawJoystick raw_joystick[MAX_JOYSTICKS];
};

void create_joysticks();
void initialize_raw_joystick(int index, SDL_Joystick *joystick, struct RawJoystick *raw_joystick);
void print_raw_joystick(struct RawJoystick *raw_joystick);
void destroy_joysticks();

#endif
