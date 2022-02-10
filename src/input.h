
#ifndef _INPUT_H_
#define _INPUT_H_

#include <SDL.h>
#include <stdbool.h>

#define MAX_JOYSTICKS 4 // 3 joysticks + 1 keyboard as virtual joystick
#define MAX_CONTROLLERS 4
#define MAX_JOYSTICK_AXES 6 // (2 axes * 2 thumbsticks) + 2 triggers
#define MAX_JOYSTICK_BUTTONS 11
#define JOYSTICK_HAT_INDEX 0 // only one hat per joystick

enum input_actions {
	ACTION_UP,
	ACTION_DOWN,
	ACTION_LEFT,
	ACTION_RIGHT,
	ACTION_A,
	ACTION_B,
	ACTION_X,
	ACTION_Y,
	ACTION_LB,
	ACTION_RB,
	ACTION_LT,
	ACTION_RT,
	ACTION_START,
	ACTION_SELECT
};

struct KeyboardMapping {
	SDL_Keycode up, down, left, right;
};

struct Action { // change to Uint16 and use bits later
	bool up, down, left, right;
};

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
	SDL_Joystick *joystick_handle[MAX_JOYSTICKS];

	int num_controllers;
	SDL_GameController *controller_handle[MAX_CONTROLLERS];

	struct RawJoystick raw_joystick[MAX_JOYSTICKS];
};

void create_joysticks();
void initialize_raw_joystick(int index, SDL_Joystick *joystick, struct RawJoystick *raw_joystick);
void print_raw_joystick(struct RawJoystick *raw_joystick);
void destroy_joysticks();

void get_keyboard_input();

#endif
