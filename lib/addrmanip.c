#include "addrmanip.h"

bool bitsEnabled(vuint32_c* vAddr, size_t bits) {
    return *((uint32_t*) vAddr) & bits;
}

void setRegisterBits(vuint32_c* vAddr, size_t bits, int toggleType) {
    uint32_t* addr = (uint32_t*) vAddr;

    if (toggleType == 0) {
        *addr &= ~(bits);           // bit clear (off)
    } else if (toggleType == 1) {
        *addr |= bits;              // bit or (on)
    } else if (toggleType == -1) {
        *addr ^= bits;              // bit xor (toggle)
    }
}