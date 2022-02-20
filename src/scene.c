
#include <stdlib.h>

#include "scene.h"

struct Scene *create_scene(char *name, void *data, update_fp *update, render_fp *render)
{
	struct Scene *scene = malloc(sizeof(struct Scene));

	scene->name = name;
	scene->data = data;
	scene->update = update;
	scene->render = render;
	scene->state = SCENE_STOPPED;

	return scene;
}

void print_scene(struct Scene *scene)
{
	char *state;
	switch(scene->state)
	{
		case SCENE_STOPPED:
			state = "stopped";
			break;
		case SCENE_ASLEEP:
			state = "asleep";
			break;
		case SCENE_PAUSED:
			state = "paused";
			break;
		case SCENE_INVISIBLE:
			state = "invisible";
			break;
		case SCENE_ACTIVE:
			state = "active";
			break;
		default:
			state = "unknown";
			break;
	}

	printf("scene %s, state = %s\n", state);
}

void destroy_scene(struct Scene *scene)
{
	free(scene);
}
