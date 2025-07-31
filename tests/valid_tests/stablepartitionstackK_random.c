#include <stdlib.h>
#include <stdio.h>
#include "partitioningK.h"

int n;

#define MY_FUNC(e) ((e)%2 == 0)
DEFINE_STABLEPARTITIONK(int, int, MY_FUNC, isEven)

int main(int argc, char* argv[]) {
    n = atoi(argv[1]);
    srand(n);

    int* array = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; ++i) {
        array[i] = rand() % 100;
        printf("%d\n", array[i]);
    }
    printf("\n\n");

    stablepartitionstackK_int_isEven(array, array + n);

    for (int i=0; i<n; ++i) {
        printf("%d\n", array[i]);
    }

    free(array);

    return 0;
}