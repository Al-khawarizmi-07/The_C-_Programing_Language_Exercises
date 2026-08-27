//
// Created by Yassi on 12/7/2025.
//

#include <stdio.h>

int main() {
    double i;
    for (i = 0; getchar() != EOF; i++)
        ;
    printf("%.0f\n", i);
    return 0;
}