#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "partitioningK.h"

int n;

#define MY_FUNC(e) ((e)>=0)
DEFINE_STABLEPARTITIONK(int, int, MY_FUNC, isNotNegative)

int main(int argc, char* argv[]) {
    n = atoi(argv[1]);

    int* array = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; ++i) {
        array[i] = i;
    }

    clock_t start = clock();
    stablepartitionstackK_int_isNotNegative(array, array + n);
    clock_t end = clock();
    double time = (double)(end-start)/CLOCKS_PER_SEC;
    printf("%fs", time);

    free(array);

    return 0;
}