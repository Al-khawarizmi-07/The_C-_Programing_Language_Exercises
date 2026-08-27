//
// Created by Yassi on 3/1/2026.
//

#include <stdio.h>
#define BUFFER_STRING_SIZE 100

int getLine(int bufferStringSize);

int main() {
    int result = 0;
    while (result != EOF)
        result = getLine(BUFFER_STRING_SIZE);

    return 0;
}

int getLine(int bufferStringSize) {
    char bufferString[bufferStringSize];
    int index = 0;
    int character = 0;

    for (index = 0; index < bufferStringSize - 1 && character != '\n' && character != EOF; index++) {
        character = getchar();
        bufferString[index] = character;
    }

    bufferString[index] = '\0';

    if (character == EOF)
        return EOF;
    if (character == '\n') {
        index--;
        int postIndex = 0;
        for (postIndex = index - 1; postIndex >= 0 && (bufferString[postIndex] == ' ' || bufferString[postIndex] =='\t'); postIndex--) {
            bufferString[postIndex] = '\n';
            bufferString[postIndex + 1] = '\0';
        }
        if (postIndex == 0 && bufferString[postIndex] == '\n')
            return 0;
        printf("string: %s", bufferString);
        return '\n';
    }

    return 1;
}
