
#include <SDL.h>
#include <stdbool.h>
#include <stdio.h>

#include <stdlib.h>

void get_joystick_input();

int main(int argc, char *argv[])
{
	int success = SDL_Init(SDL_INIT_EVERYTHING);
	if(success != 0) printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());

	SDL_bool hint = SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
	if(!hint) printf("Warning: Linear texture filtering not enabled!");

	SDL_Window *window = SDL_CreateWindow("Cube", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_RESIZABLE);
	if(window == NULL) printf("SDL window could not be created! SDL_Error: %s\n", SDL_GetError());

	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if(renderer == NULL) printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());

	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

	bool quit = false;
	SDL_Event event;

	while(!quit)
	{
		while(SDL_PollEvent(&event))
		{
			switch(event.type)
			{
				case SDL_JOYDEVICEADDED:
				case SDL_JOYDEVICEREMOVED:
					// printf("joystick event\n");
					break;
				case SDL_QUIT:
					quit = true;
					break;
				default:
					break;
			}
		}

		SDL_PumpEvents();
		get_joystick_input();
	}

	renderer = NULL;
	window = NULL;

	SDL_Quit();

	return 0;
}

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
















































