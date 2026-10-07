#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <math.h>

long long int computeRange(long long int bit, long long int sign);

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
 
  printf("--------> Signed values: \n");

  printf("    char [%d, %d]\n", computeRange(SCHAR_WIDTH - 1, -1), computeRange(SCHAR_WIDTH - 1, 1) );
  printf("    short int [%d, %d]\n", computeRange(SHRT_WIDTH - 1, -1), computeRange(SHRT_WIDTH - 1, 1));
  printf("    int [%d, %d]\n", computeRange(INT_WIDTH - 1, -1), computeRange(INT_WIDTH - 1, 1));
  fflush(stdout);
  printf("    long int [%ld, %ld]\n", computeRange(LONG_WIDTH - 1, -1), computeRange(LONG_WIDTH - 1, 1));
  printf("    long long int [%lld, %lld]\n", computeRange(LLONG_WIDTH - 1, -1), computeRange(LLONG_WIDTH - 1, 1));


  printf("--------> Unsigned values: \n");

  printf("    char [%u, %u]\n", 0, computeRange(UCHAR_WIDTH, 1));
  printf("    short int [%hu, %hu]\n", 0,  computeRange(USHRT_WIDTH, 1));
  printf("    int [%u, %u]\n", 0, computeRange(UINT_WIDTH, 1));
  printf("    long int [%lu, %lu]\n", 0, (unsigned long int)pow(2LL, (long long int)ULONG_WIDTH) - 1UL);
  printf("    long long int [%llu, %llu]\n", 0, (unsigned long long int)pow(2ULL, (unsigned long long int)ULLONG_WIDTH) - 1ULL);



  printf("\n\n\n");

  printf("#######################################################\n");
  printf("#   Ranges of floating point data types from header   #\n");
  printf("#######################################################\n");
  
  printf("----------> Decimal Notation: \n");
  
  printf("    float[%f, %f]\n", -FLT_MAX, FLT_MAX);
  printf("    double[%f, %f]\n", -DBL_MAX, DBL_MAX);
  printf("    long double[%Lf, %Lf]\n", -LDBL_MAX, LDBL_MAX);
  
  printf("----------> Exponent Notation: \n");
  
  printf("    float[%e, %e]\n", -FLT_MAX, FLT_MAX);          
  printf("    double[%e, %e]\n", -DBL_MAX, DBL_MAX);         
  printf("    long double[%Le, %Le]\n", -LDBL_MAX, LDBL_MAX);


  
  return 0;
}


long long int computeRange(long long int bit, long long int sign) {
  return sign >= 0 ? (long long int)pow(2, bit) - 1 : -1 * (long long int)pow(2, bit);
} 
