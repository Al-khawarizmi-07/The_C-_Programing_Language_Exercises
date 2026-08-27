//
// Created by Yassi on 12/23/2025.
//

#include <stdio.h>

int main() {
    int character = 0;
    while ((character = getchar()) != EOF) {
        if (character == '\t') {
            putchar('\\');
            putchar('t');
            continue;
        } else if (character == '\b') {
            putchar('\\');
            putchar('b');
            continue;
        } else if (character == '\\') {
            putchar('\\');
            putchar('\\');
        } else {
            putchar(character);
        }
    }

    return 0;
}