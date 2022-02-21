
#include <stdio.h>
#include <stdlib.h>

#include "settings.h" 

void *create_settings()
{
	struct Settings *settings = malloc(sizeof(struct Settings));

	return settings;
}

void settings_update(void *data)
{
	struct Settings *settings = (struct Settings *) data;

	printf("updating settings\n");
}

void settings_render(void *data, int alpha)
{
	struct Settings *settings = (struct Settings *) data;

	printf("rendering settings\n");
}

void destroy_settings(void *data)
{
	struct Settings *settings = (struct Settings *) data;

	free(settings);
}
