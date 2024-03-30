#include "resistor_color.h"

const resistor_band_t res_colors[] = { COLORS };

int color_code(resistor_band_t color) {
    return color;
}

const resistor_band_t *colors() {
    return res_colors;
}