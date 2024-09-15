#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

#include "sort_Kutils.h"
#include "../../datatypehandleK/cmpK/cmpSTD_Kutils.h"
#include "../../datatypehandleK/swapK/swapSTD_Kutils.h"



#define VERBOSE false

int test_sort(int n, int k, void (sort_type)(void *begin, void *end, size_t datatype_size, int (*cmp)(const void *, const void *, size_t), void (*swap)(void *, void *, size_t)));


int main() {
    int sum = 0;
    int res = 0;

    res = test_sort(1, 100000, bubblesortK);
    sum += res;
    printf("[MAIN-DEBUG] \"test_bubblesortK\": %d\n", res);

    res = test_sort(1, 100000, insertsortK);
    sum += res;
    printf("[MAIN-DEBUG] \"test_insertsortK\": %d\n", res);

    res = test_sort(1, 100000, quicksortK);
    sum += res;
    printf("[MAIN-DEBUG] \"test_quicksortK\": %d\n", res);

    res = test_sort(1, 100000, heapsortK);
    sum += res;
    printf("[MAIN-DEBUG] \"test_heapsortK\": %d\n", res);


    return sum;
}




int test_sort(int n, int k, void (sort_type)(void *begin, void *end, size_t datatype_size, int (*cmp)(const void *, const void *, size_t), void (*swap)(void *, void *, size_t))) {
    int *arr = (int *)malloc(k * sizeof(int));

    for (int i=0; i<k; i++) {
        arr[i] = rand() % 1000 - 500;
    }
    
    /*
    for (int i=0; i<k-1; i++) {
        printf("%d, ", arr[i]);
    }
    printf("%d\n", arr[k-1]);
    */
    
    sortK(arr, arr+k, sizeof(int), sort_type, intcmpK, intswapK);
    
    /*
    for (int i=0; i<k-1; i++) {
        printf("%d, ", arr[i]);
    }
    printf("%d\n", arr[k-1]);
    */

    for (int i=0; i<k-1; i++) {
        if (arr[i]>arr[i+1]) {
            #if VERBOSE
            printf("bubblesortK test %d failed: arr[%d]->%d, arr[%d]->%d\n", n, i, arr[i], i+1, arr[i+1]);
            #endif
            return 1;
        }
    }


    return 0;
}

