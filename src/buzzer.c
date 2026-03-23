#include "pico/stdlib.h"
#include "buzzer.h"

#define BUZZ 19

void tone(int delay)
{
	for(int i=0; i<delay; i++)
	{
		gpio_put(BUZZ, 1);
		sleep_us(500);
		gpio_put(BUZZ, 0);
		sleep_us(500);
	}
}

void buzz_one(){ tone(100); }
void buzz_zero(){ tone(40); }
void buzz_eval(){ tone(200); }
void buzz_overflow(){ tone(400); }
