//
// Created by Yassi on 1/3/2026.
//


#include <stdio.h>

int main() {
    int histogramFrequenciesCharacter[126 - 32];
    int i, j;
    int character = 0;
    int maxCharacterFrequency = 0;
    char starCharacter = '^';
    char spaceCharacter = ' ';
    char underScoreCharacter = '-';


    //initialize the elements of the array
    for (i = 0; i < 126 - 32; i++) {
        histogramFrequenciesCharacter[i] = 0;
    }

    while ((character = getchar()) != EOF) {
        if ((character - 32) > (126 - 32))
            continue;
        histogramFrequenciesCharacter[character - 32]++;
    }

    // print the histogram for words length horizontally
    printf("histogram horizontal of character frequencies.\n");
    for (i = 0; i < (126 - 32); i++) {
        if (histogramFrequenciesCharacter[i] == 0)
            continue;
        printf("%2c |", i + 32);
        for (j = 0; j < histogramFrequenciesCharacter[i]; j++) {
            printf("-");
        }
        printf("\n");
    }

    // print the histogram for words length vertically

    printf("\n\n");
    printf("histogram vertical of character frequencies. \n");

    // get the Maximum word length
    maxCharacterFrequency = histogramFrequenciesCharacter[0];
    for (i = 0; i < (126 - 32); i++) {
        if (maxCharacterFrequency < histogramFrequenciesCharacter[i]) {
            maxCharacterFrequency = histogramFrequenciesCharacter[i];
        }
    }

    // print the histogram vertically
    for (j = maxCharacterFrequency; j >= -1; j--) {
        for (i = 0; i < (126 - 32); i ++) {
            if (histogramFrequenciesCharacter[i] == 0)
                continue;
            if (j == 0) {
                printf("%3c", underScoreCharacter);
                continue;
            } else if ( j == -1) {
                printf("%3c", i + 32);
                continue;
            }
            if (histogramFrequenciesCharacter[i] >= j)
                printf("%3c", starCharacter);
            else
                printf("%3c", spaceCharacter);
        }
        putchar('\n');
    }

    return 0;
}