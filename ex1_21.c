#include <stdio.h>

int const TAB_STOP = 8;


int main() {
    int character = 0;
    int blankSpaces = 0;
    int cursorIndex = 0;

    printf("enter a string sentence with blank spaces: \n");
    while ((character = getchar()) != EOF) {
        if (character == ' ') {
            blankSpaces++;
            continue;
        }

        if (blankSpaces != 0) {
            const int tabs = blankSpaces / TAB_STOP;
            const int blankSpacesRest = (blankSpaces % TAB_STOP) + (tabs == 0 ? 0 : (cursorIndex % TAB_STOP)) ;

            //printf("tabs: %d\n", tabs);
            for (int i = 0; i < tabs; i++) {
                putchar('\t');
            }
            //printf("blank Spaces: %d\n", blankSpacesRest);
            for (int i = 0; i < blankSpacesRest; i++) {
                putchar(' ');
            }
            blankSpaces = 0;
        }

        putchar(character);
        cursorIndex++;
        if (character == '\n') {
            cursorIndex = 0;
        }
    }
    return 0;
}