#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

#include "sort_Kutils.h"
#include "../swapK/swap_Kutils.h"



#define VERBOSE false


int test_intcmpK(int n);
int test_doublecmpK(int n);
int test_charcmpK(int n);

int test_sort(int n, int k, void (sort_type)(void *begin, void *end, size_t datatype_size, int (*cmp)(const void *, const void *, size_t), void (*swap)(void *, void *, size_t)));


int main() {
    int sum = 0;
    int res = 0;

    res = test_intcmpK(100);
    sum += res;
    printf("[MAIN-DEBUG] \"test_intcmpK\": %d\n", res);

    res = test_doublecmpK(100);
    sum += res;
    printf("[MAIN-DEBUG] \"test_doublecmpK\": %d\n", res);

    res = test_charcmpK(100);
    sum += res;
    printf("[MAIN-DEBUG] \"test_charcmpK\": %d\n", res);

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




int test_intcmpK(int n) {
    for (int i=0; i<n; i++) {
        int a = rand() % 1000 - 500;
        int b = rand() % 1000 - 500;
        int cmp = intcmpK(&a, &b, sizeof(int));
        if (cmp==0) {
            if (a==b) {
                #if VERBOSE
                printf("intcmpK test %d passed: a->%d, b->%d\n", n, a, b);
                #endif
            } else {
                #if VERBOSE
                printf("intcmpK test %d failed: a->%d, b->%d\n", n, a, b);
                #endif
                return 1;
            }
        } else if (cmp<0) {
            if (a<b) {
                #if VERBOSE
                printf("intcmpK test %d passed: a->%d, b->%d\n", n, a, b);
                #endif
            } else {
                #if VERBOSE
                printf("intcmpK test %d failed: a->%d, b->%d\n", n, a, b);
                #endif
                return 1;
            }
        } else if (cmp>0) {
            if (a>b) {
                #if VERBOSE
                printf("intcmpK test %d passed: a->%d, b->%d\n", n, a, b);
                #endif
            } else {
                #if VERBOSE
                printf("intcmpK test %d failed: a->%d, b->%d\n", n, a, b);
                #endif
                return 1;
            }
        } else {
            #if VERBOSE
            printf("intcmpK test %d failed: a->%d, b->%d\n", n, a, b);
            #endif
            return 1;
        }
    }

    return 0;
}

int test_doublecmpK(int n) {
    for (int i=0; i<n; i++) {
        double a = (double)rand() / (double)RAND_MAX * 1000 - 500;
        double b = (double)rand() / (double)RAND_MAX * 1000 - 500;
        int cmp = doublecmpK(&a, &b, sizeof(double));
        if (cmp==0) {
            if (a==b) {
                #if VERBOSE
                printf("doublecmpK test %d passed: a->%f, b->%f\n", n, a, b);
                #endif
            } else {
                #if VERBOSE
                printf("doublecmpK test %d failed: a->%f, b->%f\n", n, a, b);
                #endif
                return 1;
            }
        } else if (cmp<0) {
            if (a<b) {
                #if VERBOSE
                printf("doublecmpK test %d passed: a->%f, b->%f\n", n, a, b);
                #endif
            } else {
                #if VERBOSE
                printf("doublecmpK test %d failed: a->%f, b->%f\n", n, a, b);
                #endif
                return 1;
            }
        } else if (cmp>0) {
            if (a>b) {
                #if VERBOSE
                printf("doublecmpK test %d passed: a->%f, b->%f\n", n, a, b);
                #endif
            } else {
                #if VERBOSE
                printf("doublecmpK test %d failed: a->%f, b->%f\n", n, a, b);
                #endif
                return 1;
            }
        } else {
            #if VERBOSE
            printf("doublecmpK test %d failed: a->%f, b->%f\n", n, a, b);
            #endif
            return 1;
        }
    }

    return 0;
}

int test_charcmpK(int n) {
    for (int i=0; i<n; i++) {
        char a = rand() % 256;
        char b = rand() % 256;
        int cmp = charcmpK(&a, &b, sizeof(char));
        if (cmp==0) {
            if (a==b) {
                #if VERBOSE
                printf("charcmpK test %d passed: a->%c, b->%c\n", n, a, b);
                #endif
            } else {
                #if VERBOSE
                printf("charcmpK test %d failed: a->%c, b->%c\n", n, a, b);
                #endif
                return 1;
            }
        } else if (cmp<0) {
            if (a<b) {
                #if VERBOSE
                printf("charcmpK test %d passed: a->%c, b->%c\n", n, a, b);
                #endif
            } else {
                #if VERBOSE
                printf("charcmpK test %d failed: a->%c, b->%c\n", n, a, b);
                #endif
                return 1;
            }
        } else if (cmp>0) {
            if (a>b) {
                #if VERBOSE
                printf("charcmpK test %d passed: a->%c, b->%c\n", n, a, b);
                #endif
            } else {
                #if VERBOSE
                printf("charcmpK test %d failed: a->%c, b->%c\n", n, a, b);
                #endif
                return 1;
            }
        } else {
            #if VERBOSE
            printf("charcmpK test %d failed: a->%c, b->%c\n", n, a, b);
            #endif
            return 1;
        }
    }

    return 0;
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

