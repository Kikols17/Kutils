#include <stdlib.h>
#include <stdio.h>
#include "minmaxK.h"

DEFINE_MINMAXELEMENTK(long long int, llint)

int main(int argc, char* argv[]) {
    int n = atoi(argv[1]);

    long long int* array = (long long int*)malloc(n*sizeof(int));
    for (int i=0; i<n; ++i) {
        array[i] = i;
    }

    long long int *min, *max;
    minmaxelementK_llint(&array[0], &array[n], &min, &max);

    return 0;
}