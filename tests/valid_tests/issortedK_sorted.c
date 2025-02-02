#include <stdlib.h>
#include <stdio.h>
#include "issortedK.h"

#define MY_COMPARE(a, b) ((a) > (b))
DEFINE_ISSORTEDK(int, int, MY_COMPARE)


int main(int argc, const char *argv[]) {
    long long int n = atoll(argv[1]);
    
    int *array = (int*)malloc(n*sizeof(int));
    for (long long int i=0; i<n; i++) {
        array[i] = i;
    }

    printf("%d\n", 1*issortedK_int(&array[0], &array[n]));

    return 0;
}
