//
// Created by Yassi on 12/23/2025.
//

#include <stdio.h>

int main() {
    int character = 0;
    int counter = 0;

    while ((character = getchar()) != EOF) {
        if (character == '\n' || character == '\t' || character == ' ')
            counter++;
    }

    printf("the number of blanks, tabs or newlines is : %d", counter);
    return 0;
}