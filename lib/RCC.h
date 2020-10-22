#ifndef STM32_RCC
#define STM32_RCC

// RCC Registers

#define RCC_AHB1ENR                (volatile uint32_t*) 0x40023830     // RCC peripheral clock enable register

// GPIO Registers

#define GPIOA_MODER                (volatile uint32_t*) 0x40020000      // port A direction/mode register
#define GPIOA_ODR                  (volatile uint32_t*) 0x40020014      // port A output data register

#define GPIOB_MODER                (volatile uint32_t*) 0x40020400      // port B direction/mode register
#define GPIOB_ODR                  (volatile uint32_t*) 0x40020414      // port B output data register

#define GPIOC_MODER                (volatile uint32_t*) 0x40020800      // port C direction/mode register
#define GPIOC_ODR                  (volatile uint32_t*) 0x40020814      // port C output data register

#endif // STM32_RCC