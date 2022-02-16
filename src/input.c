
#include "input.h"

void get_joystick_input()
{
	int num_joysticks = SDL_NumJoysticks();

	for(int i = 0; i < num_joysticks; i++)
	{
		SDL_Joystick *handle = SDL_JoystickOpen(i);
		SDL_bool is_open = SDL_JoystickGetAttached(handle);
		SDL_JoystickID instanceID = SDL_JoystickGetDeviceInstanceID(i);
		char *name = (char *)SDL_JoystickNameForIndex(i);

		printf("device_index = %d, ", i);
		printf("handle = %p, ", handle);
		printf("is_open = %s, ", is_open ? "true" : "false" );
		printf("instanceID = %d, ", instanceID);
		printf("name = %s, ", name);
		printf("\n");
	}
	system("clear");
}

void get_keyboard_input()
{
	struct KeyboardMapping keymap = {
		.up = SDLK_u,
		.down = SDLK_d,
		.left = SDLK_l,
		.right = SDLK_r,
	};

	struct Action action;

	const Uint8 *state = SDL_GetKeyboardState(NULL);

	action.up = state[SDL_GetScancodeFromKey(keymap.up)];
	action.down = state[SDL_GetScancodeFromKey(keymap.down)];
	action.left = state[SDL_GetScancodeFromKey(keymap.left)];
	action.right = state[SDL_GetScancodeFromKey(keymap.right)];

#if 0
	printf("up = %s, ", action.up ? "true" : "false");
	printf("down = %s, ", action.down ? "true" : "false");
	printf("left = %s, ", action.left ? "true" : "false");
	printf("right = %s\n", action.right ? "true" : "false");
#endif
}

void get_mouse_input()
{
	int x, y;
	Uint32 buttons = SDL_GetMouseState(&x, &y);

	// wheel up and wheel down are events, not states
	// process in event handler if needed, but will not be used here

#if 0
	printf("mouse at (%d, %d),  ", x, y);
	printf("left = %s, ", buttons & SDL_BUTTON_LMASK ? "true" : "false");
	printf("middle = %s, ", buttons & SDL_BUTTON_MMASK ? "true" : "false");
	printf("right = %s, ", buttons & SDL_BUTTON_RMASK ? "true" : "false");
	printf("x1 = %s, ", buttons & SDL_BUTTON_X1MASK ? "true" : "false");
	printf("x2 = %s\n", buttons & SDL_BUTTON_X2MASK ? "true" : "false");
#endif
}































