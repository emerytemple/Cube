
#include <stdio.h>
#include <stdlib.h>

#include "main_menu.h" 

void *create_main_menu()
{
	struct MainMenu *main_menu = malloc(sizeof(struct MainMenu));

	return main_menu;
}

void main_menu_update(void *data)
{
	struct MainMenu *main_menu = (struct MainMenu *) data;

	printf("updating main menu\n");
}

void main_menu_render(void *data, int alpha)
{
	struct MainMenu *main_menu = (struct MainMenu *) data;

	printf("rendering main menul\n");
}

void destroy_main_menu(void *data)
{
	struct MainMenu *main_menu = (struct MainMenu *) data;

	free(main_menu);
}
