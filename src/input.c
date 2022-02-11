
#include "input.h"

// #include "virtual_joystick.h"

void create_joysticks()
{
	struct Joysticks joysticks;

	joysticks.num_joysticks = SDL_NumJoysticks();
	if(joysticks.num_joysticks < 1) puts("Warning: No Joysticks connected!\n");

	for(int i = 0; i < joysticks.num_joysticks; i++)
	{
		joysticks.joystick_handle[i] = SDL_JoystickOpen(i);
		if(joysticks.joystick_handle[i] == NULL) printf("Warning: Unable to open game joystick! SDL_Error: %s\n", SDL_GetError());

		initialize_raw_joystick(i, joysticks.joystick_handle[i], &joysticks.raw_joystick[i]);
		print_raw_joystick(&joysticks.raw_joystick[i]);

		/*
		if(joysticks->num_controllers > MAX_CONTROLLERS) break;

		if(SDL_IsGameController(i))
		{
			printf("Index %i is a compatible controller, named %s\n", i, SDL_GameControllerNameForIndex(i));
			SDL_GameController *ctrl = SDL_GameControllerOpen(i);
			char *mapping = SDL_GameControllerMapping(ctrl);
			printf("Controller %i is mapped as %s\n", i, mapping);
		}
		*/
	}

#if 0
	int device_index = create_virtual_joystick();
	printf("Device index = %d\n", device_index);
	joysticks.joystick_handle[device_index] = SDL_JoystickOpen(device_index);
	print_raw_joystick(&joysticks.raw_joystick[device_index]);
#endif
	SDL_JoystickEventState(SDL_IGNORE);
	printf("Joystick event polling is %s\n", SDL_JoystickEventState(SDL_QUERY) ? "enabled" : "disabled");
}

void initialize_raw_joystick(int index, SDL_Joystick *joystick, struct RawJoystick *raw_joystick)
{
	raw_joystick->index = index;
	raw_joystick->name = (char *)SDL_JoystickName(joystick);

	raw_joystick->num_buttons = SDL_JoystickNumButtons(joystick);
	if(raw_joystick->num_buttons > MAX_JOYSTICK_BUTTONS) printf("Joystick[%d] has %d buttons, which is more than the max of %d\n", index, raw_joystick->num_buttons, MAX_JOYSTICK_BUTTONS);

	raw_joystick->num_axes = SDL_JoystickNumAxes(joystick);
	if(raw_joystick->num_axes > MAX_JOYSTICK_AXES) printf("Joystick[%d] has %d axes, which is more than the max of %d\n", index, raw_joystick->num_axes, MAX_JOYSTICK_AXES);

	raw_joystick->num_balls = SDL_JoystickNumBalls(joystick);
	raw_joystick->num_hats = SDL_JoystickNumHats(joystick);

	Sint16 state;
	for(int i = 0; i < raw_joystick->num_axes; i++)
	{
		SDL_JoystickGetAxisInitialState(joystick, i, &state);
		raw_joystick->axis[i] = state;
	}

	Uint8 button;
	for(int i = 0; i < raw_joystick->num_buttons; i++)
	{
		raw_joystick->button[i] = SDL_JoystickGetButton(joystick, i);
	}

	raw_joystick->hat = SDL_JoystickGetHat(joystick, JOYSTICK_HAT_INDEX); // 0 for only one hat
}

void print_raw_joystick(struct RawJoystick *raw_joystick)
{
	printf("index = %d, name = %s\n", raw_joystick->index, raw_joystick->name);

	printf("num buttons = %d\n", raw_joystick->num_buttons);
	for(int i = 0; i < raw_joystick->num_buttons; i++)
	{
		printf("%d", raw_joystick->button[i]);
	}
	printf("\n");

	printf("num axes = %d\n", raw_joystick->num_axes);
	for(int i = 0; i < raw_joystick->num_axes; i++)
	{
		printf("axes %d = %d,  ", i, raw_joystick->axis[i]);
	}
	printf("\n");

	printf("num balls = %d\n", raw_joystick->num_balls);

	printf("num hats = %d\n", raw_joystick->num_hats);
	printf("hat = %d\n", raw_joystick->hat);

	// system("clear");
}

void destroy_joysticks()
{
	// SDL_JoystickClose(joystick);
	// joystick = NULL;
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

	// wheel up and wheel down are events, not states. need to be processed in event handler

	printf("mouse at (%d, %d),  ", x, y);
	printf("left = %s, ", buttons & SDL_BUTTON_LMASK ? "true" : "false");
	printf("middle = %s, ", buttons & SDL_BUTTON_MMASK ? "true" : "false");
	printf("right = %s, ", buttons & SDL_BUTTON_RMASK ? "true" : "false");
	printf("x1 = %s, ", buttons & SDL_BUTTON_X1MASK ? "true" : "false");
	printf("x2 = %s\n", buttons & SDL_BUTTON_X2MASK ? "true" : "false");
}
































