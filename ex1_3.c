/*
 *
 * Temperature conversion program with a heading above the table to print.
 *
 */

#include <stdio.h>

int main() {
    int fah;
    float celsius;
    char h1[11] = "Fahrenheit";
    char h2[11] = "Celsius";

    int lower = 0, upper = 300, step = 20;

    fah = lower;
    printf("%-10s\t%-10s\n",h1, h2);
    while (fah <= upper) {
        celsius = 5/9.0 *( fah - 32);
        printf("%-10d\t%-10.1f\n", fah, celsius);

        fah = fah + step;
    }

    return 0;
}