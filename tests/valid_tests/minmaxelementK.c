#include <stdlib.h>
#include <stdio.h>
#include "minmaxK.h"

DEFINE_MINMAXELEMENTK(int, int)

int main(int argc, char* argv[]) {
    int n = atoi(argv[1]);
    srand(n);

    int* array = (int*)malloc(n*sizeof(int));
    for (int i=0; i<n; ++i) {
        array[i] = rand();
        printf("%d\n", array[i]);
    }

    int *min, *max;
    minmaxelementK_int(&array[0], &array[n], &min, &max);
    printf("\nMin: %d\nMax: %d\n", *min, *max);

    free(array);

    return 0;
}