#include <stdlib.h>
#include <stdio.h>
#include "binsearchK.h"

#define MY_COMPARE(a, b) ((a) > (b))
DEFINE_EQUALRANGEK(int, int, MY_COMPARE)

int main(int argc, char* argv[]) {
    int n = atoi(argv[1]);
    srand(n);

    int* array = (int*)malloc(n*sizeof(int));
    for (int i=0; i<n; ++i) {
        array[i] = 5;
        printf("%d\n", array[i]);
    }

    int value = 5;
    printf("\nvalue: %d\n", value);

    int *lower, *upper;
    equalrangeK_int(&array[0], &array[n], value, &lower, &upper);
    printf("equalrange: %d %d\n", (int)(lower-&array[0]), (int)(upper-&array[0]));

    free(array);

    return 0;
}