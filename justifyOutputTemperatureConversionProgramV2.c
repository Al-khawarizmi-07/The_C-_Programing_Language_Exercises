/**
*
 * It's a program that print the table of Fahrenheit temperatures and their Celsius equivalents with justify format
 * for fahr = 0, 20, ..., 300 floating point version
 *
 */

#include <stdio.h>


int main() {
    float fahr, celsius;
    float lower = 0, upper = 300, step = 20;

    fahr = lower;
    while (fahr <= upper) {
        celsius = (5.0/9.0) * (fahr - 32);

        printf("%3.0f\t%6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }

    return 0;
}