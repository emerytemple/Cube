
#include <stdio.h>

#include "event.h"

void handle_event(SDL_Event *event, bool *quit, struct Joysticks *joysticks)
{
	switch(event->type)
	{
		case SDL_CONTROLLERDEVICEADDED:
		case SDL_CONTROLLERDEVICEREMOVED:
		case SDL_CONTROLLERDEVICEREMAPPED:
			// printf("controller event\n");
			handle_controllerdevice_event(event->cdevice, joysticks);
			break;
		case SDL_JOYDEVICEADDED:
		case SDL_JOYDEVICEREMOVED:
			// printf("joystick event\n");
			handle_joydevice_event(event->jdevice, joysticks);
			break;
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

void handle_controllerdevice_event(SDL_ControllerDeviceEvent cdevice, struct Joysticks *joysticks)
{
	switch(cdevice.type)
	{
		case SDL_CONTROLLERDEVICEADDED:
			// printf("Controller %d added\n", cdevice.which);
			// add_controller(joysticks, cdevice.which);
			// print_input(joysticks);
			break;
		case SDL_CONTROLLERDEVICEREMOVED:
			// printf("Controller %d removed\n", cdevice.which);
			// remove_controller(joysticks, cdevice.which);
			// print_input(joysticks);
			break;
		case SDL_CONTROLLERDEVICEREMAPPED:
			printf("Controller %d remapped\n", cdevice.which);
			break;
		default:
			break;
	}
}

void handle_joydevice_event(SDL_JoyDeviceEvent jdevice, struct Joysticks *joysticks)
{
	switch(jdevice.type)
	{
		case SDL_JOYDEVICEADDED:
			printf("Joystick %d added\n", jdevice.which);
			add_joystick(joysticks, jdevice.which);
			print_input2(joysticks);
			break;
		case SDL_JOYDEVICEREMOVED:
			printf("Joystick %d removed\n", jdevice.which);
			remove_joystick(joysticks, jdevice.which);
			print_input2(joysticks);
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

void print_controller()
{

}












