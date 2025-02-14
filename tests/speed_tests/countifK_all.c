#include <stdlib.h>
#include <stdio.h>
#include "countifK.h"



#define MY_CONDITION(a) (*(a) < 5)
DEFINE_COUNTIFK(int, int, MY_CONDITION)



int main(int argc, const char *argv[]) {
    long long int n = atoll(argv[1]);

    int *array = (int*)malloc(n*sizeof(n));
    for (long long int i=0; i<n; i++) {
        array[i] = 0;
    }

    int res = countifK_int(&array[0], &array[n]);

    return 0;
}