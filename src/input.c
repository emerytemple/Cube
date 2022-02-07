
#include "input.h"

void print_input(struct RawInput *input)
{
	printf("joy axis  ");
	for(int i = 0; i < 6; i++)
	{
		printf("%d  ", input->joy_axis_value[i]);
	}
	printf("\n");

	printf("hat  %d\n", input->joy_hat_value);

	printf("\n");
}
