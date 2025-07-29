#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "partitioningK.h"

#define MY_FUNC(e) ((e)%2 == 0)
DEFINE_PARTITIONK(int, int, MY_FUNC, isEven)

int main(int argc, char* argv[]) {
    int n = atoi(argv[1]);

    int* array = (int*)malloc(n*sizeof(int));

    for (int i=0; i<n; ++i) {
        array[i] = i;
    }

    clock_t start = clock();
    for (int i=0; i<10; ++i) {
        partitionK_int_isEven(array, array+n);
    }
    clock_t end = clock();
    double time = (double)(end-start)/CLOCKS_PER_SEC;
    printf("%fs", time);

    free(array);

    return 0;
}