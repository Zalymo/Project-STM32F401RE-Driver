#include "types.h"

#ifndef STM32_ADDR_MANIP
#define STM32_ADDR_MANIP

bool bitsEnabled(vuint32_c* vAddr, size_t bits);

void writeBits(vuint32_c* vAddr, size_t mask, int toggleType);

#endif // STM32_ADDR_MANIP