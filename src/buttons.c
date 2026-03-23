#include "pico/stdlib.h"
#include "buttons.h"

#define ZERO 10
#define ONE 11
#define ADD 12
#define SUB 13
#define EVAL 14

int btn_zero(){ return !gpio_get(ZERO); }
int btn_one(){ return !gpio_get(ONE); }
int btn_add(){ return !gpio_get(ADD); }
int btn_sub(){ return !gpio_get(SUB); }
int btn_eval(){ return !gpio_get(EVAL); }
