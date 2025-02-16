#include <stdlib.h>
#include <stdio.h>
#include "minmaxK.h"

DEFINE_MAXELEMENTK(long long int, llint)

int main(int argc, char* argv[]) {
    int n = atoi(argv[1]);

    long long int* array = (long long int*)malloc(n*sizeof(int));
    for (int i=0; i<n; ++i) {
        array[i] = n-i;
    }

    long long int* max = maxelementK_llint(&array[0], &array[n]);

    return 0;
}