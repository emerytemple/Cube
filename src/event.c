
#include <stdio.h>

#include "event.h"

void handle_event(SDL_Event *event, bool *quit)
{
	switch(event->type)
	{
		case SDL_QUIT:
			*quit = true;
			break;
#if 0
		case SDL_KEYDOWN:
		case SDL_KEYUP:
			handle_keyboard_event(event->key);
			break;
		case SDL_JOYAXISMOTION:
			handle_joy_axis_event(event->jaxis, input);
			break;
		case SDL_JOYHATMOTION:
			handle_joy_hat_event(event->jhat, input);
			break;
		case SDL_JOYBUTTONDOWN:
		case SDL_JOYBUTTONUP:
			handle_joy_button_event(event->jbutton, input);
			break;
		case SDL_JOYDEVICEADDED:
		case SDL_JOYDEVICEREMOVED:
			handle_joy_device_event(event->jdevice);
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
#endif
		default:
			break;
	}
}

#if 0
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

void handle_joy_axis_event(SDL_JoyAxisEvent jaxis, struct RawInput *input)
{
	input->joy_axis_value[jaxis.axis] = jaxis.value;
	print_input(input);
}

void handle_joy_hat_event(SDL_JoyHatEvent jhat, struct RawInput *input)
{
	input->joy_hat_value = jhat.value;
	print_input(input);
}

void handle_joy_button_event(SDL_JoyButtonEvent jbutton, struct RawInput *input)
{
	printf("type = %d, button = %d, state = %d\n", jbutton.type, jbutton.button, jbutton.state);
}

void handle_joy_device_event(SDL_JoyDeviceEvent jdevice)
{

}

void handle_mouse_motion_event(SDL_MouseMotionEvent motion)
{
	// printf("x = %d, y = %d, xrel = %d, yrel = %d\n", motion.x, motion.y, motion.xrel, motion.yrel);
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

#endif
















