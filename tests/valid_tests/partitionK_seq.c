#include <stdlib.h>
#include <stdio.h>
#include "partitioningK.h"

#define MY_FUNC(e) ((e)% 2 == 0)
DEFINE_PARTITIONK(int, int, MY_FUNC, isEven)

int main(int argc, char* argv[]) {
    int n = atoi(argv[1]);

    int* array = (int*)malloc(n*sizeof(int));

    for (int i=0; i<n; ++i) {
        array[i] = i;
        printf("%d\n", array[i]);
    }
    printf("\n");

    printf("%ld\n\n", (partitionK_int_isEven(array, array+n) - array));

    for (int i=0; i<n; ++i) {
        printf("%d\n", array[i]);
    }

    free(array);

    return 0;
}