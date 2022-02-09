
#include "virtual_joystick.h"

#define naxes 6
#define nbuttons 11
#define nhats 1

int create_virtual_joystick()
{
	int device_index = SDL_JoystickAttachVirtual(SDL_JOYSTICK_TYPE_GAMECONTROLLER, naxes, nbuttons, nhats);
	if(device_index == -1) printf("Warning: Could not attach virtual joystick. %s\n", SDL_GetError());

	return device_index;
}

void set_virtual_joystick(SDL_Joystick *joystick)
{
	// get keyboard state
	const Uint8 *state = SDL_GetKeyboardState(NULL);

	// left stick
	SDL_JoystickSetVirtualAxis(joystick, 0, state[SDL_SCANCODE_W] - state[SDL_SCANCODE_S]);
	SDL_JoystickSetVirtualAxis(joystick, 1, state[SDL_SCANCODE_A] - state[SDL_SCANCODE_D]);

	// right stick
	SDL_JoystickSetVirtualAxis(joystick, 2, state[SDL_SCANCODE_I] - state[SDL_SCANCODE_J]);
	SDL_JoystickSetVirtualAxis(joystick, 3, state[SDL_SCANCODE_K] - state[SDL_SCANCODE_L]);

	// triggers
	SDL_JoystickSetVirtualAxis(joystick, 4, state[SDL_SCANCODE_Q]);
	SDL_JoystickSetVirtualAxis(joystick, 5, state[SDL_SCANCODE_E]);

	// buttons
	SDL_JoystickSetVirtualButton(joystick, 0, state[SDL_SCANCODE_0]);
	SDL_JoystickSetVirtualButton(joystick, 1, state[SDL_SCANCODE_1]);
	SDL_JoystickSetVirtualButton(joystick, 2, state[SDL_SCANCODE_2]);
	SDL_JoystickSetVirtualButton(joystick, 3, state[SDL_SCANCODE_3]);
	SDL_JoystickSetVirtualButton(joystick, 4, state[SDL_SCANCODE_4]);
	SDL_JoystickSetVirtualButton(joystick, 5, state[SDL_SCANCODE_5]);
	SDL_JoystickSetVirtualButton(joystick, 6, state[SDL_SCANCODE_6]);
	SDL_JoystickSetVirtualButton(joystick, 7, state[SDL_SCANCODE_7]);
	SDL_JoystickSetVirtualButton(joystick, 8, state[SDL_SCANCODE_8]);
	SDL_JoystickSetVirtualButton(joystick, 9, state[SDL_SCANCODE_9]);
	SDL_JoystickSetVirtualButton(joystick, 10, state[SDL_SCANCODE_F1]);

	// dpad
	Uint8 value = 2; // use boolean algebra to figure out value

	SDL_JoystickSetVirtualHat(joystick, 0, value);
}

void destroy_virtual_joystick(int device_index)
{
	SDL_JoystickDetachVirtual(device_index);
}























