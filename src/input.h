
#ifndef _INPUT_H_
#define _INPUT_H_

#include <SDL.h>
#include <stdbool.h>

struct KeyboardMapping {
	SDL_Keycode up, down, left, right;
};

struct Action { // change to Uint16 and use bits later
	bool up, down, left, right;
};

void get_joystick_input();
void get_keyboard_input();
void get_mouse_input();

#endif
