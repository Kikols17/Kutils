#include <stdlib.h>
#include <stdio.h>
#include "otheropsK.h"

#define MY_COMPARE(a, b) ((a) > (b))
DEFINE_INPLACEMERGEK(int, int, MY_COMPARE)

int main(int argc, char* argv[]) {
    int n = atoi(argv[1]);
    srand(n);

    int* array = (int*)malloc(n*2*sizeof(int));

    for (int i=0; i<n; ++i) {
        array[i] = i;
        printf("%d\n", array[i]);
    }
    printf("\n");
    for (int i=n; i<n*2; ++i) {
        array[i] = i;
        printf("%d\n", array[i]);
    }
    printf("\n");

    inplacemergestackK_int(array, array+n, array+n*2);

    for (int i=0; i<n*2; ++i) {
        printf("%d\n", array[i]);
    }

    free(array);

    return 0;
}