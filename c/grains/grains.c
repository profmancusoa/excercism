#include "grains.h"
#include <stdio.h>
#include <math.h>

uint64_t square(uint8_t index) {
    return (uint64_t)powl(2, index - 1);
}

uint64_t total(void) {
    uint64_t tot = 0ull;

    for(uint8_t i = 1; i <= 64; i++)
        tot += square(i);
    
    return tot;
}

