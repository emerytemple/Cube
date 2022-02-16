
#include "render.h"

void render(SDL_Renderer *renderer)
{
	// clear screen
	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
	SDL_RenderClear(renderer);

	// box 1
	SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
	SDL_RenderDrawRect(renderer, &(SDL_Rect) { 10, 10, 200, 200 });
	SDL_RenderDrawLine(renderer, 110, 10, 110, 210);
	SDL_RenderDrawLine(renderer, 10, 110, 210, 110);
	draw_circle(renderer, 110, 110, 100);

	// box 1 dead zone
	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xFF, 0xFF);
	draw_circle(renderer, 110, 110, 25);
	draw_circle(renderer, 110, 110, 90);

	// box 1 raw value
	SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0x00, 0xFF);
	// double xvalue = (input->joy_axis_value[0]) ? input->joy_axis_value[0]/32768.0: input->joy_axis_value[0]/32767.0;
	// double yvalue = (input->joy_axis_value[1]) ? input->joy_axis_value[1]/32768.0: input->joy_axis_value[1]/32767.0;
	// SDL_RenderDrawRect(renderer, &(SDL_Rect) { 105.0*(1.0 + xvalue), 105.0*(1.0 + yvalue), 10, 10 });


	SDL_RenderPresent(renderer);
}

void draw_circle(SDL_Renderer *renderer, int32_t centreX, int32_t centreY, int32_t radius)
{
   const int32_t diameter = (radius * 2);

   int32_t x = (radius - 1);
   int32_t y = 0;
   int32_t tx = 1;
   int32_t ty = 1;
   int32_t error = (tx - diameter);

   while (x >= y)
   {
      //  Each of the following renders an octant of the circle
      SDL_RenderDrawPoint(renderer, centreX + x, centreY - y);
      SDL_RenderDrawPoint(renderer, centreX + x, centreY + y);
      SDL_RenderDrawPoint(renderer, centreX - x, centreY - y);
      SDL_RenderDrawPoint(renderer, centreX - x, centreY + y);
      SDL_RenderDrawPoint(renderer, centreX + y, centreY - x);
      SDL_RenderDrawPoint(renderer, centreX + y, centreY + x);
      SDL_RenderDrawPoint(renderer, centreX - y, centreY - x);
      SDL_RenderDrawPoint(renderer, centreX - y, centreY + x);

      if (error <= 0)
      {
         ++y;
         error += ty;
         ty += 2;
      }

      if (error > 0)
      {
         --x;
         tx += 2;
         error += (tx - diameter);
      }
   }
}
