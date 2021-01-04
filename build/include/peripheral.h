
#ifndef STM32F4_PERIPHERAL_H
#define STM32F4_PERIPHERAL_H

#include "cmsis.h"

/* TIM Register Abstraction */

/* CCMR1 */
#define CCMR1_OC1M_PWM_MODE1 (TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_2)
#define CCMR1_OC1M_PWM_MODE2 (TIM_CCMR1_OC1M_0 | TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_2)

#define CCMR1_OC2M_PWM_MODE1 (TIM_CCMR1_OC2M_1 | TIM_CCMR1_OC2M_2)
#define CCMR1_OC2M_PWM_MODE2 (TIM_CCMR1_OC2M_0 | TIM_CCMR1_OC2M_1 | TIM_CCMR1_OC2M_2)

#define CCMR1_OC3M_PWM_MODE1 (TIM_CCMR2_OC3M_1 | TIM_CCMR2_OC3M_2)
#define CCMR1_OC3M_PWM_MODE2 (TIM_CCMR2_OC3M_0 | TIM_CCMR2_OC3M_1 | TIM_CCMR2_OC3M_2)

/* TIM General Macros */
#define MAX_COUNT 0xFFFF

/* Macro Functions */
#define BIT_SET(R, M) (R |= M)
#define BIT_CLEAR(R, M) (R &= ~M)
#define BIT_TOGGLE(R, M) (R ^= M)
#define BIT_ON(R, M) (R & M)

//vuint32_c* getClock(uint32_t base);

#endif