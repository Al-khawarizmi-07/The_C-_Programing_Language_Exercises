//
// Created by Yassi on 3/9/2026.
//

#include <stdio.h>
#define BUFFER_SIZE 1000

int getLength(char string[]);
void reverse(char string[]);

int main() {
    int character;
    char bufferString[BUFFER_SIZE];
    int index = 0;

    while ((character = getchar()) != EOF) {
        if (character == '\n') {
            bufferString[index] = character;
            bufferString[index + 1] = '\0';
            printf("printed line : ");
            reverse(bufferString);
            index = 0;
            continue;
        }
        bufferString[index] = character;
        index++;
    }

    return 0;
}


int getLength(char string[]) {
    int length = 0;

    while (string[length] != '\0')
        length++;

    return length;
}
void reverse(char string[]) {
    int length = getLength(string);

    for (int index = length - 1; index >= 0; index--)
        putchar(string[index]);
    putchar('\n');
}