// myblinky.c
// A simple blinker to test the dev environment

#include "../common/button_boot.h"
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>

static void gpio_setup(void)
{
    rcc_periph_clock_enable(RCC_GPIOA);
    gpio_mode_setup(GPIOA, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO8);
}

int main(void)
{
    button_boot();
    gpio_setup();

    while(1) {
        gpio_toggle(GPIOA, GPIO8);

        for (int i = 0; i < 2500000; i++) {
            __asm__("nop");
        }
    }
    return 0;
}