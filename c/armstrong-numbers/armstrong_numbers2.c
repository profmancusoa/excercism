#include <math.h>
#include <stdbool.h>
#include <stdio.h>

bool is_armstrong_number(int candidate) {
    int armstrong = 0, d = 0, digit = 0, last = 0, factor = 0;
    int n_digit = (int)floor(log10(candidate)) + 1;
    int k = n_digit;

    if (candidate < 10) return true;

    while(k > 0) {
        factor = (int)pow(10, k-1); 
        d = candidate/factor * factor / factor;
        digit = d - (last * 10);
        last = d;
        armstrong += (int)pow(digit, n_digit);
        k--;
    }

    return armstrong == candidate;
}

// this is just a simple main to test the function

int main() {
    printf("4 is Armstrong number: %d\n", is_armstrong_number(4));
    printf("153 is Armstrong number: %d\n", is_armstrong_number(153));
    printf("5631 is Armstrong number: %d\n", is_armstrong_number(5631));

    return 0;
}