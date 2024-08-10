#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

#include "cmp_Kutils.h"



#define VERBOSE false


int test_intcmpK(int n);
int test_doublecmpK(int n);
int test_charcmpK(int n);
int test_bincmpK(int n, size_t datatype_size);


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

int test_bincmpK(int n, size_t datatype_size) {
    for (int i=0; i<n; i++) {
    }

    return 0;
}