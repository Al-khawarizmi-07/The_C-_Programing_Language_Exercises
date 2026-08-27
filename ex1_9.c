//
// Created by Yassi on 12/23/2025.
//

#include <stdio.h>

int main() {
    int character = 0;
    int isBlankCharacter = 0;

    while ((character = getchar()) != EOF) {
        isBlankCharacter = 0;
        if (character == ' ')
            while ((character = getchar()) == ' ') {
                isBlankCharacter = ' ';
            }

        if (isBlankCharacter == ' ')
            putchar(isBlankCharacter);

        putchar(character);
    }

    return 0;
}