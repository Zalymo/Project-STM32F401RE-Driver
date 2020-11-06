#include "addrmanip.h"

bool bitsEnabled(vuint32_c* vAddr, size_t bits) {
    return *((uint32_t*) vAddr) & bits;
}

void writeBits(vuint32_c* vAddr, size_t mask, int toggleType) {
    uint32_t* addr = (uint32_t*) vAddr;

    if (toggleType == 0) {
        *addr &= ~(mask);           // bit clear (off)
    } else if (toggleType == 1) {
        *addr |= mask;              // bit or (on)
    } else if (toggleType == -1) {
        *addr ^= mask;              // bit xor (toggle)
    }
}