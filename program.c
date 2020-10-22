#include "lib/STM32F4XX-Local-2.h"
//#include "lib/bitmanip.h"

/**
 * TO-DO: create algorithm that takes a pin name as input, and toggles the actual 
 * pin on the board 
 */
int main(void) {
    /*
    // Toggle port A GPIO mode register (0th bit)
    toggleRegisterBit(RCC_AHB1ENR, 0, 1);
    
    // Toggle 10th bit of the port A GPIO mode register
    toggleRegisterBit(GPIOA_MODER, 10, 1);

    // Toggle 5th bit of port A GPIO output data register to toggle the user LED (LD2)
    toggleRegisterBit(GPIOA_ODR, 5, 1);

    // Toggle 2nd bit of the port C GPIO mode register
    toggleRegisterBit(RCC_AHB1ENR, 2, 1);
    
    // Toggle bits 14 and 0 of port C GPIO mode register
    toggleRegisterBit(GPIOC_MODER, 14, 1);
    toggleRegisterBit(GPIOC_MODER, 0, 1);

    // Toggle 7th bit of the port C GPIO output data register to initialize yellow LED
    toggleRegisterBit(GPIOC_ODR, 7, 1);
    yield();

    while (1) {
        toggleRegisterBit(GPIOC_ODR, 7, -1);
        toggleRegisterBit(GPIOC_ODR, 0, -1);

        yield();
    }
    */

    GPIO_MOPDR_TogglePin("PC7", 3, 1);
    return 0;
}
