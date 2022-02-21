
#ifndef _MAIN_MENU_H_
#define _MAIN_MENU_H_

struct MainMenu {
	int a;
};

void *create_main_menu();
void main_menu_update(void *data);
void main_menu_render(void *data, int alpha);
void destroy_main_menu(void *data);

#endif
