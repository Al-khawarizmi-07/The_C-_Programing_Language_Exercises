//
// Created by Yassi on 2/21/2026.
//

#include <stdio.h>

int getLine(int bufferLimit);

int main() {
    int result = 0;
    while (result != EOF)
        result = getLine(81);

    return 0;
}

int getLine(int bufferLimit) {
    char bufferCharacter[bufferLimit];
    int index;
    int character = ' ';

    for (index = 0; index < bufferLimit - 1 && character != EOF && character != '\n' ; index++) {
        character = getchar();
        bufferCharacter[index] = character;
    }

    bufferCharacter[index] = '\0';

    if (index == bufferLimit - 1)
        printf("%s", bufferCharacter);
    else
        return 0;

    if (character == EOF)
        return EOF;
    if (character == '\n')
        return '\n';

    while ((character = getchar()) != EOF && character != '\n')
        putchar(character);
    if (character == '\n')
        putchar(character);
    return character;
}
