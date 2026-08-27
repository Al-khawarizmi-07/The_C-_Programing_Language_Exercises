//
// Created by Yassi on 2/16/2026.
//
#include <stdio.h>

int power(int base, int e);

int main() {
    printf("%d", power(10, 2));
    return 0;
}

int power(int base, int n) {
    int p;

    for (p = 1; n > 0; n--)
        p = p * base;

    return p;
}