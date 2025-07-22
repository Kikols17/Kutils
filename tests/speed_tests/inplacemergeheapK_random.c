#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "otheropsK.h"

#define MY_COMPARE(a, b) ((a) > (b))
DEFINE_INPLACEMERGEK(int, int, MY_COMPARE)

int main(int argc, char* argv[]) {
    int n = atoi(argv[1]);

    int* array = (int*)malloc(n*2*sizeof(int));

    // Fill array with sorted random numbers
    array[0] = rand() % 10;
    for (int i=1; i<n; ++i) {
        array[i] = array[i-1] + (rand() % 10);
    }
    // Fill array2 with sorted random numbers
    array[n] = rand() % 10;
    for (int i=n+1; i<n*2; ++i) {
        array[i] = array[i-1] + (rand() % 10);
    }

    clock_t start = clock();
    inplacemergeheapK_int(array, array+n, array+n*2);
    clock_t end = clock();
    double time = (double)(end-start)/CLOCKS_PER_SEC;
    printf("%fs", time);

    free(array);

    return 0;
}