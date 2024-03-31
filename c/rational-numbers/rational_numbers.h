#ifndef RATIONAL_NUMBERS_H
#define RATIONAL_NUMBERS_H

typedef struct _rational_t {
    int numerator;
    int denominator;
} rational_t;

int gcd(int a, int b);
rational_t reduce(rational_t r);
rational_t rev_sign(rational_t r);
rational_t absolute(rational_t r);
rational_t add(rational_t r1, rational_t r2);
rational_t subtract(rational_t r1, rational_t r2);
rational_t multiply(rational_t r1, rational_t r2);
rational_t divide(rational_t r1, rational_t r2);
rational_t exp_rational(rational_t r, int n);
float exp_real(int x, rational_t r);

#endif
