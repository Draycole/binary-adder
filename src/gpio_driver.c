#include "pico/stdlib.h"
#include "gpio_driver.h"

int reg_pins[8] = {2,3,4,5,6,7,8,9};

void gpio_driver_init()
{
	for(int i=0; i<8; i++)
	{
		gpio_init(reg_pins[i]);
		gpio_set_dir(reg_pins[i], GPIO_OUT);
	}

	int outs[] = {15,16,17,18,19};
	for(int i=0; i<5; i++)
	{
		gpio_init(outs[i]);
		gpio_set_dir(outs[i], GPIO_OUT);
	}

	int ins[] = {10,11,12,13,14};
	for(int i=0; i<5; i++)
	{
		gpio_init(ins[i]);
		gpio_set_dir(ins[i], GPIO_IN);
		gpio_pull_up(ins[i]);
	}
}
