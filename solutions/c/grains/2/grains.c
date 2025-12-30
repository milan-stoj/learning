#include "grains.h"

// implement power function base^exponent
static double power(double base, double exponent) {
    double result = 1;

    for (double i = 0; i < exponent; i++) {
        result *= base;
    }

    return result;
}

uint64_t square(uint8_t index) {
    return index > 0 && index <= 64 ? power(2, index - 1) : 0;
}

uint64_t total(void) {
    int sum = 0;
    for (int i = 1; i <= 64; i++) {
        sum += square(i);
    }
    return sum;
}

