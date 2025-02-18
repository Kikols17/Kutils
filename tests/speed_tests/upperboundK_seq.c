#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "binsearchK.h"

#define MY_COMPARE(a, b) ( (a) > (b) )
DEFINE_UPPERBOUNDK(int, int, MY_COMPARE)

int main(int argc, char* argv[]) {
    int n = atoi(argv[1]);

    int* array = (int*)malloc(n*sizeof(int));
    for (int i=0; i<n; ++i) {
        array[i] = i;
    }

    clock_t start = clock();
    for (int i=0; i<5; ++i) {
        int* p = upperboundK_int(&array[0], &array[n], n*(3/7));
    }
    clock_t end = clock();
    double time = (double)(end-start)/CLOCKS_PER_SEC;
    printf("%fs", time);

    free(array);

    return 0;
}