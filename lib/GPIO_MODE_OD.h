/*
* This header contains different addresses required to manipulate
* GPIO mode registers and GPIO output data registers
*/

#ifndef STM32_GPIO_MODE_OD
#define STM32_GPIO_MODE_OD

struct RegisterPair {
    uint32_t* mode_register;
    uint32_t* opd_register;
   
    uint8_t mode_bit;
};

struct RegisterPair GPIO_MOPDR_Pair(char pin);

void GPIO_MOPDR_TogglePin(char* pin, uint8_t pinLength, int toggleType);

#endif // STM32_GPIO_MODE_OD