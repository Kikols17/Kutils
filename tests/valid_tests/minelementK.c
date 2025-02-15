#include <stdlib.h>
#include <stdio.h>
#include "minmaxK.h"

DEFINE_MINELEMENTK(int, int)

int main(int argc, char* argv[]) {
    int n = atoi(argv[1]);
    srand(n);

    int* array = (int*)malloc(n*sizeof(int));
    for (int i=0; i<n; ++i) {
        array[i] = rand();
        printf("%d\n", array[i]);
    }

    printf("\nMin: %d\n", (int)(minelementK_int(&array[0], &array[n])-&array[0]));

    free(array);

    return 0;
}