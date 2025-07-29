#include <stdlib.h>
#include <stdio.h>
#include "partitioningK.h"

int n;

#define MY_FUNC(e) ((e)<0)
DEFINE_PARTITIONCOPYK(int, int, MY_FUNC, isNegative)

int main(int argc, char* argv[]) {
    n = atoi(argv[1]);

    int* array = (int*)malloc(n * sizeof(int));
    int* true_array = (int*)malloc(n * sizeof(int));
    int* false_array = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; ++i) {
        array[i] = i;
        printf("%d\n", array[i]);
    }
    printf("\n\n");

    int *endt, *endf;
    partitioncopyK_int_isNegative(array, array + n, true_array, false_array, &endt, &endf);

    printf("%ld\n", endt - true_array);
    for (int* it = true_array; it != endt; ++it) {
        printf("%d\n", *it);
    }
    printf("\n");
    
    printf("%ld\n", endf - false_array);
    for (int* it = false_array; it != endf; ++it) {
        printf("%d\n", *it);
    }
    printf("\n");

    free(array);
    free(true_array);
    free(false_array);
    
    return 0;
}