
#include <stdio.h>
#include <stdlib.h>

#include "world_map.h" 

void *create_world_map()
{
	struct WorldMap *world_map = malloc(sizeof(struct WorldMap));

	return world_map;
}

void world_map_update(void *data)
{
	struct WorldMap *world_map = (struct WorldMap *) data;

	printf("updating world map\n");
}

void world_map_render(void *data, int alpha)
{
	struct WorldMap *world_map = (struct WorldMap *) data;

	printf("rendering world map\n");
}

void destroy_world_map(void *data)
{
	struct WorldMap *world_map = (struct WorldMap *) data;

	free(world_map);
}
