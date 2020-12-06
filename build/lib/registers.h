#ifndef STM32_REGISTERS_H
#define STM32_REGISTERS_H

#include "types.h"

/**
 * 
 * NOTE: This file should be treated as a dynamic header. Its contents should always be
 * subject to change depending on the needs of the task at hand. We don't want unneccessary
 * bloat.
 *
 */

/* Register Clock Control Registers (RCC) */

#define RCC_AHB1ENR (vuint32_c*)            0x40023830
#define RCC_APB1ENR (vuint32_c*)            0x40023840
#define RCC_APB2ENR (vuint32_c*)            0x40023844

#define RCC_CR (vuint32_c*)                 0x40023800
#define RCC_PLLCFGR (vuint32_c*)            0x40023804
#define RCC_CFGR (vuint32_c*)               0x40023808
#define RCC_DCKCFGR (vuint32_c*)            0x4002388C

/* Advanced Control Timer/General Purpose Timer Registers (TIM1) */

#define TIM1_CR1 (vuint32_c*)               0x40010000      // TIM1 control register 1
#define TIM1_CR2 (vuint32_c*)               0x40010004      // TIM1 control register 2
#define TIM1_CCER (vuint32_c*)              0x40010020      // TIM1 capture/compare enable register
#define TIM1_CCMR1 (vuint32_c*)             0x40010018      // TIM1 capture/compare mode enable register
#define TIM1_BDTR (vuint32_c*)              0x40010044      // TIM1 break and dead-time register
#define TIM1_EGR (vuint32_c*)               0x40010014      // TIM1 event generation register
#define TIM1_CNT (vuint32_c*)               0x40010024      // TIM1 count register
#define TIM1_PSC (vuint32_c*)               0x40010028      // TIM1 prescaler register
#define TIM1_SR (vuint32_c*)                0x40010010      // TIM1 status register

#define TIM1_CCR1 (vuint32_c*)              0x40010034      // TIM1 capture/compare register 1

/* General Purpose Input/Output Mode Registers (GPIO_MODER) */

#define GPIOA_MODER (vuint32_c*)            0x40020000      // port A direction/mode register
#define GPIOB_MODER (vuint32_c*)            0x40020400      // port B direction/mode register
#define GPIOC_MODER (vuint32_c*)            0x40020800      // port C direction/mode register

/* General Purpose Input/Output Output Data Registers (GPIO_ODR) */

#define GPIOA_ODR (vuint32_c*)              0x40020014      // port A output data register
#define GPIOB_ODR (vuint32_c*)              0x40020414      // port B output data register
#define GPIOC_ODR (vuint32_c*)              0x40020814      // port C output data register

/* General Purpose Input/Output Alternate Function High Register (GPIO_AFRH) */

#define GPIOA_AFRL (vuint32_c*)            0x40020020      // port A alternate function high register
#define GPIOA_AFRH (vuint32_c*)            0x40020024      // port A alternate function high register


#define GPIOC_BSRR (vuint32_c*)            0x40020818
#endif // STM32_REGISTERS_H