#include <math.h>
#include <stdbool.h>
#include <stdio.h>

bool is_armstrong_number(int candidate) {
    int n_digit = (int)floor(log10(candidate)) + 1;
    int armstrong = 0;

    if (candidate < 10) return true;

    for(int i = 0; i < n_digit; i++) {
        int digit = candidate % (int)pow(10, i + 1) / (int)pow(10, i);
        armstrong += (int)pow(digit, n_digit);
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