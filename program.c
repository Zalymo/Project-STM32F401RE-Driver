#include "lib/STM32F4XX-Local.h"

int main(void) {
    setRegisterBits(RCC_APB2ENR, 0x1, 1);

    setRegisterBits(TIM1_CR1, 0x1, 1);
    setRegisterBits(TIM1_PSC, 0xF4, 1);

    setRegisterBits(RCC_AHB1ENR, 0x4, 1);
    setRegisterBits(GPIOC_MODER, 0x4001, 1);

    while (1) {
        /**
         * Check the status register to see if the update bit is enabled.
         * If it is, then turn it off and toggle the GPIO ports that the
         * LEDs are connected to.
         */
        if (bitsEnabled(TIM1_SR, 0x1)) {
            setRegisterBits(TIM1_SR, 0x1, 0);

            setRegisterBits(GPIOC_ODR, 0x81, -1);
        }
    }

    return 0;
}
