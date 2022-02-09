
#ifndef _VIRTUAL_JOYSTICK_H_
#define _VIRTUAL_JOYSTICK_H_

#include <SDL.h>

int create_virtual_joystick();
void set_virtual_joystick(SDL_Joystick *joystick);
void destroy_virtual_joystick(int device_index);

#endif
