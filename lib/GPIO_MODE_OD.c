#include "addrmanip.h"
#include "RCC.h"
#include "GPIO_MODE_OD.h"

struct RegisterPair GPIO_MOPDR_Pair(char pin) {
    struct RegisterPair regPair;

    if (pin == 'A') {
        regPair.mode_register = addrGrab(GPIOA_MODER);
        regPair.opd_register = addrGrab(GPIOA_ODR);
       
        regPair.mode_bit = 0;
    } else if (pin == 'B') {
        regPair.mode_register = addrGrab(GPIOB_MODER);
        regPair.opd_register = addrGrab(GPIOB_ODR);
       
        regPair.mode_bit = 1;
    } else if (pin == 'C') {
        regPair.mode_register = addrGrab(GPIOC_MODER);
        regPair.opd_register = addrGrab(GPIOC_ODR);

        regPair.mode_bit = 2;
    }

    return regPair;
}

void GPIO_MOPDR_TogglePin(char* pin, uint8_t pinLength, int toggleType) {
    // The identifier for this pin, which is the second char in the pin name
    char iden = pin[1];

    struct RegisterPair regPair = GPIO_MOPDR_Pair(iden);

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
    if (!bitEnabled(addrGrab(RCC_AHB1ENR), regPair.mode_bit) || !bitEnabled(regPair.mode_register, pinNumber * 2)) {
        toggleRegisterBit(addrGrab(RCC_AHB1ENR), regPair.mode_bit, 1);
        
        toggleRegisterBit(regPair.mode_register, pinNumber * 2, 1);
    }

    // Finally, we can toggle the bit in the GPIO output data register for the result
    toggleRegisterBit(regPair.opd_register, pinNumber, toggleType);
}