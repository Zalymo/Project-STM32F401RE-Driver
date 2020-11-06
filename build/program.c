#include "lib/STM32F4XX-Local.h"

int main(void) {
    // Enable APB2 Clock
    writeBits(RCC_APB2ENR, 0x1, 1);

    /*
    // Configure the PLL Clock Register
    writeBits(RCC_PLLCFGR, 0x8, 1);
    writeBits(RCC_PLLCFGR, 0x30000, 1);

    // Set PLL as the system clock
    writeBits(RCC_CFGR, 0x2, 1);

    // Enable the PLL Clock
    writeBits(RCC_CR, 1 << 24, 1);
    */

   // Enable AHB1 Clock, then enable the GPIOC & GPIOA Mode Register
    writeBits(RCC_AHB1ENR, 0x5, 1);
    
    // Set GPIOA Mode Register 8 (bits 17:16) to alternate function mode [bits as 10]
    writeBits(GPIOA_MODER, 1 << 17, 1);

    writeBits(GPIOC_MODER, 0x1, 1);

    // Enable TIM1 (Adv Control Timer) and set the prescaler to 243
    writeBits(TIM1_CR1, 0x1, 1);
    //writeBits(TIM1_PSC, 0xF, 1);

    // Set up and configure TIM1 capture/compare channel 1

    /*
    // Enable preloading on TIM1_CCR1 (OC1PE on)
    writeBits(TIM1_CCMR1, 0x8, 1);

    // Enable TI1 ON CC1s (IC1 mapped on TI1)
    writeBits(TIM1_CCMR1, 0x1, 1);

    // Enable ARPE bit (TIM1_ARR register is buffered)
    writeBits(TIM1_CR1, 0x80, 1);

    // Load value into capture/compare register 1
    writeBits(TIM1_CCR1, 0xFF, 1); // 255

    // Set OC1M (Output Compare 1 Mode) to PWM Mode 1.
    writeBits(TIM1_CCMR1, 0x60, 1);

    // CC1E: Capture/Compare 1 output enable
    writeBits(TIM1_CCER, 0x1, 1);
    
    // CC1NE: Capture/Compare 1 complementary output enable
    writeBits(TIM1_CCER, 0x4, 1);
    
    //uint8_t dir = 0;
    */

    // Main output enable
    writeBits(TIM1_BDTR, 1 << 15, 1);

    // Enable preloading on TIM1_CCR1 (OC1PE on)
    //writeBits(TIM1_CCMR1, 0x8, 1);

    // CC1E: Capture/Compare 1 output enable
    writeBits(TIM1_CCER, 0x1, 1);

    // Set OC1M (Output Compare 1 Mode) to PWM Mode 1.
    writeBits(TIM1_CCMR1, 0x60, 1);

    // Toggle Update Generation (on)
    writeBits(TIM1_EGR, 0x1, 1);

    // Load value into capture/compare register 1
    //writeBits(TIM1_CCR1, 0xFD6F, 1); // 26,214

    // Configure first bit in AFRH8 to connect port A8 to TIM1 channel 1
    writeBits(GPIOA_AFRH, 0x1, 1);

    uint8_t dir = 0;

    while (1) {
        /**
         * Check the status register to see if the update bit is enabled.
         * If it is, then turn it off and toggle the GPIO ports that the
         * LEDs are connected to.
         */
        if (bitsEnabled(TIM1_SR, 0x1)) {
            writeBits(TIM1_SR, 0x1, 0);

            //writeBits(GPIOC_ODR, 0x1, -1);

            //writeBits(GPIOA_ODR, 0x100, -1);
        }

        if (dir == 0) {
            *TIM1_CCR1 = *TIM1_CNT;

            if (*TIM1_CCR1 == ((1 << 16) - 1)) {
                dir = 1;
            }
        } else {
            *TIM1_CCR1 -= 1;

            if (*TIM1_CCR1 == 0) {
                dir = 0;
            }
        }
    }

    return 0;
}
