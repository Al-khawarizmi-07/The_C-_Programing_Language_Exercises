#include <stdio.h>

int const  WIDTH_LIMIT = 20;


int main() {
    int character = 0;
    int characterSize = 0;
    int characterBuffer[WIDTH_LIMIT + 1];

    printf("enter your sentence :\n");

    while ((character = getchar()) != EOF) {
        characterBuffer[characterSize] = character;
        characterSize++;

        if (character == '\n' && characterSize <= WIDTH_LIMIT) { // the case for shorter or medium line size
            for (int i = 0; i < characterSize; i++) {
                putchar(characterBuffer[i]);
            }
            characterSize = 0;
        } else if (characterSize == (WIDTH_LIMIT + 1)) {
            if (characterBuffer[characterSize - 1] == ' ' ||
                characterBuffer[characterSize - 1] == '\t' ||
                characterBuffer[characterSize - 1] == '\n') {
                for (int i = 0; i < characterSize; i++) {
                    putchar(characterBuffer[i]);
                }
                characterBuffer[0] = characterBuffer[characterSize - 1];
                characterSize = 1;

                if (characterBuffer[0] == '\n') {
                    putchar(characterBuffer[0]);
                    characterSize = 0;
                }
            } else {
                int lastBlankOccurrenceIndex = 0;
                for (int i = 0; i < WIDTH_LIMIT; i++) {
                    if (characterBuffer[i] == ' ' || characterBuffer[i] == '\t') {
                        lastBlankOccurrenceIndex = i;
                    }
                }

                if (lastBlankOccurrenceIndex != 0) {
                    for (int i = 0 ; i <= lastBlankOccurrenceIndex; i++) {
                        putchar(characterBuffer[i]);
                    }
                    putchar('\n');

                    for (int i = lastBlankOccurrenceIndex + 1; i < WIDTH_LIMIT + 1; i++) {
                        characterBuffer[i - (lastBlankOccurrenceIndex + 1)] = characterBuffer[i];
                    }
                    characterSize = characterSize - (lastBlankOccurrenceIndex + 1);
                } else {
                    for (int i = 0; i < WIDTH_LIMIT; i++) {
                        putchar(characterBuffer[i]);
                    }
                    putchar('\n');
                    characterBuffer[0] = characterBuffer[characterSize - 1];
                    characterSize = 1;
                }
            }
        }
    }

    return 0;
}