#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "otheropsK.h"

#define MY_COMPARE(a, b) ((a) > (b))
DEFINE_MERGEK(int, int, MY_COMPARE)

int main(int argc, char* argv[]) {
    int n = atoi(argv[1]);
    int mid = rand() % n;

    int* array1 = (int*)malloc(mid*sizeof(int));
    int* array2 = (int*)malloc((n - mid)*sizeof(int));

    // Fill array1 with sorted random numbers
    array1[0] = rand() % 10;
    for (int i=1; i<mid; ++i) {
        array1[i] = array1[i-1] + (rand() % 10);
    }
    // Fill array2 with sorted random numbers
    array2[0] = rand() % 10;
    for (int i=1; i<(n-mid); ++i) {
        array2[i] = array2[i-1] + (rand() % 10);
    }

    int* output = (int*)malloc(n*sizeof(int));

    clock_t start = clock();
    int* outout_end = mergeK_int(array1, array1+mid, array2, array2+(n-mid), output);
    clock_t end = clock();
    double time = (double)(end-start)/CLOCKS_PER_SEC;
    printf("%fs", time);


    free(array1);
    free(array2);
    free(output);

    return 0;
}