#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "issortedK.h"

#define MY_COMPARE(a, b) ((a) > (b))
DEFINE_ISSORTEDK(int, int, MY_COMPARE)


int main(int argc, const char *argv[]) {
    long long int n = atoll(argv[1]);
    
    int *array = (int*)malloc(n*sizeof(int));
    for (long long int i=0; i<n; i++) {
        array[i] = i;
    }

    clock_t start = clock();
    for (int i=0; i<5; i++) {
        int res = issortedK_int(&array[0], &array[n]);
    }
    clock_t end = clock();
    double time = (double)(end-start)/CLOCKS_PER_SEC;
    printf("%fs", time);

    return 0;
}
