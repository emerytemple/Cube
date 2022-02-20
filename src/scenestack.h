

#ifndef _SCNESTACK_H_
#define _SCENESTACK_H_

#include <stdbool.h>

#include "scene.h"

struct SceneStack {
	int active_scene;
	int capacity;

	struct Scene *scenes;
};

struct SceneStack *create_scene_stack(int capacity);
bool isFull(struct SceneStack *scenes); // change instance variable to stack, also in .c
bool isEmpty(struct SceneStack *scenes);
void push_scene(struct SceneStack *scenes, struct Scene *scene);
struct Scene *pop_scene(struct SceneStack *scenes);
struct Scene *peek_scene(struct SceneStack *scenes);
void destroy_scene_stack(struct SceneStack *scenes);

#endif
