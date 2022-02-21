
#ifndef _SCENE_H_
#define _SCENE_H_

typedef void (*update_fp)(void *);
typedef void (*render_fp)(void *, int);

/* available states are:
	'stopped'   // no update, no render, no data (start/stop)
	'asleep'    // no update, no render,    data (sleep/wake)
	'paused'    // no update,    render,    data (pause/resume)
	'invisible' // update,    no render,    data (show/hide)
	'active'    // update,       render,    data (activate/deactivate)
*/

enum SceneState {
	SCENE_STOPPED,
	SCENE_ASLEEP,
	SCENE_PAUSED,
	SCENE_INVISIBLE,
	SCENE_ACTIVE
};

struct Scene {
	const char *name;
	void *data;
	update_fp update;
	render_fp render;
	enum SceneState state;
};

struct Scene *create_scene(char *name, void *data, update_fp update, render_fp render);
char *scene_state_to_string(enum SceneState state);
void print_scene(struct Scene *scene);
void destroy_scene(struct Scene *scene);

#endif
