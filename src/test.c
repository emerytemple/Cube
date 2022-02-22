
#include <SDL.h>
#include <stdbool.h>
#include <stdio.h>

#include <stdlib.h>

#include "scene.h"
#include "scene_stack.h"

#include "scenes/main_menu.h"
#include "scenes/settings.h"
#include "scenes/world_map.h"
#include "scenes/level.h"

int main()
{
	struct MainMenu *main_menu = create_main_menu();
	struct Settings *settings = create_settings();
	struct WorldMap *world_map = create_world_map();
	struct Level *level = create_level();

	struct Scene *main_menu_scene = create_scene("main menu", main_menu, main_menu_update, main_menu_render);
	struct Scene *settings_scene = create_scene("settings", settings, settings_update, settings_render);
	struct Scene *world_map_scene = create_scene("world map", world_map, world_map_update, world_map_render);
	struct Scene *level_scene = create_scene("level", level, level_update, level_render);

	struct SceneStack *stack = create_scene_stack(5);

	push_scene(stack, main_menu_scene, SCENE_NONE);
	push_scene(stack, settings_scene, SCENE_STOPPED);
	push_scene(stack, world_map_scene, SCENE_ASLEEP);
	push_scene(stack, level_scene, SCENE_PAUSED);

	print_scene_stack(stack);

	int alpha = 0.5;
	stack_update(stack);
	stack_render(stack, alpha);

	return 0;
}



#if 0
int main(int argc, char *argv[])
{
	int success = SDL_Init(SDL_INIT_EVERYTHING);
	if(success != 0) printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());

	SDL_bool hint = SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
	if(!hint) printf("Warning: Linear texture filtering not enabled!");

	SDL_Window *window = SDL_CreateWindow("Cube", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_RESIZABLE);
	if(window == NULL) printf("SDL window could not be created! SDL_Error: %s\n", SDL_GetError());

	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if(renderer == NULL) printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());

	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

	bool quit = false;
	SDL_Event event;

	while(!quit)
	{
		while(SDL_PollEvent(&event))
		{
			switch(event.type)
			{
				case SDL_QUIT:
					quit = true;
					break;
				default:
					break;
			}
		}

		SDL_PumpEvents();

	}

	renderer = NULL;
	window = NULL;

	SDL_Quit();

	return 0;
}

#endif














































