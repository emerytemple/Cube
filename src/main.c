
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

SDL_Window *create_app();
void destroy_app(SDL_Window *window);

int main(int argc, char *argv[])
{
	SDL_Joystick *controller = NULL;

	SDL_Window *window = create_app();

	if(SDL_NumJoysticks() < 1)
	{
		puts("Warning: No Joysticks connected!\n");
	}

	controller = SDL_JoystickOpen(0);
	if(controller == NULL)
	{
		printf("Warning: Unable to open game controller! SDL_Error: %s\n", SDL_GetError());
	}

	bool quit = false;
	SDL_Event event;

	while(!quit)
	{
		while(SDL_PollEvent(&event))
		{
			handle_event(&quit, &event);
		}

		SDL_Surface *surface = SDL_GetWindowSurface(window);
		const SDL_Rect *rect = NULL;
		Uint32 color = SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF);
		int fill_success = SDL_FillRect(surface, rect, color);

		SDL_UpdateWindowSurface(window);
	}

	SDL_JoystickClose(controller);
	controller = NULL;

	destroy_app(window);
	window = NULL;

	return 0;
}

SDL_Window *create_app()
{
	int success = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK);
	if(success != 0) printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());

	const char *title = "Cube";
	int screen_width = 640;
	int screen_height = 480;
	Uint32 window_flags = 0;
	SDL_Window *window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screen_width, screen_height, window_flags);
	if(window == NULL) printf("SDL window could not be created! SDL_Error: %s\n", SDL_GetError());

	return window;
}

void destroy_app(SDL_Window *window)
{
	SDL_DestroyWindow(window);
	// window = NULL;

	SDL_Quit();
}
















