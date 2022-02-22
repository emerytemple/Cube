
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
		char *state = scene_state_to_string(scenes->scenes[i].state);
		printf("scene[%d] = %s, state = %s\n", i, scenes->scenes[i].name, state);
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

void push_scene(struct SceneStack *scenes, struct Scene *scene, enum SceneState state)
{
	if(isFull(scenes))
	{
		printf("cannot push scene. stack is full\n");
		return;
	}

	if(!isEmpty(scenes))
	{
		if(state == SCENE_ACTIVE)
		{
			printf("cannot have more than one active scene");
			return;
		}

		scenes->scenes[scenes->top].state = state;
	}

	scenes->top++;

	scenes->scenes[scenes->top] = *scene;
	scenes->scenes[scenes->top].state = SCENE_ACTIVE;
}

struct Scene *pop_scene(struct SceneStack *scenes)
{
	if(isEmpty(scenes)) return NULL;

	scenes->top--;
	scenes->scenes[scenes->top].state = SCENE_ACTIVE;

	return &scenes->scenes[scenes->top];
}

struct Scene *peek_scene(struct SceneStack *scenes)
{
	if(isEmpty(scenes)) return NULL;

	return &scenes->scenes[scenes->top];
}

void destroy_scene_stack(struct SceneStack *scenes)
{
	for(int i = 0; i <= scenes->capacity; i++)
	{
		destroy_scene(&scenes->scenes[scenes->top]);
	}

	free(scenes);
}

void stack_update(struct SceneStack *scenes)
{
	for(int i = 0; i <= scenes->top; i++)
	{
		struct Scene current = scenes->scenes[i];

		if(current.state == SCENE_ACTIVE || current.state == SCENE_INVISIBLE)
		{
			current.update(current.data);
		}
	}
}

void stack_render(struct SceneStack *scenes, int alpha)
{
	for(int i = 0; i <= scenes->top; i++)
	{
		struct Scene current = scenes->scenes[i];
		if(current.state == SCENE_ACTIVE || current.state == SCENE_PAUSED)
		{
			current.render(current.data, alpha);
		}
	}
}
























