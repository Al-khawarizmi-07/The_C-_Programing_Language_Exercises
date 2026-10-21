#include <stdio.h>


int atoi(char string[]);

int main() {
  int result = atoi("10");
  printf("%d", result);
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
