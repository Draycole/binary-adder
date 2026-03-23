#include "pico/stdlib.h"
#include "gpio_driver.h"
#include "state_machine.h"

int main()
{
	stdio_init_all();
	gpio_driver_init();

	while(1)
	{
		system_update();
	}
}
