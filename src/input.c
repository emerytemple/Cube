
#include "input.h"

void get_joystick_input()
{
	int num_joysticks = SDL_NumJoysticks();

	for(int i = 0; i < num_joysticks; i++)
	{
		// joystick
		SDL_Joystick *joystick = SDL_JoystickOpen(i);
		SDL_bool is_joystick_open = SDL_JoystickGetAttached(joystick);
		SDL_JoystickID instanceID = SDL_JoystickGetDeviceInstanceID(i);
		char *joystick_name = (char *)SDL_JoystickNameForIndex(i);
		SDL_bool is_game_controller = SDL_IsGameController(i);

		char *guid_string = NULL;
		SDL_JoystickGUID guid = SDL_JoystickGetGUID(joystick);
		// SDL_JoystickGUID guid = SDL_JoystickGetDeviceGUID(i);
		SDL_JoystickGetGUIDString(guid, guid_string, sizeof(guid));
		printf("guid = %s, ", guid_string);

		printf("device_index = %d, ", i);
		printf("handle = %p, ", joystick);
		// printf("guid = %s, ", guid_string);
		printf("is_open = %s, ", is_joystick_open ? "true" : "false" );
		printf("instanceID = %d, ", instanceID);
		printf("name = %s, ", joystick_name);
		printf("is game ctrl = %s, ", is_game_controller ? "true" : "false" );

		printf("button = ");
		for(int j = 0; j < SDL_JoystickNumButtons(joystick); j++)
		{
			Uint8 button = SDL_JoystickGetButton(joystick, j);
			printf("%d", button);
		}
		printf(", ");

		printf("hat = ");
		for(int j = 0; j < SDL_JoystickNumHats(joystick); j++)
		{
			Uint8 hat = SDL_JoystickGetHat(joystick, j);
			printf("%d", hat);
		}
		printf(", ");

		printf("\n");

		// game controller
		SDL_GameController *controller = SDL_GameControllerOpen(i);
		SDL_bool is_controller_open = SDL_GameControllerGetAttached(controller);
		SDL_Joystick *joystick_for_controller = SDL_GameControllerGetJoystick(controller);
		char *controller_name = (char *)SDL_GameControllerName(controller);
		char *controller_for_index = (char *)SDL_GameControllerNameForIndex(i);

		printf("device_index = %d, ", i);
		printf("ctrl_handle = %p, ", controller);
		printf("joy for ctrl = %p, ", joystick_for_controller);
		printf("ctrl name = %s, ", controller_name);
		printf("ctrl for device index = %s, ", controller_for_index);
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































