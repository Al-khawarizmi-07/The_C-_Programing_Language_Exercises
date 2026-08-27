//
// Created by Yassi on 12/7/2025.
//

#include <stdio.h>


int main() {
    int c, nl = 0;

    while ((c = getchar()) != EOF)
        if (c == '\n')
            nl++;

    printf("%d", nl);

    return 0;
}