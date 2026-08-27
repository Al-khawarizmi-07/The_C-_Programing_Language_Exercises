/*
 *
 * Temperature conversion program with a heading above the table to print.
 * for convert celsius to fahrenheit
 */

#include <stdio.h>

int main() {
    int celsius;
    float fah;
    char h1[11] = "Fahrenheit";
    char h2[11] = "Celsius";

    int lower = 0, upper = 300, step = 1;

    celsius = lower;
    printf("%-10s\t%-10s\n",h2, h1);
    while (celsius <= upper) {
        fah = celsius * 9.0/5 + 32;
        printf("%-10d\t%-10.1f\n", celsius, fah);

        celsius = celsius + step;
    }

    return 0;
}