#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "countK.h"

DEFINE_COUNTK(int, int)



int main(int argc, const char *argv[]) {
    long long int n = atoll(argv[1]);

    int *array = (int*)malloc(n*sizeof(n));
    for (long long int i=0; i<n; i++) {
        array[i] = 0;
    }

    clock_t start = clock();
    for (int i=0; i<5; i++) {
        int res = countK_int(&array[0], &array[n], 5);
    }
    clock_t end = clock();
    double time = (double)(end-start)/CLOCKS_PER_SEC;
    printf("%fs", time);
    
    return 0;
}