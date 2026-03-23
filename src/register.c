#include "pico/stdlib.h"
#include "register.h"

static uint8_t reg = 0;
int pins[8] = {2,3,4,5,6,7,8,9};

void reg_display(uint8_t value)
{
	for(int i=0; i<8; i++)
	{
		gpio_put(pins[i], (value>>i)&1);
	}
}

void reg_shift_in(uint8_t bit)
{
	reg <<= 1;
	reg |= bit;
	reg_display(reg);
}

void reg_clear()
{
	reg = 0;
	reg_display(reg);
}

uint8_t reg_get_value()
{
	return reg;
}
