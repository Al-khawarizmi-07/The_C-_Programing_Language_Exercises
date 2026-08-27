#include <stdio.h>

int const TAB_STOP = 4;

int main() {
    int cursorIndex = 0;
    int character;

    printf("enter a sentences string to test the detab program: \n");
    while ((character = getchar()) != EOF) {
        if (character == '\t') {
            int blankSpaces = TAB_STOP - (cursorIndex % TAB_STOP);
            for (int i = 0; i < blankSpaces; i++) {
                putchar(' ');
                cursorIndex++;
            }
            continue;
        }

        if (character == '\n') {
            putchar('\n');
            cursorIndex = 0;
            continue;
        }
        putchar(character);
        cursorIndex++;
    }

    return 0;
}