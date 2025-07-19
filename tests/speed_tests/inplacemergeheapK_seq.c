#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "otheropsK.h"

#define MY_COMPARE(a, b) ((a) > (b))
DEFINE_INPLACEMERGEK(int, int, MY_COMPARE)

int main(int argc, char* argv[]) {
    int n = atoi(argv[1]);

    int* array = (int*)malloc(n*2*sizeof(int));

    for (int i=0; i<n; ++i) {
        array[i] = i;
    }
    for (int i=n; i<n*2; ++i) {
        array[i] = i;
    }

    clock_t start = clock();
    inplacemergeheapK_int(array, array+n, array+n*2);
    clock_t end = clock();
    double time = (double)(end-start)/CLOCKS_PER_SEC;
    printf("%fs", time);

    free(array);

    return 0;
}