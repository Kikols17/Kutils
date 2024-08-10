#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

#include "swap_Kutils.h"



#define VERBOSE false

int test_intswap(int n);
int test_doubleswap(int n);
int test_charswap(int n);
int test_binswap(int n, size_t datatype_size);


int main() {
    int sum = 0;
    int res;

    res = test_intswap(100);
    sum += res;
    printf("[MAIN-DEBUG] \"test_intswapK\": %d\n", res);

    res = test_doubleswap(100);
    sum += res;
    printf("[MAIN-DEBUG] \"test_doubleswapK\": %d\n", res);

    res = test_charswap(100);
    sum += res;
    printf("[MAIN-DEBUG] \"test_charswapK\": %d\n", res);

    res = test_binswap(100, sizeof(int));
    sum += res;
    printf("[MAIN-DEBUG] \"test_binswapK\": %d\n", res);

    return sum;
}



int test_intswap(int n) {
    for (int i=0; i<n; i++) {
        int or_a = rand() % 1000 - 500;
        int or_b = rand() % 1000 - 500;
        int a = or_a;
        int b = or_b;
        intswapK(&a, &b, sizeof(int));
        if (a==or_b && b==or_a) {
            #if VERBOSE
            printf("swapK test %ld passed: a->%d, b->%d\n", i, a, b);
            #endif
        } else {
            #if VERBOSE
            printf("swapK test %ld failed: a->%d, b->%d\n", i, a, b);
            #endif
            return 1;
        }
    }

    return 0;
}

int test_doubleswap(int n) {
    for (int i=0; i<n; i++) {
        double or_a = (double)rand() / (double)RAND_MAX;
        double or_b = (double)rand() / (double)RAND_MAX;
        double a = or_a;
        double b = or_b;
        doubleswapK(&a, &b, sizeof(double));
        if (a==or_b && b==or_a) {
            #if VERBOSE
            printf("swapK test %ld passed: a->%f, b->%f\n", i, a, b);
            #endif
        } else {
            #if VERBOSE
            printf("swapK test %ld failed: a->%f, b->%f\n", i, a, b);
            #endif
            return 1;
        }
    }
    return 0;
}

int test_charswap(int n) {
    for (int i=0; i<n; i++) {
        char or_a = rand() % 256;
        char or_b = rand() % 256;
        char a = or_a;
        char b = or_b;
        charswapK(&a, &b, sizeof(char));
        if (a==or_b && b==or_a) {
            #if VERBOSE
            printf("swapK test %ld passed: a->%c, b->%c\n", i, a, b);
            #endif
        } else {
            #if VERBOSE
            printf("swapK test %ld failed: a->%c, b->%c\n", i, a, b);
            #endif
            return 1;
        }
    }
    return 0;
}

int test_binswap(int n, size_t datatype_size) {
    for (int i=0; i<n; i++) {
        char or_a[datatype_size];
        char or_b[datatype_size];
        for (int j=0; j<datatype_size; j++) {
            or_a[j] = rand() % 256;
            or_b[j] = rand() % 256;
        }
        char a[datatype_size];
        char b[datatype_size];
        memcpy(a, or_a, datatype_size);
        memcpy(b, or_b, datatype_size);
        binswapK(a, b, datatype_size);
        if (memcmp(a, or_b, datatype_size)==0 && memcmp(b, or_a, datatype_size)==0) {
            #if VERBOSE
            printf("swapK test %ld passed: a->%s, b->%s\n", i, a, b);
            #endif
        } else {
            #if VERBOSE
            printf("swapK test %ld failed: a->%s, b->%s\n", i, a, b);
            #endif
            return 1;
        }
    }
    return 0;
}