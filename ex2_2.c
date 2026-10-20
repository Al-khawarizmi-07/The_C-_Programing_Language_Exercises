#include <stdio.h>


int main() {
  int i = 0;
  int lim = 100;
  int c = 0;
  char s[lim];

  for (i = 0; i < lim - 1; i++) {
    c = getchar();
    if (c != '\n') {
      if (c != EOF) {
        printf("inserting: %c\n", c);
        s[i] = c;
      }
    }
  }
  return 0;
}
