
#ifndef STM32F4XX_LOCAL_PROJECT
#define STM32F4XX_LOCAL_PROJECT

#include "registers.h"
#include "addrmanip.h"

void GPIO_MOPDR_TogglePin(const char* pin, const uint8_t pinLength, const int toggleType);

#endif // STM32F4XX_LOCAL_PROJECT