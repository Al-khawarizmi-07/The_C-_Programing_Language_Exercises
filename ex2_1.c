#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <math.h>

int computeRange(int bit, int sign);

int main() {
  printf("###########################################################\n");
  printf("#   Ranges of integral data types from standard headers   #\n");
  printf("###########################################################\n");
  printf("--------> Signed values: \n");
  
  
  printf("    char [%d, %d]\n", SCHAR_MIN, SCHAR_MAX);
  printf("    short int [%hd, %hd]\n", SHRT_MIN, SHRT_MAX);
  printf("    int [%d, %d]\n", INT_MIN, INT_MAX);
  printf("    long int [%ld, %ld]\n", LONG_MIN, LONG_MAX);
  printf("    long long int [%lld, %lld]\n", LLONG_MIN, LLONG_MAX);


  printf("--------> Unsigned values: \n");

  printf("    char [%u, %u]\n", 0, UCHAR_MAX);
  printf("    short int [%hu, %hu]\n", 0,  USHRT_MAX);
  printf("    int [%u, %u]\n", 0, UINT_MAX);
  printf("    long int [%lu, %lu]\n", 0, ULONG_MAX);
  printf("    long long int [%llu, %llu]\n", 0, ULLONG_MAX);


  printf("\n\n\n");
  
  printf("######################################################\n");
  printf("#   Ranges of integral data types from computation   #\n");
  printf("######################################################\n");
  
  printf("    char [%d, %d]\n", computeRange(SCHAR_WIDTH, -1), computeRange(SCHAR_WIDTH, 1) );
  printf("    short int [%d, %d]\n", computeRange(SHRT_WIDTH, -1), computeRange(SHRT_WIDTH, 1));
  printf("    int [%d, %d]\n", computeRange(INT_WIDTH, -1), computeRange(INT_WIDTH, 1));
  printf("    long int [%ld, %ld]\n", computeRange(LONG_WIDTH, -1), computeRange(LONG_WIDTH, 1));
  printf("    long long int [%lld, %lld]\n", computeRange(LLONG_WIDTH, -1), computeRange(LLONG_WIDTH, 1));


  printf("--------> Unsigned values: \n");

  printf("    char [%u, %u]\n", 0, computeRange(UCHAR_WIDTH + 1, 1));
  printf("    short int [%hu, %hu]\n", 0,  computeRange(USHRT_WIDTH + 1, 1));
  printf("    int [%u, %u]\n", 0, computeRange(UINT_WIDTH + 1, 1));
  printf("    long int [%lu, %lu]\n", 0, computeRange(ULONG_WIDTH + 1, 1));
  printf("    long long int [%llu, %llu]\n", 0, computeRange(ULLONG_WIDTH + 1, 1));



  printf("\n\n\n");

  printf("############################################################\n");
  printf("#   Ranges of floating point data types from computation   #\n");
  printf("############################################################\n");
   

  return 0;
}


int computeRange(int bit, int sign) {
  return sign * pow(2, bit - 1) - 1;
} 
