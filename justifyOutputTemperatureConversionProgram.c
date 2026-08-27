/**
*
 * It's a program that print the table of Fahrenheit temperatures and their Celsius equivalents with justify format
 * for fahr = 0, 20, ..., 300
 *
 */

#include <stdio.h>


int main() {
    int fahr, celsius;
    int lower = 0, upper = 300, step = 20;

    fahr = lower;
    while (fahr <= upper) {
        celsius = (5/9.) * (fahr - 32);

        printf("%3d\t%4d\n", fahr, celsius);
        fahr = fahr + step;
    }

    return 0;
}