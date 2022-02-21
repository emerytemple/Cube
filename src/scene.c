
#include <stdio.h>
#include <stdlib.h>

#include "scene.h"

struct Scene *create_scene(char *name, void *data, update_fp update, render_fp render)
{
	struct Scene *scene = malloc(sizeof(struct Scene));

	scene->name = name;
	scene->data = data;
	scene->update = update;
	scene->render = render;
	scene->state = SCENE_STOPPED;

	return scene;
}

char *scene_state_to_string(enum SceneState scene_state)
{
	char *state;
	switch(scene_state)
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

	return state;
}

void print_scene(struct Scene *scene)
{
	char *state = scene_state_to_string(scene->state);

	printf("scene %s, state = %s\n", scene->name, state);
}

void destroy_scene(struct Scene *scene)
{
	free(scene);
}
