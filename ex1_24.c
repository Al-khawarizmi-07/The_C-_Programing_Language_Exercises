#include <stdio.h>
#include <stdbool.h>

#define ANSI_COLOR_RED "\x1b[31m"



// Global variables
const int STACK_SIZE = 1024;

// Function prototypes
void push(int character, int stack[], int *index);
int pop(int stack[], int *index);
bool isEmpty(int index);
bool isFull(int index);

struct Context {
    const int outside;
    const int insideDoubleQuotes;
    const int insideSingleQuotes;
    const int insideCommentsTypeOne; // type one it means this symbols // ended by this symbol \n or this symbol EOF
    const int insideCommentsTypeTwo; // type two it means this symbols /* ended by this symbol */
    int currentContext;
} typedef Context;

bool saveSymbol(Context *context, int previousCharacter, int currentCharacter);
int main() {
    int stack[STACK_SIZE];
    int stackAnalyzer[STACK_SIZE];
    int index = -1;
    int currentCharacter = -1;
    int previousCharacter = -1;
    Context context = {
        0,
        1,
        2,
        3,
        4,
        0
    };


    while ((currentCharacter = getchar()) != EOF) {
        if (saveSymbol(&context, previousCharacter, currentCharacter)) {
            if ((previousCharacter == '/' && currentCharacter == '/')
                || (previousCharacter == '/' && currentCharacter == '*')
                || (previousCharacter == '*' && currentCharacter == '/')) {

                push(previousCharacter + currentCharacter, stack, &index);
            } else {
                push(currentCharacter, stack, &index);
            }
        }

        previousCharacter = currentCharacter;
    }

    push(EOF, stack, &index);


    return 0;
}

bool saveSymbol(Context *context, const int previousCharacter, const int currentCharacter) {
    if (context->currentContext == context->outside) {
        if (currentCharacter == '{' || currentCharacter  == '}'
            || currentCharacter == '[' || currentCharacter == ']'
            || currentCharacter == '(' ||currentCharacter == ')') {
            return true;
        }

        if (currentCharacter == '"') {
            context->currentContext = context->insideDoubleQuotes;
            return true;
        }

        if (currentCharacter == '\'' ) {
            context->currentContext = context->insideSingleQuotes;
            return true;
        }

        if (previousCharacter == '/' && currentCharacter == '/') {
            context->currentContext = context->insideCommentsTypeOne;
            return true;
        }

        if (previousCharacter == '/' && currentCharacter == '*') {
            context->currentContext = context->insideCommentsTypeTwo;
            return true;
        }

        if (previousCharacter == '\\') {
            printf(ANSI_COLOR_RED"[Error]: This character %c%c is used only inside a single quotes ('') or double quotes (\"\"):", previousCharacter, currentCharacter);
            return false;
        }

    } else if (context->currentContext == context->insideDoubleQuotes) {
        if (previousCharacter != '\\' && currentCharacter == '"') {
            context->currentContext = context->outside;
            return true;
        }

        if (currentCharacter == '\n') {
            printf(ANSI_COLOR_RED"[Error]: Missed double quotes: \" ");
            context->currentContext = context->outside;
            return false;
        }
    } else if (context->currentContext == context->insideSingleQuotes) {
        if (previousCharacter != '\\' && currentCharacter == '\'') {
            context->currentContext = context->outside;
            return true;
        }

        if (currentCharacter == '\n') {
            printf(ANSI_COLOR_RED"[Error]: Missed single quote: ' ");
            context->currentContext = context->outside;
            return false;
        }
    } else if (context->currentContext == context->insideCommentsTypeOne) {
        if (currentCharacter == '\n' || currentCharacter == EOF) {
            context->currentContext = context->outside;
            return true;
        }
    } else if (context->currentContext == context->insideCommentsTypeTwo) {
        if (previousCharacter == '*' && currentCharacter == '/') {
            context->currentContext = context->outside;
            return true;
        }
    } else {
        printf(ANSI_COLOR_RED"[Error]: Unknown context !");
    }

    return false;
}

bool isEmpty(int index) {
    return index == -1;
}

bool isFull(int index) {
    return index == STACK_SIZE;
}

void push(int character, int stack[], int *index) {
    if (isFull(*index)) {
        printf(ANSI_COLOR_RED "[Error]: The stack is full.");
        return;
    }

    (*index)++;
    stack[*index] = character;
}

int pop(int stack[], int *index) {
    if (isEmpty(*index)) {
        printf(ANSI_COLOR_RED "[Error]: The stack is empty so no element stil.");
        return -1;
    }

    (*index)--;
    return stack[*index];
}