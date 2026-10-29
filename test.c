#include <stdio.h>
#include <ctype.h>


void testo(int test);

int main() {
  int i = 1255555555;
  float x = i;


  printf("%d\n", i);
  printf("%f\n", x);

  i = x;

  printf("%d\n", i);
  printf("%f\n", x);

  testo(10);

  return 0;
}

void testo(int test) {
  printf("%d", test);
}
