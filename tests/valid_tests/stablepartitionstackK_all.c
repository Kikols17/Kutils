#include <stdlib.h>
#include <stdio.h>
#include "partitioningK.h"

int n;

#define MY_FUNC(e) ((e)>=0)
DEFINE_STABLEPARTITIONK(int, int, MY_FUNC, isNotNegative)

int main(int argc, char* argv[]) {
    n = atoi(argv[1]);

    int* array = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; ++i) {
        array[i] = i;
        printf("%d\n", array[i]);
    }
    printf("\n\n");

    stablepartitionstackK_int_isNotNegative(array, array + n);

    for (int i=0; i<n; ++i) {
        printf("%d\n", array[i]);
    }

    free(array);

    return 0;
}