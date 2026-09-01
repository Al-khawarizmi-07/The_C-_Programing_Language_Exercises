#include <stdio.h>
#include <stdbool.h>

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN   "\033[32m"
#define ANSI_COLOR_RESET   "\033[0m"

#define DEBUG_MODE

#ifdef DEBUG_MODE
    #define DEBUG_PRINT(fmt, ...) printf(fmt,  ##__VA_ARGS__)
#else
    #define DEBUG_PRINT(fmt, ...)
#endif

// Templates variables
struct Context {
    const int outside;
    const int insideDoubleQuotes;
    const int insideSingleQuotes;
    const int insideCommentsTypeOne; // type one it means this symbols // ended by this symbol \n or this symbol EOF
    const int insideCommentsTypeTwo; // type two it means this symbols /* ended by this symbol */
    const int escapeSequences;
    int currentContext;
    int previousContext;
} typedef Context;

// Global variables
const int STACK_SIZE = 10 * 1024;

// Function prototypes
// Stack functions
void push(int character, int stack[], int *index);
int pop(int stack[], int *index);
bool isEmpty(int index);
bool isFull(int index);
int top(int stack[], const int *index);
// General functions
bool saveToken(Context *context, int previousCharacter, int currentCharacter);
bool isOppositeToken(const int tokenOne, const int tokenTwo);
void analyseTokens(int stack[], int *index);


int main() {
    int stack[STACK_SIZE];
    int index = -1;
    int currentCharacter = -1;
    int previousCharacter = -1;
    Context context = {
        0,
        1,
        2,
        3,
        4,
        5,
    };

    // Fill the stack with the tokens to analyze them
    DEBUG_PRINT("[Debug]: Filling the stack with the tokens\n");
    while ((currentCharacter = getchar()) != EOF) {
        if (saveToken(&context, previousCharacter, currentCharacter)) {
            if ((previousCharacter == '/' && currentCharacter == '/')
                || (previousCharacter == '/' && currentCharacter == '*')
                || (previousCharacter == '*' && currentCharacter == '/')) {

                push(previousCharacter + previousCharacter + currentCharacter, stack, &index);
            } else {
                push(currentCharacter, stack, &index);
            }
        }

        previousCharacter = currentCharacter;
    }

    push(EOF, stack, &index);

    // Analyze the symbols to know if there is any error.
    // show the stack value
    // while (index > - 1) {
    //     printf("token: %3c\n", pop(stack, &index));
    // }

    analyseTokens(stack, &index);

    return 0;
}

bool saveToken(Context *context, const int previousCharacter, const int currentCharacter) {
    if (context->currentContext == context->outside) {
        if (currentCharacter == '\\') {
            context->previousContext = context->currentContext;
            context->currentContext = context->escapeSequences;
            return false;
        }
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
            printf(ANSI_COLOR_RED"[Error]: This character %c%c is used only inside a single quotes ('') or double quotes (\"\")\n"ANSI_COLOR_RESET, previousCharacter, currentCharacter);
            return false;
        }
    } else if (context->currentContext == context->insideDoubleQuotes) {
        if (currentCharacter == '\\') {
            context->previousContext = context->currentContext;
            context->currentContext = context->escapeSequences;
            return false;
        }

        if (currentCharacter == '"') {
            context->currentContext = context->outside;
            return true;
        }

        if (currentCharacter == '\n') {
            printf(ANSI_COLOR_RED"[Error]: Missed double quotes: \" \n"ANSI_COLOR_RESET);
            context->currentContext = context->outside;
            return false;
        }
    } else if (context->currentContext == context->insideSingleQuotes) {
        if (currentCharacter == '\\') {
            context->previousContext = context->currentContext;
            context->currentContext = context->escapeSequences;
            return false;
        }

        if (currentCharacter == '\'') {
            context->currentContext = context->outside;
            return true;
        }

        if (currentCharacter == '\n') {
            printf(ANSI_COLOR_RED"[Error]: Missed single quote: ' \n"ANSI_COLOR_RESET);
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
    } else if (context->currentContext == context->escapeSequences) {
        context->currentContext = context->previousContext;
        return false;
    } else {
        printf(ANSI_COLOR_RED"[Error]: Unknown context !\n"ANSI_COLOR_RESET);
    }

    return false;
}

bool isOppositeToken(const int tokenOne, const int tokenTwo) {
    if ((tokenOne == '{' && tokenTwo == '}')
    || (tokenOne == '(' && tokenTwo == ')')
    || (tokenOne == '[' && tokenTwo == ']')
    || (tokenOne == '"' && tokenTwo == '"')
    || (tokenOne == '\'' && tokenTwo == '\'')
    || (tokenOne == ('/' + '/' + '*') && tokenTwo == ('*' + '*' + '/'))
    || (tokenOne == ('/' + '/' + '/') && (tokenTwo == '\n' || tokenTwo == EOF))
    || (tokenOne == -1 && tokenTwo == EOF)
    || (tokenOne == EOF && tokenTwo == -1)
    || (tokenOne == '\n' && tokenTwo == -1)
    || (tokenOne == -1 && tokenTwo == '\n')) {
        DEBUG_PRINT("[Debug]: tokenOne: %d, tokenTwo: %d\n", tokenOne, tokenTwo);
        return true;
    }
    return false;
}

void analyseTokens(int stack[], int *index) {
    DEBUG_PRINT("[Debug]: Analysing the tokens ...\n");
    int bufferStack[STACK_SIZE];
    int bufferIndex = -1;
    bool isProcessFinished = false;

    while (!isProcessFinished) {
        // this function is for initialization of the bufferStack
        // Empty bufferStack <----> Filled stack
        if (isEmpty(bufferIndex)) {
            DEBUG_PRINT("[Debug]: The buffer stack is empty\n");
            push(pop(stack, index), bufferStack, &bufferIndex);
        }
        // Here we process the phase where Filled bufferStack <-----> Filled stack
        if (!isEmpty(bufferIndex) && !isEmpty(*index)) {
            DEBUG_PRINT("[Debug]: Both the stack are filled\n");
            if (isOppositeToken(top(stack, index), top(bufferStack, &bufferIndex))) {
                pop(stack, index);
                pop(bufferStack, &bufferIndex);
            } else {
                push(pop(stack, index), bufferStack, &bufferIndex);
            }
        }


        // Here we process the phase where Filled bufferStack <----> Empty Stack
        if (!isEmpty(bufferIndex) && isEmpty(*index)) {
            DEBUG_PRINT("[Debug]: The buffer stack is filled and main stack is empty\n");
            if (top(bufferStack, &bufferIndex) == EOF) {
                pop(bufferStack, &bufferIndex);
               // show the stack value
                continue;
            }
            while (bufferIndex > -1) {
                printf("token: %3c\n", pop(bufferStack, &bufferIndex));
            }

            printf(ANSI_COLOR_RED"[Error]: there is a missed opposite for token: %c\n"ANSI_COLOR_RESET, top(bufferStack, &bufferIndex));
            isProcessFinished = true;

            break;
        }

        // Here we process the case where Empty bufferStack <----> Empty Stack
        if (isEmpty(bufferIndex) && isEmpty(*index)) {
            DEBUG_PRINT("[Debug]: Both the stacks are empty\n");
            printf(ANSI_COLOR_GREEN"The source code tokens rules are correct ^^\n"ANSI_COLOR_RESET);
            isProcessFinished = true;
        }
    }

}

bool isEmpty(int index) {
    return index <= -1;
}

bool isFull(int index) {
    return index == STACK_SIZE;
}

void push(int character, int stack[], int *index) {
    DEBUG_PRINT("[Debug]: Pushing element ...\n");
    if (character <= -1) {
        // printf(ANSI_COLOR_RED "[Error]: The character is invalid to be pushed.\n");
        return;
    }
    if (isFull(*index)) {
        printf(ANSI_COLOR_RED "[Error]: The stack is full.\n"ANSI_COLOR_RESET);
        return;
    }

    (*index)++;
    stack[*index] = character;
}

int pop(int stack[], int *index) {
    DEBUG_PRINT("[Debug]: Poping element ...\n");
    int currentIndex = *index;
    if (isEmpty(*index)) {
        printf(ANSI_COLOR_RED "[Error]: The stack is empty so no element still.\n"ANSI_COLOR_RESET);
        return -1;
    }

    (*index)--;
    return stack[currentIndex];
}

int top(int stack[], const int *index) {
    DEBUG_PRINT("[Debug]: Get the top element\n");
    if (! isEmpty(*index)) {
        return stack[*index];
    }

    return -1;
}