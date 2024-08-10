#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

#include "swap_Kutils.h"



#define VERBOSE false

int test_charswap(int n);

int test_intswap(int n);
int test_shintswap(int n);
int test_lintswap(int n);
int test_llintswap(int n);

int test_floatswap(int n);

int test_doubleswap(int n);
int test_ldoubleswap(int n);

int test_binswap(int n, size_t datatype_size);


int main() {
    int sum = 0;
    int res;

    res = test_charswap(100);
    sum += res;
    printf("[MAIN-DEBUG] \"test_charswapK\": %d\n", res);
    printf("\n");


    res = test_intswap(100);
    sum += res;
    printf("[MAIN-DEBUG] \"test_intswapK\": %d\n", res);

    res = test_shintswap(100);
    sum += res;
    printf("[MAIN-DEBUG] \"test_shintswapK\": %d\n", res);

    res = test_lintswap(100);
    sum += res;
    printf("[MAIN-DEBUG] \"test_lintswapK\": %d\n", res);

    res = test_llintswap(100);
    sum += res;
    printf("[MAIN-DEBUG] \"test_llintswapK\": %d\n", res);
    printf("\n");


    res = test_floatswap(100);
    sum += res;
    printf("[MAIN-DEBUG] \"test_floatswap\": %d\n", res);
    printf("\n");


    res = test_doubleswap(100);
    sum += res;
    printf("[MAIN-DEBUG] \"test_doubleswapK\": %d\n", res);

    res = test_ldoubleswap(100);
    sum += res;
    printf("[MAIN-DEBUG] \"test_ldoubleswapK\": %d\n", res);
    printf("\n");


    res = test_binswap(100, 15);
    sum += res;
    printf("[MAIN-DEBUG] \"test_binswapK\": %d\n", res);

    return sum;
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
            printf("swapK test %d passed: a->%c, b->%c\n", i, a, b);
            #endif
        } else {
            #if VERBOSE
            printf("swapK test %d failed: a->%c, b->%c\n", i, a, b);
            #endif
            return 1;
        }
    }
    return 0;
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
            printf("swapK test %d passed: a->%d, b->%d\n", i, a, b);
            #endif
        } else {
            #if VERBOSE
            printf("swapK test %d failed: a->%d, b->%d\n", i, a, b);
            #endif
            return 1;
        }
    }

    return 0;
}

int test_shintswap(int n) {
    for (int i=0; i<n; i++) {
        short int or_a = (short int)(rand()%1000-500);
        short int or_b = (short int)(rand()%1000-500);
        short int a = or_a;
        short int b = or_b;
        shintswapK(&a, &b, sizeof(short int));
        if (a==or_b && b==or_a) {
            #if VERBOSE
            printf("swapK test %d passed: a->%d, b->%d\n", i, a, b);
            #endif
        } else {
            #if VERBOSE
            printf("swapK test %d failed: a->%d, b->%d\n", i, a, b);
            #endif
            return 1;
        }
    }

    return 0;
}

int test_lintswap(int n) {
    for (int i=0; i<n; i++) {
        long int or_a = rand() % 10000000000 - 5000000000;
        long int or_b = rand() % 10000000000 - 5000000000;
        long int a = or_a;
        long int b = or_b;
        lintswapK(&a, &b, sizeof(long int));
        if (a==or_b && b==or_a) {
            #if VERBOSE
            printf("swapK test %d passed: a->%ld, b->%ld\n", i, a, b);
            #endif
        } else {
            #if VERBOSE
            printf("swapK test %d failed: a->%ld, b->%ld\n", i, a, b);
            #endif
            return 1;
        }
    }

    return 0;
}

int test_llintswap(int n) {
    for (int i=0; i<n; i++) {
        long long int or_a = rand() % 10000000000000 - 5000000000000;
        long long int or_b = rand() % 10000000000000 - 5000000000000;
        long long int a = or_a;
        long long int b = or_b;
        llintswapK(&a, &b, sizeof(long long int));
        if (a==or_b && b==or_a) {
            #if VERBOSE
            printf("swapK test %d passed: a->%lld, b->%lld\n", i, a, b);
            #endif
        } else {
            #if VERBOSE
            printf("swapK test %d failed: a->%lld, b->%lld\n", i, a, b);
            #endif
            return 1;
        }
    }

    return 0;
}



int test_floatswap(int n) {
    for (int i=0; i<n; i++) {
        float or_a = (float)rand() / (float)RAND_MAX;
        float or_b = (float)rand() / (float)RAND_MAX;
        float a = or_a;
        float b = or_b;
        floatswapK(&a, &b, sizeof(float));
        if (a==or_b && b==or_a) {
            #if VERBOSE
            printf("swapK test %d passed: a->%f, b->%f\n", i, a, b);
            #endif
        } else {
            #if VERBOSE
            printf("swapK test %d failed: a->%f, b->%f\n", i, a, b);
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
            printf("swapK test %d passed: a->%f, b->%f\n", i, a, b);
            #endif
        } else {
            #if VERBOSE
            printf("swapK test %d failed: a->%f, b->%f\n", i, a, b);
            #endif
            return 1;
        }
    }
    return 0;
}

int test_ldoubleswap(int n) {
    for (int i=0; i<n; i++) {
        long double or_a = (long double)rand() / (long double)RAND_MAX;
        long double or_b = (long double)rand() / (long double)RAND_MAX;
        long double a = or_a;
        long double b = or_b;
        ldoubleswapK(&a, &b, sizeof(long double));
        if (a==or_b && b==or_a) {
            #if VERBOSE
            printf("swapK test %d passed: a->%Lf, b->%Lf\n", i, a, b);
            #endif
        } else {
            #if VERBOSE
            printf("swapK test %d failed: a->%Lf, b->%Lf\n", i, a, b);
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
            printf("swapK test %d passed: a->%s, b->%s\n", i, a, b);
            #endif
        } else {
            #if VERBOSE
            printf("swapK test %d failed: a->%s, b->%s\n", i, a, b);
            #endif
            return 1;
        }
    }
    return 0;
}