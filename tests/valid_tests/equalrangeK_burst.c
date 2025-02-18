#include <stdlib.h>
#include <stdio.h>
#include "binsearchK.h"

#define MY_COMPARE(a, b) ((a) > (b))
DEFINE_EQUALRANGEK(int, int, MY_COMPARE)

int main(int argc, char* argv[]) {
    int n = atoi(argv[1]);
    srand(n);

    int* array = (int*)malloc(n*5*sizeof(int));
    for (int i=0; i<n*5; i+=5) {
        array[i] = i;
        array[i+1] = i;
        array[i+2] = i;
        array[i+3] = i;
        array[i+4] = i;
        printf("%d\n%d\n%d\n%d\n%d\n", array[i], array[i+1], array[i+2], array[i+3], array[i+4]);
    }

    int value = rand()%n;
    printf("\nvalue: %d\n", value);

    int *lower, *upper;
    equalrangeK_int(&array[0], &array[n*5], value, &lower, &upper);
    printf("equalrange: %d %d\n", (int)(lower-&array[0]), (int)(upper-&array[0]));

    free(array);

    return 0;
}