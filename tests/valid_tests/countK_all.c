#include <stdlib.h>
#include <stdio.h>
#include "nonmodseqopK.h"


DEFINE_COUNTK(int, int)



int main(int argc, const char *argv[]) {
    long long int n = atoll(argv[1]);

    int *array = (int*)malloc(n*sizeof(n));
    for (long long int i=0; i<n; i++) {
        array[i] = 5;
    }

    printf("\n%d\n", countK_int(&array[0], &array[n], 5));

    return 0;
}