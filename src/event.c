
#include <stdio.h>

#include "event.h"

void handle_event(SDL_Event *event, bool *quit) // return quit?
{
	switch(event->type)
	{
		case SDL_QUIT:
			*quit = true;
			break;
		case SDL_WINDOWEVENT:
			// handle_window_event(event->window);
			break;
		default:
			break;
	}
}

void handle_window_event(SDL_WindowEvent window)
{
	switch(window.event)
	{
		case SDL_WINDOWEVENT_SHOWN:
			printf("Window %d shown\n", window.windowID);
			break;
		case SDL_WINDOWEVENT_HIDDEN:
			printf("Window %d hidden\n", window.windowID);
			break;
		case SDL_WINDOWEVENT_EXPOSED:
			printf("Window %d exposed\n", window.windowID);
			break;
		case SDL_WINDOWEVENT_MOVED:
			printf("Window %d moved to (%d, %d)\n", window.windowID, window.data1, window.data2);
			break;
		case SDL_WINDOWEVENT_RESIZED:
			printf("Window %d resized to %d x %d\n", window.windowID, window.data1, window.data2);
			break;
		case SDL_WINDOWEVENT_SIZE_CHANGED:
			printf("Window %d size change to %d x %d\n", window.windowID, window.data1, window.data2);
			break;
		case SDL_WINDOWEVENT_MINIMIZED:
			printf("Window %d minimized\n", window.windowID);
			break;
		case SDL_WINDOWEVENT_MAXIMIZED:
			printf("Window %d maximized\n", window.windowID);
			break;
		case SDL_WINDOWEVENT_RESTORED:
			printf("Window %d restored\n", window.windowID);
			break;
		case SDL_WINDOWEVENT_ENTER:
			printf("Mouse entered window %d\n", window.windowID);
			break;
		case SDL_WINDOWEVENT_LEAVE:
			printf("Mouse left window %d\n", window.windowID);
			break;
		case SDL_WINDOWEVENT_FOCUS_GAINED:
			printf("Window %d gained keyboard focus\n", window.windowID);
			break;
		case SDL_WINDOWEVENT_FOCUS_LOST:
			printf("Window %d lost keyboard focus\n", window.windowID);
			break;
		case SDL_WINDOWEVENT_CLOSE:
			printf("Window %d closed\n", window.windowID);

			SDL_Event event;
			event.type = SDL_QUIT;
			SDL_PushEvent(&event);

			break;
		case SDL_WINDOWEVENT_TAKE_FOCUS:
			printf("Window %d is offered a focus\n", window.windowID);
			break;
		case SDL_WINDOWEVENT_HIT_TEST:
			printf("Window %d has a special hit test\n", window.windowID);
			break;
		default:
			printf("Window %d got unknown event %d\n", window.windowID, window.event);
			break;
	}
}












