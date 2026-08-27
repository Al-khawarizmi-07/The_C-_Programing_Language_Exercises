//
// Created by Yassi on 1/1/2026.
//

/**
 * this is a program to test and lear arrays
 */

#include <stdio.h>


int main() {
    int occurrenceOfDigits[10];
    int occurrenceOfWhiteSpace = 0;
    int occurrenceOfOtherCharacters = 0;
    int index;
    int character = 0;

    // initialisation of array elements
    for (index = 0; index < 10; index++)
        occurrenceOfDigits[index] = 0;

    while ((character = getchar()) != EOF) {
        if (character == ' ' || character == '\t' || character == '\n')
            occurrenceOfWhiteSpace++;
        else if (character >= '0' && character <= '9')
            occurrenceOfDigits[character - '0']++;
        else
            occurrenceOfOtherCharacters++;
    }

    printf("occurrences of each digit : ");
    for (index = 0; index < 10; index++)
        printf("%d\t",occurrenceOfDigits[index]);

    printf("\n occurrences of white space : %d", occurrenceOfWhiteSpace);
    printf("\n occurrences of other characters : %d", occurrenceOfOtherCharacters);


    return 0;
}