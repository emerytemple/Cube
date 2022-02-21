
#include <stdio.h>
#include <stdlib.h>

#include "level.h" 

void *create_level()
{
	struct Level *level = malloc(sizeof(struct Level));

	return level;
}

void level_update(void *data)
{
	struct Level *level = (struct Level *) data;

	printf("updating level\n");
}

void level_render(void *data, int alpha)
{
	struct Level *level = (struct Level *) data;

	printf("rendering level\n");
}

void destroy_level(void *data)
{
	struct Level *level = (struct Level *) data;

	free(level);
}
