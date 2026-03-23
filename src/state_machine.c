#include "state_machine.h"
#include "register.h"
#include "buttons.h"
#include "alu.h"
#include "buzzer.h"
#include "pico/stdlib.h"

#define ADD_LED 15
#define SUB_LED 16
#define EVAL_LED 17
#define OVF_LED 18 //overflow led

typedef enum{
	ENTER_A,
	ENTER_B,
	SHOW_RESULT
}state_t;

static state_t state = ENTER_A;

static uint8_t A = 0;
static uint8_t B = 0;
static int mode = 0; //1 for add, 2 for sub

void system_update()
{
	switch(state)
	{

		case ENTER_A:

			if(btn_one())
			{
				reg_shift_in(1);
				buzz_one();
				sleep_ms(200);
			}

			if(btn_zero())
			{
				reg_shift_in(0);
				buzz_zero();
				sleep_ms(200);
			}

			if(btn_add())
			{
				A = reg_get_value();
				reg_clear();
				gpio_put(ADD_LED, 1);
				mode = 1;
				state = ENTER_B;
				sleep_ms(300);
			}

			if(btn_sub())
			{
				A = reg_get_value();
				reg_clear();
				gpio_put(SUB_LED, 1);
				mode = 2;
				state = ENTER_B;
				sleep_ms(300);
			}

		break;


		case ENTER_B:

			if(btn_one())
			{
				reg_shift_in(1);
				buzz_one();
				sleep_ms(200);
			}

			if(btn_zero())
			{
				reg_shift_in(0);
				buzz_zero();
				sleep_ms(200);
			}

			if(btn_eval())
			{
				B = reg_get_value();
				gpio_put(EVAL_LED, 1);

				uint16_t result;

				if(mode == 1)
					result = alu_add(A, B);
				else
					result = alu_sub(A, B);

				if(result>255)
				{
					gpio_put(OVF_LED, 1);
					buzz_overflow();
				}

				reg_display((uint8_t)result);
				buzz_eval();

				state = SHOW_RESULT;
				sleep_ms(400);
			}

		break;

		case SHOW_RESULT:
		break;

	}
}
