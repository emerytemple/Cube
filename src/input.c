
#include "input.h"

void create_joysticks()
{
	struct Joysticks joysticks;

	joysticks.num_joysticks = SDL_NumJoysticks();
	if(joysticks.num_joysticks < 1) puts("Warning: No Joysticks connected!\n");

	for(int i = 0; i < joysticks.num_joysticks; i++)
	{
		joysticks.joystick[i] = SDL_JoystickOpen(i);
		if(joysticks.joystick[i] == NULL) printf("Warning: Unable to open game joystick! SDL_Error: %s\n", SDL_GetError());

		initialize_raw_joystick(i, joysticks.joystick[i], &joysticks.raw_joystick[i]);
		print_raw_joystick(&joysticks.raw_joystick[i]);
	}

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






