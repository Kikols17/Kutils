#include <stdlib.h>
#include <stdio.h>
#include "partitioningK.h"

int n;

#define MY_FUNC(e) ((e)<(n-2))
DEFINE_PARTITIONPOINTK(int, int, MY_FUNC, lesshalf)

int main(int argc, char* argv[]) {
    n = atoi(argv[1]);

    int* array = (int*)malloc(n*sizeof(int));

    for (int i=0; i<n; ++i) {
        array[i] = i;
        printf("%d\n", array[i]);
    }
    printf("\n");

    printf("%ld\n\n", (partitionpointK_int_lesshalf(array, array+n) - array));

    for (int i=0; i<n; ++i) {
        printf("%d\n", array[i]);
    }

    free(array);

    return 0;
}