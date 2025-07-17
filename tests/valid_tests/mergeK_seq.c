#include <stdlib.h>
#include <stdio.h>
#include "otheropsK.h"

#define MY_COMPARE(a, b) ((a) > (b))
DEFINE_MERGEK(int, int, MY_COMPARE)

int main(int argc, char* argv[]) {
    int n = atoi(argv[1]);

    int* array1 = (int*)malloc(n*sizeof(int));
    int* array2 = (int*)malloc(n*sizeof(int));

    for (int i=0; i<n; ++i) {
        array1[i] = i;
        printf("%d\n", array1[i]);
    }
    printf("\n");
    for (int i=0; i<n; ++i) {
        array2[i] = i;
        printf("%d\n", array2[i]);
    }
    printf("\n");

    int* output = (int*)malloc(n*2*sizeof(int));

    printf("%ld\n\n", (mergeK_int(array1, array1+n, array2, array2+n, output) - output));

    for (int i=0; i<n*2; ++i) {
        printf("%d\n", output[i]);
    }

    free(array1);
    free(array2);
    free(output);

    return 0;
}