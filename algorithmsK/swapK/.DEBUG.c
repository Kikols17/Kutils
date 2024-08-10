#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

#include "swap_Kutils.h"



#define VERBOSE false

int test_intswap(int n);
//int test_doubleswap(int n);
//int test_charswap(int n);
//int test_binswap(int n);


int main() {
    int sum = 0;
    int res;

    res = test_intswap(100);
    sum += res;
    printf("[MAIN-DEBUG] \"test_intswapK\": %d\n", res);

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