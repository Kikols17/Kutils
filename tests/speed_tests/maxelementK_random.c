#include <stdlib.h>
#include <stdio.h>
#include "minmaxK.h"

DEFINE_MAXELEMENTK(int, int)

int main(int argc, char* argv[]) {
    int n = atoi(argv[1]);
    srand(n);

    int* array = (int*)malloc(n*sizeof(int));
    for (int i=0; i<n; ++i) {
        array[i] = rand();
    }

    int* max = maxelementK_int(&array[0], &array[n]);

    return 0;
}