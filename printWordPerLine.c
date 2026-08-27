//
// Created by Yassi on 1/1/2026.
//

/**
 *
 * The program is for prints the input one word per line
 *
*/

#include <stdio.h>
#define IN_WORD 1
#define OUT_WORD 0

int main() {
    int character = 0;
    int state = OUT_WORD;

    while ((character = getchar()) != EOF) {
        if (character == ' ' || character == '\t' || character == '\n') {
            state = OUT_WORD;
        } else if (state == OUT_WORD) {
            putchar('\n');
            putchar(character);
            state = IN_WORD;
        } else
            putchar(character);

    }

    return 0;
}