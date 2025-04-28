#include <stdlib.h>
#include <stdio.h>
#include "sortK.h"


#define MY_COMPARE(a, b) ((a) > (b))
DEFINE_QUICKSORTK(int, int, MY_COMPARE)


void test(long long int n);


int main(int argc, const char* argv[]) {
    
    test(atoll(argv[1]));

    return 0;
}



void test(long long int n) {
    int *array = (int*)malloc(n*sizeof(int));

    for (long long int i=0; i<n; i++) {
        array[n-i-1] = i;
    }

    quicksortK_int(&array[0], &array[n]);
}