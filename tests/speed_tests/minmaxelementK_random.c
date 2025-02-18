#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "minmaxK.h"

DEFINE_MINMAXELEMENTK(int, int)

int main(int argc, char* argv[]) {
    int n = atoi(argv[1]);
    srand(n);

    int* array = (int*)malloc(n*sizeof(int));
    for (int i=0; i<n; ++i) {
        array[i] = rand();
    }

    clock_t start = clock();
    for (int i=0; i<5; i++) {
        int* min, *max;
        minmaxelementK_int(&array[0], &array[n], &min, &max);
    }
    clock_t end = clock();
    double time = (double)(end-start)/CLOCKS_PER_SEC;
    printf("%fs", time);

    return 0;
}