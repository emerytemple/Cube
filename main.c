
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

SDL_Window *create_app();
void destroy_app(SDL_Window *window);

int main(int argc, char *argv[])
{
	SDL_Window *window = create_app();

	SDL_Event event;

	SDL_Surface *surface = SDL_GetWindowSurface(window);
	const SDL_Rect *rect = NULL;
	Uint32 color = SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF);
	int fill_success = SDL_FillRect(surface, rect, color);

	SDL_UpdateWindowSurface(window);

	Uint32 ms = 2000;
	SDL_Delay(ms);

	destroy_app(window);

	return 0;
}

SDL_Window *create_app()
{
	Uint32 init_flags = SDL_INIT_VIDEO;
	int success = SDL_Init(init_flags);
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



















