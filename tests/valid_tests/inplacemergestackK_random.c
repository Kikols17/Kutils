#include <stdlib.h>
#include <stdio.h>
#include "otheropsK.h"

#define MY_COMPARE(a, b) ((a) > (b))
DEFINE_INPLACEMERGEK(int, int, MY_COMPARE)

int main(int argc, char* argv[]) {
    int n = atoi(argv[1]);
    srand(n);

    int* array = (int*)malloc(n*2*sizeof(int));

    // Fill array with sorted random numbers
    array[0] = rand() % 10;
    printf("%d\n", array[0]);
    for (int i=1; i<n; ++i) {
        array[i] = array[i-1] + (rand() % 10);
        printf("%d\n", array[i]);
    }
    printf("\n");
    // Fill array2 with sorted random numbers
    array[n] = rand() % 10;
    printf("%d\n", array[n]);
    for (int i=n+1; i<n*2; ++i) {
        array[i] = array[i-1] + (rand() % 10);
        printf("%d\n", array[i]);
    }
    printf("\n");

    inplacemergestackK_int(array, array+n, array+n*2);

    for (int i=0; i<n*2; ++i) {
        printf("%d\n", array[i]);
    }
    printf("\n");

    free(array);

    return 0;
}