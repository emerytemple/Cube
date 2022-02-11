
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
// #include "render.h"

#include <stdlib.h>

int main(int argc, char *argv[])
{
	int success = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK | SDL_INIT_GAMECONTROLLER);
	if(success != 0) printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());

	create_joysticks();

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

	bool quit = false;
	SDL_Event event;

	while(!quit)
	{
		while(SDL_PollEvent(&event))
		{
			handle_event(&event, &quit);
		}

		SDL_PumpEvents();
		get_mouse_input();
		// get_keyboard_input();
		// poll_input(joystick);
		// render(renderer, &raw_input);
	}

	destroy_joysticks();

	// SDL_DestroyRenderer(renderer);
	renderer = NULL;

	// SDL_DestroyWindow(window);
	window = NULL;

	SDL_Quit();

	return 0;
}










