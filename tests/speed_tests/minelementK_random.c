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
    }

    int* max = minelementK_int(&array[0], &array[n]);

    return 0;
}