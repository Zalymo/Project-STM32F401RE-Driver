#include "types.h"

#ifndef STM32_ADDR_MANIP
#define STM32_ADDR_MANIP

bool bitsEnabled(vuint32_c* vAddr, size_t bits);

void setRegisterBits(vuint32_c* vAddr, size_t bits, int toggleType);

#endif // STM32_ADDR_MANIP