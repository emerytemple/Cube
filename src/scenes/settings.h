
#ifndef _SETTINGS_H_
#define _SETTINGS_H_

struct Settings {
	int a;
};

void *create_settings();
void settings_update(void *data);
void settings_render(void *data, int alpha);
void destroy_settings(void *data);

#endif
