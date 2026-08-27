/**
 *
 * It's a program that print the table of Fahrenheit temperatures and their Celsius equivalents
 * for fahr = 0, 20, ..., 300
 *
 */

#include <stdio.h>

int convertFahrenheitToCelsius(int fahr);

int main() {
    int fahr, celsius;
    int lower = 0, upper = 300, step = 20;

    fahr = lower;
    while (fahr <= upper) {
        celsius = convertFahrenheitToCelsius(fahr);

        printf("%d\t%d\n", fahr, celsius);
        fahr = fahr + step;
    }

    return 0;
}

int convertFahrenheitToCelsius(int fahr) {
    return (5/9.0) * (fahr - 32);
}