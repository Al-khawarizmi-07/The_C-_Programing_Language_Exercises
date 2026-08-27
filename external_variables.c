//
// Created by Yassi on 2/21/2026.
//


/* *
 * this is a revised main program where we can print the original length of the overflow buffer of string the is defined by the MACRO MAX_LINE_LENGTH
 * this is a program that save the maximum length typed by the user
 * so each time the user type the line and the program compare if the line is the longest one
 * if the EOF was reached so in this case the program will be terminated and then print the longest line with its value
 */

#include <stdio.h>
#define MAX_LINE_LENGTH 1000 // this is the maximum length of the line that can be hold by the program

/**
 * External variables
 */
char savedLine[MAX_LINE_LENGTH];
char line[MAX_LINE_LENGTH];
int savedLineLength = 0;

/**
 *  this function "getLine" is used to get the line from the standard input using the function getChar() then put it in the @param array passed by reference
 *
 * @param array this is a parameter of the character array name that will be used to hold the argument array address it's used as a way to hold the value of line and returned
 * @param maxLineLength this is a parameter that is used as the limit of the number of character that can be memorized by the function
 * @return the function return an int value that is used as the length of the line returned and also as a signal value of the EOF that is 0.
 */
int getLine();

/**
 * this is function is used to print the array character to the standard output
 * @param array this is the array passed as reference used to print its elements to the standard output
 */
void putLine(char array[]);

/**
 *  this function is used to copy the elements of source arrays to the elements of destination arrays
 *
 * @param sourceArray this parameter represent the source array
 * @param destinationArray this parameter represent the destionation arry
 */
void copyLine();


int main() {
    extern char savedLine[];
    extern int savedLineLength;

    int lineLength = 0;

    while ((lineLength = getLine()) != 0) {
        if (savedLineLength < lineLength) {
            savedLineLength = lineLength;
            copyLine();
        }
    }

    printf("The longest line length is: %d\n", savedLineLength);
    printf("The longest line is : ");
    putLine(savedLine);

    return 0;
}

int getLine() {
    extern char line[];
    int character;
    int index;

    for (index = 0; (character = getchar()) != EOF &&  character != '\n' ; index++)
        if (index < MAX_LINE_LENGTH - 1)
            line[index] = character;
    if (character == '\n') {
        line[index] = character;
        index++;
    }
    line[index] = '\0';
    return index;
}


void copyLine() {
    extern char line[];
    extern char savedLine[];

    int index;
    for (index = 0; line[index] != '\0' && index < MAX_LINE_LENGTH - 1; index++)
        savedLine[index] = line[index];
    savedLine[index] = '\0';
}

void putLine(char array[]) {
    for (int index = 0; array[index] != '\0' && index < MAX_LINE_LENGTH - 1 ; index++)
        putchar(array[index]);
}