//
// Created by Yassi on 1/12/2026.
//

#include <stdio.h>

int power(int, int);

int main() {
    int base;
    int exponent;
    int result;

    base = 3;
    exponent = 5;
    result = power(base, exponent);
    if (result < 0)
        return result;
    printf("%d^%d = %d", base, exponent, result);
    return 0;
}

int power(int base, int exponent) {
    int i = 0, p = 0;

    if (exponent < 0)
        return -1;

    p = 1;

    for (i = 0; i < exponent; i++)
        p *= base;

    return p;
}