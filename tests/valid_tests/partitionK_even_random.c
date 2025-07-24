#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "partitioningK.h"

#define MY_FUNC(e) ((e)%2 == 0)
DEFINE_PARTITIONK(int, int, MY_FUNC, isEven)

int main(int argc, char* argv[]) {
    int n = atoi(argv[1]);
    srand(n);

    int* array = (int*)malloc(n*sizeof(int));

    for (int i=0; i<n; ++i) {
        array[i] = rand();
        printf("%d\n", array[i]);
    }

    for (int i=0; i<10; ++i) {
        printf("%ld\n", partitionK_int_isEven(array, array+n) - array);
    }

    free(array);

    return 0;
}