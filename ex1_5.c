/**
 *
 * It's a program that print the table of Fahrenheit temperatures and their Celsius equivalents
 * for fahr = 300, 280, ..... 0
 *
 */

#include <stdio.h>


int main() {
    int fahr;

    for (fahr = 300; fahr >= 0; fahr = fahr - 20 ) {
        printf("%10d\t%10.1f\n", fahr, (5/9.) * (fahr - 32));
    }

    return 0;
}