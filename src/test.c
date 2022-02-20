
#include <SDL.h>
#include <stdbool.h>
#include <stdio.h>

#include <stdlib.h>

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
				case SDL_QUIT:
					quit = true;
					break;
				default:
					break;
			}
		}

		SDL_PumpEvents();

	}

	renderer = NULL;
	window = NULL;

	SDL_Quit();

	return 0;
}
















































