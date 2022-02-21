
#ifndef _WORLD_MAP_H_
#define _WORLD_MAP_H_

struct WorldMap {
	int a;
};

void *create_world_map();
void world_map_update(void *data);
void world_map_render(void *data, int alpha);
void destroy_world_map(void *data);

#endif
