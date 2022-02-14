
#include "input.h"


void add_joystick(struct Joysticks *joysticks, Sint32 device_index)
{
	// int index = joysticks->num_joysticks++;
	joysticks->num_joysticks = SDL_NumJoysticks();

	joysticks->joystick_handle[device_index] = SDL_JoystickOpen(device_index);
	joysticks->is_joystick_open[device_index] = SDL_JoystickGetAttached(joysticks->joystick_handle[device_index]);

	joysticks->joystick_instance_id[device_index] = SDL_JoystickGetDeviceInstanceID(device_index);
	joysticks->joystick_name[device_index] = (char *)SDL_JoystickNameForIndex(device_index);

	/*
	joysticks->joystick_guid[device_index] = SDL_JoystickGetDeviceGUID(device_index);
	joysticks->joystick_player_index[device_index] = SDL_JoystickGetDevicePlayerIndex(device_index);
	joysticks->joystick_product[device_index] = SDL_JoystickGetDeviceProduct(device_index);
	joysticks->joystick_product_version[device_index] = SDL_JoystickGetDeviceProductVersion(device_index);
	joysticks->joystick_type[device_index] = SDL_JoystickGetDeviceType(device_index);
	joysticks->joystick_vendor[device_index] = SDL_JoystickGetDeviceVendor(device_index);

	// joysticks->joystick_serial_number[device_index] = (char *)SDL_JoystickGetSerial(joysticks->joystick_handle[device_index]);
*/
}

void remove_joystick(struct Joysticks *joysticks, Sint32 instance_id)
{
	int device_index;
	for(int i = 0; i < joysticks->num_joysticks; i++)
	{
		if(joysticks->joystick_instance_id[i] == instance_id)
		{
			device_index = i;
			break;
		}
	}

	if(SDL_JoystickGetAttached(joysticks->joystick_handle[device_index]))
	{
		SDL_JoystickClose(joysticks->joystick_handle[device_index]);
	}	

	joysticks->num_joysticks = SDL_NumJoysticks();
	joysticks->joystick_handle[device_index] = NULL;

	joysticks->is_joystick_open[device_index] = SDL_JoystickGetAttached(joysticks->joystick_handle[device_index]);

	joysticks->joystick_instance_id[device_index] = -1;
	joysticks->joystick_name[device_index] = "_";
}

void add_controller(struct Joysticks *joysticks, Sint32 index)
{
	// int index = joysticks->num_controllers++;

	joysticks->controller_handle[index] = SDL_GameControllerOpen(index);
	if(joysticks->controller_handle[index] == NULL)
	{
		printf("Warning: Unable to open game joystick! SDL_Error: %s\n", SDL_GetError());
	}
}

void remove_controller(struct Joysticks *joysticks, Sint32 index)
{
		if(!SDL_JoystickGetAttached(joysticks->joystick_handle[index]))
		{
			printf("error in controller remove. joystick is not attached\n");
			return;
		}

		if(!SDL_IsGameController(index))
		{
			printf("error in controller remove. joystick is not game controller\n");
			return;
		}

		if(!SDL_GameControllerGetAttached(joysticks->controller_handle[index]))
		{
			printf("error in cotnroller remove. controller is not attached\n");
			return;
		}

		SDL_GameControllerClose(joysticks->controller_handle[index]);
		joysticks->controller_handle[index] = NULL;
}

void print_input(struct Joysticks *joysticks)
{
	printf("\tnum joysticks = %d\n", SDL_NumJoysticks());
	// printf("\tnum controllers = %d\n", joysticks->num_controllers);
	for(int i = 0; i < 5; i++)
	{
		SDL_bool is_joystick_open = SDL_JoystickGetAttached(joysticks->joystick_handle[i]);
		char *joystick_name = (char *)SDL_JoystickName(joysticks->joystick_handle[i]);
		char *name_for_index = (char *)SDL_JoystickNameForIndex(i);
		printf("\tjoystick %d named %s and %s is %s", i, joystick_name, name_for_index, is_joystick_open ? "open" : "closed");
		if(SDL_IsGameController(i) && is_joystick_open)
		{
			SDL_bool is_controller_open = SDL_GameControllerGetAttached(joysticks->controller_handle[i]);
			char *controller_name = (char *)SDL_GameControllerNameForIndex(i);	
			if(is_controller_open)
			{
				printf(", controller %d named %s is %s", i, controller_name, is_controller_open ? "open" : "closed");
			}
		}
		printf("\n");
	}
}

void print_input2(struct Joysticks *joysticks)
{
	printf("\tnum joysticks = %d %d\n", joysticks->num_joysticks, SDL_NumJoysticks());
	for(int device_index = 0; device_index < 5; device_index++)
	{\
		printf("\tindex = %d, ", device_index);
		printf("state = %s, ", joysticks->is_joystick_open[device_index] ? "open" : "closed");
		printf("handle = %p, ", joysticks->joystick_handle[device_index]);
		printf("id = %d, ", joysticks->joystick_instance_id[device_index]);
		printf("name = %s\n", joysticks->joystick_name[device_index]);

/*
		char *guid;
		SDL_JoystickGetGUIDString(joysticks->joystick_guid[device_index], guid, sizeof(joysticks->joystick_guid[device_index]));
		printf("guid = %s, ", guid);

		printf("player_id = %d, ", joysticks->joystick_player_index[device_index]);
		printf("product = %d, ", joysticks->joystick_product[device_index]);
		printf("version = %d, ", joysticks->joystick_product_version[device_index]);

		printf("type = ");
		switch(joysticks->joystick_type[device_index])
		{
			case SDL_JOYSTICK_TYPE_UNKNOWN:
				printf("unknown");
				break;
			case SDL_JOYSTICK_TYPE_GAMECONTROLLER:
				printf("game controller");
				break;
			case SDL_JOYSTICK_TYPE_WHEEL:
				printf("wheel");
				break;
			case SDL_JOYSTICK_TYPE_ARCADE_STICK:
				printf("arcade stick");
				break;
			case SDL_JOYSTICK_TYPE_FLIGHT_STICK:
				printf("flight stick");
				break;
			case SDL_JOYSTICK_TYPE_DANCE_PAD:
				printf("dance pad");
				break;
			case SDL_JOYSTICK_TYPE_GUITAR:
				printf("guitar");
				break;
			case SDL_JOYSTICK_TYPE_DRUM_KIT:
				printf("drum kit");
				break;
			case SDL_JOYSTICK_TYPE_ARCADE_PAD:
				printf("arcade pad");
				break;
			case SDL_JOYSTICK_TYPE_THROTTLE:
				printf("throttle");
				break;
			default:
				break;
		}
		printf(", ");

		printf("vendor = %d, ", joysticks->joystick_vendor[device_index]);
*/
		// joysticks->joystick_serial_number[device_index] = (char *)SDL_JoystickGetSerial(joysticks->joystick_handle[device_index]);
	}
}

#if 0
void print_input2()
{
	int num_joysticks = SDL_NumJoysticks(); // attached joystick count
	printf("\tnum joysticks = %d\n", num_joysticks);

	SDL_Joystick *joystick[5];

	for(int i = 0; i < num_joysticks; i++)
	{
		SDL_bool is_joystick_open = SDL_JoystickGetAttached(joysticks->joystick_handle[i]);
		char *joystick_name = (char *)SDL_JoystickName(joysticks->joystick_handle[i]);
		printf("\tjoystick %d named %s is %s", i, joystick_name, is_joystick_open ? "open" : "closed");
	}
}
#endif

#if 0
void create_joysticks(struct Joysticks *joysticks)
{
	int joysticks->num_joysticks = SDL_NumJoysticks();
	if(joysticks->num_joysticks < 1) puts("Warning: No Joysticks connected!\n");

	printf("num joysticks = %d\n", joysticks->num_joysticks);

	for(int i = 0; i < num_joysticks; i++)
	{
		joystick[i] = SDL_JoystickOpen(i);
		if(joystick[i] == NULL) printf("Warning: Unable to open game joystick! SDL_Error: %s\n", SDL_GetError());

		printf("joystick %d = %s ", i, (char *)SDL_JoystickName(joystick[i]));

		if(SDL_IsGameController(i))
		{
			printf("is a compatible controller, named %s", SDL_GameControllerNameForIndex(i));
			controller[i] = SDL_GameControllerOpen(i);
			// char *mapping = SDL_GameControllerMapping(controller[i]);
			// printf("Controller %i is mapped as %s\n", i, mapping);
		}

		printf("\n");
	}

	// destroy and close
	for(int i = 0; i < num_joysticks; i++)
	{
		if(!SDL_JoystickGetAttached(joystick[i]))
			break;

		if(SDL_IsGameController(i) && SDL_GameControllerGetAttached(controller[i]))
		{
			SDL_GameControllerClose(controller[i]);
			controller[i] = NULL;
		}

		SDL_JoystickClose(joystick[i]);
		joystick[i] = NULL;
	}

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

#endif






























