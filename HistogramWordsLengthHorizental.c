//
// Created by Yassi on 1/1/2026.
//

#include <stdio.h>

int main() {
    int character = 0;
    int histogram[20];
    int length = 0;
    int i, j;
    int maxWordLength = 0;
    char starCharacter = '^';
    char spaceCharacter = ' ';
    char underScoreCharacter = '-';

    // initialization of the array elements
    for (i = 0; i < 20; i++)
        histogram[i] = 0;

    while ((character = getchar()) != EOF) {
        if (character == ' ' || character == '\t' || character == '\n') {
            if (length != 0) {
                histogram[length]++;
            }
            length = 0;
        } else {
            length++;
        }
    }

    // print the histogram for words length horizontally
    printf("histogram horizontal of words length.\n");
    for (i = 0; i < 20; i++) {
        if (histogram[i] == 0)
            continue;
        printf("%2d |", i);
        for (j = 0; j < histogram[i]; j++) {
            printf("-");
        }
        printf("\n");
    }

    // print the histogram for words length vertically

    printf("\n\n");
    printf("histogram vertical of words length. \n");

    // get the Maximum word length
    maxWordLength = histogram[0];
    for (i = 0; i < 20; i++) {
        if (maxWordLength < histogram[i]) {
            maxWordLength = histogram[i];
        }
    }

    // print the histogram vertically
    for (j = maxWordLength; j >= -1; j--) {
        for (i = 0; i < 20; i ++) {
            if (histogram[i] == 0)
                continue;
            if (j == 0) {
                printf("%3c", underScoreCharacter);
                continue;
            } else if ( j == -1) {
                printf("%3d", i);
                continue;
            }
            if (histogram[i] >= j)
                printf("%3c", starCharacter);
            else
                printf("%3c", spaceCharacter);
        }
        putchar('\n');
    }

    return 0;
}