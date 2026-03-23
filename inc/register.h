#ifndef REGISTER_H
#define REGISTER_H

#include <stdint.h>

void reg_clear(void);
void reg_shift_in(uint8_t bit);
void reg_display(uint8_t value);
uint8_t reg_get_value(void);

#endif
