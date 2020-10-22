/**
 * stuff
*/
#include <stdint.h>
#include <stdbool.h>

#ifndef STM32_BIT_MANIP
#define STM32_BIT_MANIP

uint32_t* addrGrab(volatile uint32_t* addr);

uint32_t getBitPlace(uint8_t bit);

bool bitEnabled(uint32_t* addr, uint8_t bit);

void toggleRegisterBit(uint32_t* addr, uint8_t bit, int toggleType);

#endif // STM32_BIT_MANIP