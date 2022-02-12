
#ifndef _EVENT_H_
#define _EVENT_H_

#include <SDL.h>
#include <stdbool.h>

#include "input.h"

void handle_event(SDL_Event *event, bool *quit); // note(emery): return quit?
void handle_window_event(SDL_WindowEvent window);

#endif
