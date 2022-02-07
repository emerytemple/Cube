
#ifndef _EVENT_H_
#define _EVENT_H_

#include <SDL.h>
#include <stdbool.h>

#include "input.h"

void handle_event(SDL_Event *event, bool *quit, struct RawInput *input); // note(emery): return quit?

void handle_keyboard_event(SDL_KeyboardEvent key);

void handle_joy_axis_event(SDL_JoyAxisEvent jaxis, struct RawInput *input);
void handle_joy_hat_event(SDL_JoyHatEvent jhat, struct RawInput *input); // dpad
void handle_joy_button_event(SDL_JoyButtonEvent jbutton, struct RawInput *input);
void handle_joy_device_event(SDL_JoyDeviceEvent jdevice);

void handle_mouse_motion_event(SDL_MouseMotionEvent motion);
void handle_mouse_button_event(SDL_MouseButtonEvent button);
void handle_mouse_wheel_event(SDL_MouseWheelEvent wheel);

#endif
