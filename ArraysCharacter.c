//
// Created by Yassi on 1/12/2026.
//

#include <stdio.h>

//TODO write a program that reads a set of text lines and prints the longest.

int main() {
    char savedLine[100];
    char longestLine[100];
    int character = 0;
    int index = 0;
    int lengthOfSavedLine = 0;
    int lengthOfLongestLine = 0;

    for (index = 0; index < 100; index++) {
        savedLine[index] = ' ';
        longestLine[index] = ' ';
    }

    while ((character = getchar()) != EOF) {
        if (character == '\n') {
            lengthOfSavedLine = 0;
            for (index = 0; index < 100; index++) {
                longestLine[index] = ' ';
            }
            continue;
        }

        savedLine[lengthOfSavedLine] = character;
    }

    return 0;
}