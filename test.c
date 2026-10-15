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
  
  printf("len: %d\n", strlenn(msg));
  
  int year = 2027;

  if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
    printf("the year is leap\n");
  } else {
    printf("the year is no leap\n");
  }




   return 0;
}


int strlenn(const char str[]) {
  int len = 0;

  for(int i = 0; str[i] != '\0'; i++) {
    len = i;
  }



  return len;
}
