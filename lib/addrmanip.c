#include "addrmanip.h"

uint32_t* addrGrab(volatile uint32_t* addr) {
    return (uint32_t*) addr;
}

uint32_t getBitPlace(uint8_t bit) {
    if (bit > 0) {
        return 0x1 << bit;
    } else {
        return 0x1;
    }
}

bool bitEnabled(uint32_t* addr, uint8_t bit) {
    return *addr & (1 << bit);
}

void toggleRegisterBit(uint32_t* addr, uint8_t bit, int toggleType) {
    uint32_t place = getBitPlace(bit);

    if (toggleType == 0) {
        *addr &= ~(place);           // bit clear (off)
    } else if (toggleType == 1) {
        *addr |= place;              // bit or (on)
    } else if (toggleType == -1) {
        *addr ^= place;              // bit xor (toggle)
    }
}