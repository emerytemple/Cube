
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
void handle_event(bool *quit, SDL_Event *event); // note(emery): return quit?
void handle_keyboard_event(SDL_KeyboardEvent key);
void handle_mouse_motion_event(SDL_MouseMotionEvent motion);
void handle_mouse_button_event(SDL_MouseButtonEvent button);
void handle_mouse_wheel_event(SDL_MouseWheelEvent wheel);



int main(int argc, char *argv[])
{
	SDL_Window *window = create_app();

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

	destroy_app(window);

	return 0;
}

SDL_Window *create_app()
{
	int success = SDL_Init(SDL_INIT_VIDEO);
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

void handle_event(bool *quit, SDL_Event *event)
{
	switch(event->type)
	{
		case SDL_QUIT:
			*quit = true;
			break;
		case SDL_KEYDOWN:
		case SDL_KEYUP:
			handle_keyboard_event(event->key);
			break;
		case SDL_MOUSEMOTION:
			handle_mouse_motion_event(event->motion);
			break;
		case SDL_MOUSEBUTTONDOWN:
		case SDL_MOUSEBUTTONUP:
			handle_mouse_button_event(event->button);
			break;
		case SDL_MOUSEWHEEL:
			handle_mouse_wheel_event(event->wheel);
			break;
		default:
			break;
	}
}

void handle_keyboard_event(SDL_KeyboardEvent key)
{
	printf("type = %s, state = %s, repeat = %s\n",
		(key.type == SDL_KEYDOWN) ? "keydown" : "keyup",
		(key.state == SDL_PRESSED) ? "pressed" : "released",
		(key.repeat != 0) ? "repeat" : "single"
	);
	switch(key.keysym.sym)
	{
		case SDLK_UP:
			puts("up");
			break;
		case SDLK_DOWN:
			puts("down");
			break;
		case SDLK_LEFT:
			puts("left");
			break;
		case SDLK_RIGHT:
			puts("right");
			break;
		default:
			break;
	}
}

void handle_mouse_motion_event(SDL_MouseMotionEvent motion)
{
	printf("x = %d, y = %d, xrel = %d, yrel = %d\n", motion.x, motion.y, motion.xrel, motion.yrel);
}

void handle_mouse_button_event(SDL_MouseButtonEvent button)
{
	switch(button.button)
	{
		case SDL_BUTTON_LEFT:
			puts("button left");
			break;
		case SDL_BUTTON_MIDDLE:
			puts("button middle");
			break;
		case SDL_BUTTON_RIGHT:
			puts("button right");
			break;
		case SDL_BUTTON_X1:
			puts("button x1");
			break;
		case SDL_BUTTON_X2:
			puts("button x2");
			break;
		default:
			break;
	}
}

void handle_mouse_wheel_event(SDL_MouseWheelEvent wheel)
{
	printf("x = %d, y = %d\n", wheel.x, wheel.y);
}
















