#include <stdlib.h>
#include <stdio.h>
#include "binsearchK.h"

#define MY_COMPARE(a, b) ((a) > (b))
DEFINE_BINARYSEARCHK(int, int, MY_COMPARE)

int main(int argc, char* argv[]) {
    int n = atoi(argv[1]);

    int* array = (int*)malloc(n*sizeof(int));
    for (int i=0; i<n; ++i) {
        array[i] = i;
        printf("%d\n", array[i]);
    }

    printf("\nbinsearch: %d\n", (int)(binarysearchK_int(&array[0], &array[n], rand()%n)!=&array[n]));

    free(array);

    return 0;
}