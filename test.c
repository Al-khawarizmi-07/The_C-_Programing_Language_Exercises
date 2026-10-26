#include <stdio.h>
#include <ctype.h>


int atoi(char string[]);
char lower(char character);

int main() {
  //int result = atoi("10");
  //printf("%d", result);
  //printf("%c", lower('Z'));
  //printf("%d", isdigit('0'));
  printf("%d", -1L > 1LU);
  return 0;
}

int atoi(char string[]) {
  int number = 0;

  for(int i = 0; string[i] != '\0'; i++) {
    if (string[i] <= '9' && string[i] >= '0') {
      number = 10 * number + (string[i] - '0');
    }
  }

  return number;
}

char lower(char character) {
  if (character >= 'A' && character <= 'Z') {
    return character + ('a' - 'A');
  }
}
