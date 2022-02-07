
#ifndef _RENDER_H_
#define _RENDER_H_

#include <SDL.h>

#include "input.h"

void render(SDL_Renderer *renderer, struct RawInput *input);
void draw_circle(SDL_Renderer * renderer, int32_t centreX, int32_t centreY, int32_t radius);

#endif
