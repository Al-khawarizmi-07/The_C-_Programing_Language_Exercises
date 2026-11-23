#include <stdio.h>
#include <ctype.h>


int main() {
  signed char testMachineSign = 'a';
  signed int test = testMachineSign;
  printf("%d", testMachineSign);
  printf("%d", test);

  return 0;
}
