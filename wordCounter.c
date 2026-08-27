//
// Created by Yassi on 12/24/2025.
//
/*
 * is a program for counting words and characters and lines
 */
#include <stdio.h>
#define INSIDE_WORD 1
#define OUTSIDE_WORD 0

int main() {
    int state = OUTSIDE_WORD;
    int character, newWord, newLine, newCharacter;

    character = newWord = newLine = newCharacter = 0;

    while ((character = getchar()) != EOF) {
        newCharacter++;
        if (character == '\n')
            newLine++;

        if (character == ' ' || character == '\t' || character == '\n') {
            state = OUTSIDE_WORD;
        } else if (state == OUTSIDE_WORD) {
            state = INSIDE_WORD;
            newWord++;
        }
    }

    printf("Characters : %d\n", newCharacter);
    printf("Lines : %d\n", newLine);
    printf("Words : %d\n", newWord);
    return 0;
}