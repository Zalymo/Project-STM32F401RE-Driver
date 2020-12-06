#include "lib/STM32F4_CMSIS.h"

void configureRegisters();

int main(void) {
    // Variables placed here for testing purposes
    RCC_TypeDef* RCCVar = RCC;
    TIM_TypeDef* TIM1Var = TIM1;
    GPIO_TypeDef* GPIOAVar = GPIOA;
    GPIO_TypeDef* GPIOCVar = GPIOC;

    configureRegisters();

    uint8_t dir = 0;

    GPIOC->BSRR |= GPIO_BSRR_BS0;

    while (1) {
        if (TIM1->SR & TIM_SR_UIF) {
            TIM1->SR &= ~TIM_SR_UIF;

            if (dir == 0) {
                TIM1->CCR1++;
            } else {
                TIM1->CCR1--;
            }

            if (TIM1->CCR1 == 0xF3) {
                dir = 1;

                GPIOC->BSRR |= GPIO_BSRR_BR0;
            } else if (TIM1->CCR1 == 0) {
                dir = 0;

                GPIOC->BSRR |= GPIO_BSRR_BS0;
            }

        }
    }
    
    return 0;
}

void configureRegisters() {
    // Enable AHB1 Clock, then enable the GPIOC & GPIOA Mode Register
    RCC->AHB1ENR |= (RCC_AHB1ENR_GPIOAEN | RCC_AHB1ENR_GPIOCEN);

    // Enable APB2 Clock (for timers TIM1)
    RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;

    // Configure the PLL Clock Register
    // RCC->PLLCFGR |= 0x8;
    // RCC->PLLCFGR |= 0x30000;

    // Set PLL as the system clock
    // RCC->CFGR |= 0x2;

    // Enable the PLL Clock
    //RCC->CR |= 1 << 24;

    // Set GPIOA Mode Register 8 (bits 17:16) to alternate function mode [bits as 10]
    GPIOA->MODER |= GPIO_MODER_MODER8_1;
    GPIOC->MODER |= GPIO_MODER_MODER0_0;

    // Enable timer counters
    TIM1->CR1 |= TIM_CR1_CEN;
    TIM1->ARR = 0x10D;
    TIM1->PSC = 0xF3;
    
    // Main output enable
    TIM1->BDTR |= TIM_BDTR_MOE;

    // Enable preloading on TIM1_CCMR1 (OC1PE on)
    TIM1->CCMR1 |= TIM_CCMR1_OC1PE;

    // CC1E: Capture/Compare 1 output enable
    TIM1->CCER |= TIM_CCER_CC1E;

    // Set OC1M (Output Compare 1 Mode) to PWM Mode 1.
    TIM1->CCMR1 |= (TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_2);

    // Toggle Update Generation (on)
    TIM1->EGR |= TIM_EGR_UG;

    // Configure first bit in AFRH8 to connect port A8 to TIM1 channel 1 (AF01)
    GPIOA->AFR[1] |= GPIO_AFRH_AFSEL8_0;
}