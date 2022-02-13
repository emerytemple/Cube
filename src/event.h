
#ifndef _EVENT_H_
#define _EVENT_H_

#include <SDL.h>
#include <stdbool.h>

#include "input.h"

void handle_event(SDL_Event *event, bool *quit, struct Joysticks *joysticks);

void handle_controllerdevice_event(SDL_ControllerDeviceEvent cdevice, struct Joysticks *joysticks);
void handle_joydevice_event(SDL_JoyDeviceEvent jdevice, struct Joysticks *joysticks);
void handle_window_event(SDL_WindowEvent window);


#endif
