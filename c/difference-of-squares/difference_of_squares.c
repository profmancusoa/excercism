#include "difference_of_squares.h"

unsigned int sum_of_squares(unsigned int number) {
    return (number * (number + 1) * (2 * number + 1)) / 6;
}

unsigned int square_of_sum(unsigned int number) {
    unsigned int base = (number * (number + 1)) / 2;

    return base * base;
}

unsigned int difference_of_squares(unsigned int number) {
    return square_of_sum(number) - sum_of_squares(number);
}

