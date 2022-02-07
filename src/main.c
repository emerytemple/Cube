
//       |
//     __|__
//     _| |__
//    / |_|/|
//   /____/ |
//   |    | /
//   |____|/

#include <SDL.h>
#include <stdbool.h>
#include <stdio.h>

#include "event.h"
#include "input.h"
#include "render.h"

int main(int argc, char *argv[])
{
	SDL_Joystick *controller = NULL;

	struct RawInput raw_input = {
		.joy_axis_value[0] = 0,
		.joy_axis_value[1] = 0,
		.joy_axis_value[2] = -1,
		.joy_axis_value[3] = 0,
		.joy_axis_value[4] = 0,
		.joy_axis_value[5] = -1,

		.joy_hat_value = 0,
	};
	print_input(&raw_input);

	int success = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK);

	if(success != 0) printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	if(SDL_NumJoysticks() < 1) puts("Warning: No Joysticks connected!\n");

	SDL_bool hint = SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
	if(!hint) printf("Warning: Linear texture filtering not enabled!");

	const char *title = "Cube";
	int screen_width = 800;
	int screen_height = 600;
	Uint32 window_flags = 0;
	SDL_Window *window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screen_width, screen_height, window_flags);
	if(window == NULL) printf("SDL window could not be created! SDL_Error: %s\n", SDL_GetError());

	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if(renderer == NULL) printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());

	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

	controller = SDL_JoystickOpen(0);
	if(controller == NULL) printf("Warning: Unable to open game controller! SDL_Error: %s\n", SDL_GetError());

	bool quit = false;
	SDL_Event event;

	while(!quit)
	{
		while(SDL_PollEvent(&event))
		{
			handle_event(&event, &quit, &raw_input);
		}

		render(renderer, &raw_input);
	}

	SDL_JoystickClose(controller);
	controller = NULL;

	// SDL_DestroyRenderer(renderer);
	renderer = NULL;

	// SDL_DestroyWindow(window);
	window = NULL;

	SDL_Quit();

	return 0;
}












