#include "STM32F4XX-Local.h"

typedef struct MOPD_RP {
    vuint32_c* mode_register;
    vuint32_c* opd_register;
   
    uint8_t mode_bit;
} MOPD_RegisterPair;

MOPD_RegisterPair GPIO_MOPDR_Pair(char pin) {
    MOPD_RegisterPair regPair;

    if (pin == 'A') {
        regPair.mode_register = GPIOA_MODER;
        regPair.opd_register = GPIOA_ODR;
       
        regPair.mode_bit = 0;
    } else if (pin == 'B') {
        regPair.mode_register = GPIOB_MODER;
        regPair.opd_register = GPIOB_ODR;
       
        regPair.mode_bit = 1;
    } else if (pin == 'C') {
        regPair.mode_register = GPIOC_MODER;
        regPair.opd_register = GPIOC_ODR;

        regPair.mode_bit = 2;
    }

    return regPair;
}

/**
* GPIO_MOPDR_TogglePin
*
*
*/
void GPIO_MOPDR_TogglePin(const char* pin, const uint8_t pinLength, const int toggleType) {
    // The identifier for this pin, which is the second char in the pin name
    char iden = pin[1];

    MOPD_RegisterPair regPair = GPIO_MOPDR_Pair(iden);

    uint8_t pinNumber = 0;

    // Convert digit(s) in pin to actual integer
    for (uint8_t i = 2; i < pinLength; i++) {
        pinNumber = (pinNumber * 10) + (pin[i] - '0');
    }

    /**
     * If the GPIO port mode register isn't enabled in RCC_AHB1ENR, or the mode register
     * isn't enabled in the GPIO port mode register, then we'll just enable both to avoid
     * hard-to-spot bugs (remember, there is no printing to stdout on bare metal! yet?)
    */
    if (!bitsEnabled(RCC_AHB1ENR, 1 << regPair.mode_bit) || !bitsEnabled(regPair.mode_register, 1 << pinNumber * 2)) {
        setRegisterBits(RCC_AHB1ENR, 1 << regPair.mode_bit, 1);
        
        setRegisterBits(regPair.mode_register, 1 << (pinNumber * 2), 1);
    }

    // Finally, we can toggle the bit in the GPIO output data register for the result
    setRegisterBits(regPair.opd_register, 1 << pinNumber, toggleType);
}