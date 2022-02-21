
#include <stdio.h>
#include <stdlib.h>

#include "scene_stack.h"

struct SceneStack *create_scene_stack(int capacity)
{
	struct SceneStack *scenes = malloc(sizeof(struct SceneStack));

	scenes->top = -1; // current active scene (the one that gets input)
	scenes->capacity = capacity;
	scenes->scenes = malloc(capacity * sizeof(struct Scene));

	return scenes;
}

void print_scene_stack(struct SceneStack *scenes)
{
	for(int i = 0; i <= scenes->top; i++)
	{
		printf("scene[%d] = %s\n", i, scenes->scenes[i].name);
	}
}

bool isFull(struct SceneStack *scenes)
{
	return scenes->top == scenes->capacity - 1;
}

bool isEmpty(struct SceneStack *scenes)
{
	return scenes->top == -1;
}

void push_scene(struct SceneStack *scenes, struct Scene *scene)
{
	if(isFull(scenes)) return;

	scenes->top++;
	scenes->scenes[scenes->top] = *scene;
}

struct Scene *pop_scene(struct SceneStack *scenes)
{
	if(isEmpty(scenes)) return NULL;

	return &scenes->scenes[scenes->top--];
}

struct Scene *peek_scene(struct SceneStack *scenes)
{
	if(isEmpty(scenes)) return NULL;

	return &scenes->scenes[scenes->top];
}

void destroy_scene_stack(struct SceneStack *scenes)
{
	free(scenes);
}

void stack_update(struct SceneStack *scenes)
{
	for(int i = 0; i <= scenes->top; i++)
	{
		struct Scene current = scenes->scenes[i];
		// if(current.state == STATE_ACTIVE || ...) // add this later
		current.update(current.data);
	}
}

void stack_render(struct SceneStack *scenes, int alpha)
{
	for(int i = 0; i <= scenes->top; i++)
	{
		struct Scene current = scenes->scenes[i];
		current.render(current.data, alpha);
	}
}
























