#include <stdio.h>

// Global Variables
const int BUFFER_SIZE = 1024 * 100;

// Contexts
const int OUTSIDE = 0;
const int INSIDE_STRING = 1;
const int INSIDE_COMMENT_TYPE_ONE = 2;
const int INSIDE_COMMENT_TYPE_TWO = 3;

int determineContext(int context, int previousCharacter, int character, int nextCharacter);

int main() {
    int character = 0;
    int bufferSize = 0;
    int context = OUTSIDE;
    int previousContext = OUTSIDE;
    int buffer[BUFFER_SIZE];


    while ((character = getchar()) != EOF) {
        buffer[bufferSize] = character;
        bufferSize++;
    }

    for (int i = 0; i < bufferSize; i++) {
        previousContext = context;
        context = determineContext(context, i - 1 < 0 ? -1 : buffer[i-1], buffer[i], buffer[i+1]);

        if ((context == INSIDE_COMMENT_TYPE_ONE || context == INSIDE_COMMENT_TYPE_TWO)) {
            continue;
        } else if (previousContext == INSIDE_COMMENT_TYPE_ONE || previousContext == INSIDE_COMMENT_TYPE_TWO) {
            if (previousContext == INSIDE_COMMENT_TYPE_TWO)
                i++;
            continue;
        } else {
            putchar(buffer[i]);
        }
    }

    return 0;
}


int determineContext(int context, int previousCharacter, int character, int nextCharacter) {
    if (character == EOF) {
        return context;
    }

    if (context == OUTSIDE) {
        if (previousCharacter != '\\' && previousCharacter != '\'' && character == '\"') {
            return INSIDE_STRING;
        }
        if (character == '/' && nextCharacter == '/') {
            return INSIDE_COMMENT_TYPE_ONE;
        }
        if (character == '/' && nextCharacter == '*') {
            return INSIDE_COMMENT_TYPE_TWO;
        }
    } else if (context == INSIDE_STRING) {
        if (previousCharacter != '\\' && character == '\"') {
            return OUTSIDE;
        }
    } else if (context == INSIDE_COMMENT_TYPE_ONE) {
        if (character == '\n') {
            return OUTSIDE;
        }
    } else if (context == INSIDE_COMMENT_TYPE_TWO) {
        if (character == '*' && nextCharacter == '/') {
            return OUTSIDE;
        }

        if (character == '\0') {
            printf("[Error]: Unterminated comment");
        }
    }

    return context;
}
