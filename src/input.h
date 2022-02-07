
#ifndef _INPUT_H_
#define _INPUT_H_

#include <SDL.h>

struct RawInput {
	Sint16 joy_axis_value[6];
	Uint8 joy_hat_value;
};

void print_input(struct RawInput *input);

#endif
