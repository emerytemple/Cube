
#ifndef _LEVEL_H_
#define _LEVEL_H_

struct Level {
	int a;
};

void *create_level();
void level_update(void *data);
void level_render(void *data, int alpha);
void destroy_level(void *data);

#endif
