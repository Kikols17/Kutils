#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "partitioningK.h"

int n;

#define MY_FUNC(e) ((e)%2 == 0)
DEFINE_PARTITIONCOPYK(int, int, MY_FUNC, isEven)

int main(int argc, char* argv[]) {
    n = atoi(argv[1]);
    srand(n);

    int* array = (int*)malloc(n * sizeof(int));
    int* true_array = (int*)malloc(n * sizeof(int));
    int* false_array = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; ++i) {
        array[i] = rand()%100;
    }

    int* endt, *endf;
    clock_t start = clock();
    for (int i=0; i<20; ++i) {
        partitioncopyK_int_isEven(array, array + n, true_array, false_array, &endt, &endf);
    }
    clock_t end = clock();
    double time = (double)(end-start)/CLOCKS_PER_SEC;
    printf("%fs", time);

    free(array);
    free(true_array);
    free(false_array);
    
    return 0;
}