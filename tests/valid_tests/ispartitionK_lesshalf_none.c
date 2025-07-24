#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "partitioningK.h"

int n;

#define MY_FUNC(e) ((e)>(n/2) == 0)
DEFINE_ISPARTITIONEDK(int, int, MY_FUNC, isLessThanHalf)

int main(int argc, char* argv[]) {
    n = atoi(argv[1]);

    int* array = (int*)malloc(n*sizeof(int));

    for (int i=0; i<n; ++i) {
        array[i] = n/2+i/2;
        printf("%d\n", array[i]);
    }
    printf("\n");

    printf("%d\n", ispartitionedK_int_isLessThanHalf(array, array+n));

    free(array);

    return 0;
}