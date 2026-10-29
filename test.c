#include <stdio.h>
#include <ctype.h>



int main() {
  int i = 1255555555;
  float x = i;


  printf("%d\n", i);
  printf("%f\n", x);

  i = x;

  printf("%d\n", i);
  printf("%f\n", x);

  return 0;
}

