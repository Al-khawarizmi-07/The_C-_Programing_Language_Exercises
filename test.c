#include <stdio.h>
#include <limits.h>
#include <float.h>

int noAutomatic;

int strlenn(const char str[]);

int main() {
  int automatic;
  printf("no automatic variable: %d, \nautomatic variable:%d\n", noAutomatic, automatic);


  const double e = 2.71828182845905;
  const char msg[] = "warning: ";

  printf("e: %f, msg[]: %s", e, msg);
  
  printf("len: %d", strlenn(msg));
  
   return 0;
}


int strlenn(const char str[]) {
  int len = 0;

  for(int i = 0; str[i] != '\0'; i++) {
    len = i;
  }



  return len;
}
