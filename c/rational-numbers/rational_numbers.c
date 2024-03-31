#include "rational_numbers.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int gcd(int a, int b) {
    int aa = abs(a);
    int bb = abs(b);

    if(aa == 0) return bb;
    if(bb == 0) return aa;

    if(aa == bb) return aa;
    if(aa > bb) return gcd(bb, aa % bb);
    if(aa < bb) return gcd(aa, bb % aa);

    return 1;
}

rational_t reduce(rational_t r) {
    int divider = gcd(r.numerator, r.denominator);
   
    r.numerator = r.numerator / divider;
    r.denominator = r.denominator / divider;

    return rev_sign(r);
}

rational_t rev_sign(rational_t r) {
    if(r.denominator < 0) {
        r.denominator = -r.denominator;
        r.numerator = -r.numerator;
    }

    return r;
}

rational_t absolute(rational_t r) {
    r.numerator = abs(r.numerator);
    r.denominator = abs(r.denominator);

    return reduce(r);
}

rational_t add(rational_t r1, rational_t r2) {
    rational_t res;

    res.denominator = r1.denominator * r2.denominator;
    res.numerator = (r2.denominator * r1.numerator) + 
                    (r1.denominator * r2.numerator);

    if(res.numerator == 0) res.denominator = 1;

    return reduce(res);
}

rational_t subtract(rational_t r1, rational_t r2) {
    return add(r1, (rational_t){-r2.numerator, r2.denominator});
}

rational_t multiply(rational_t r1, rational_t r2) {
    rational_t res;

    res.denominator = r1.denominator * r2.denominator;
    res.numerator = r1.numerator * r2.numerator;

    return reduce(res);
}

rational_t divide(rational_t r1, rational_t r2) {
    return rev_sign(multiply(r1, (rational_t){r2.denominator, r2.numerator}));
}

rational_t exp_rational(rational_t r, int n) {
    rational_t res;

    if(n >= 0) {
        res.numerator = (int)pow(r.numerator, n);
        res.denominator = (int)pow(r.denominator, n);
    }
    if(n < 0) {
        res.numerator = (int)pow(r.denominator, -n);
        res.denominator = (int)pow(r.numerator, -n);
    }

    return reduce(rev_sign(res));
}

float exp_real(int x, rational_t r) {
    return (float)pow(x, (float)r.numerator/r.denominator);
}
