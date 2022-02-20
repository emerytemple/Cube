
#include <stdlib.h>

#include "scenestack.h"

struct SceneStack *create_scene_stack(int capacity)
{
	struct SceneStack *scenes = malloc(sizeof(struct SceneStack));

	scenes->top = -1; // current active scene (the one that gets input)
	scenes->capacity = capacity;
	scenes->scenes = malloc(capacity * sizeof(struct Scene));

	return scenes;
}

bool isFull(struct SceneStack *scenes)
{
	return scenes->top == stack->capacity - 1;
}

bool isEmpty(struct SceneStack *scenes)
{
	return scenes->top == -1;
}

void push_scene(struct SceneStack *scenes, struct Scene *scene)
{
	if(isFull(scenes)) return;

	scenes->top++;
	scenes->scenes[scenes->top] = scene;
}

struct Scene *pop_scene(struct SceneStack *scenes)
{
	if(isEmpty(scenes)) return;

	struct Scene scene = scenes->scenes[scenes->top];
	scenes->top--;

	return scene;
}

struct Scene *peek_scene(struct SceneStack *scenes)
{
	if(isEmpty(scenes)) return;

	return scenes->scenes[scenes->top];
}

void destroy_scene_stack(struct SceneStack *scenes)
{
	free(scenes);
}
