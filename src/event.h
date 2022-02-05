
#ifndef _EVENT_H_
#define _EVENT_H_

#include <SDL.h>
#include <stdbool.h>

void handle_event(bool *quit, SDL_Event *event); // note(emery): return quit?

void handle_keyboard_event(SDL_KeyboardEvent key);

void handle_joy_axis_event(SDL_JoyAxisEvent jaxis);
void handle_joy_hat_event(SDL_JoyHatEvent jhat); // dpad
void handle_joy_button_event(SDL_JoyButtonEvent jbutton);
void handle_joy_device_event(SDL_JoyDeviceEvent jdevice);

void handle_mouse_motion_event(SDL_MouseMotionEvent motion);
void handle_mouse_button_event(SDL_MouseButtonEvent button);
void handle_mouse_wheel_event(SDL_MouseWheelEvent wheel);

#endif
