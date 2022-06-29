#include "py/mphal.h"

void NATUR_G0B1RE_board_early_init(void) 
{
    mp_hal_pin_output(pin_B12);
    mp_hal_pin_output(pin_B13);
    mp_hal_pin_output(pin_B14);
    mp_hal_pin_output(pin_B15);
    mp_hal_pin_write(pin_B12, 1);
    mp_hal_pin_write(pin_B13, 1);
    mp_hal_pin_write(pin_B14, 1);
    mp_hal_pin_write(pin_B15, 1);
}
