
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

struct Joysticks {
	int num_joysticks;
	SDL_Joystick *joystick_handle[10];

	SDL_bool is_joystick_open[10];

	SDL_JoystickGUID joystick_guid[10];
	SDL_JoystickID joystick_instance_id[10];
	int joystick_player_index[10];
	Uint16 joystick_product[10];
	Uint16 joystick_product_version[10];
	SDL_JoystickType joystick_type[10];
	Uint16 joystick_vendor[10];
	char *joystick_name[10];


	// char *joystick_serial_number[10];

	int num_controllers;
	SDL_GameController *controller_handle[10];
};

void add_joystick(struct Joysticks *joysticks, Sint32 device_index);
void remove_joystick(struct Joysticks *joysticks, Sint32 instance_id);

void add_controller(struct Joysticks *joysticks, Sint32 index);
void remove_controller(struct Joysticks *joysticks, Sint32 index);

void print_input(struct Joysticks *joysticks);
void print_input2(struct Joysticks *joysticks);

#if 0
void add_joystick();


void create_joysticks(Struct Joysticks *joysticks);
void destroy_joysticks();

void get_keyboard_input();
void get_mouse_input();
#endif

#endif
