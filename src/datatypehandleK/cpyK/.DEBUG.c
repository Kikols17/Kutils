#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

#include "cpy_Kutils.h"



#define VERBOSE false


int test_charcpyK(int n);
int test_scharcpyK(int n);
int test_ucharcpyK(int n);

int test_intcpyK(int n);
int test_shintcpyK(int n);
int test_ushintcpyK(int n);
int test_uintcpyK(int n);
int test_lintcpyK(int n);
int test_ulintcpyK(int n);
int test_llintcpyK(int n);
int test_ullintcpyK(int n);

int test_floatcpyK(int n);

int test_doublecpyK(int n);
int test_ldoublecpyK(int n);


int main() {
    int sum = 0;
    int res;

    res = test_charcpyK(100);
    sum += res;
    printf("[MAIN-DEBUG] \"test_charcpyK\": %d\n", res);

    res = test_scharcpyK(100);
    sum += res;
    printf("[MAIN-DEBUG] \"test_scharcpyK\": %d\n", res);

    res = test_ucharcpyK(100);
    sum += res;
    printf("[MAIN-DEBUG] \"test_ucharcpyK\": %d\n", res);
    printf("\n");


    res = test_intcpyK(100);
    sum += res;
    printf("[MAIN-DEBUG] \"test_intcpyK\": %d\n", res);

    res = test_shintcpyK(100);
    sum += res;
    printf("[MAIN-DEBUG] \"test_shintcpyK\": %d\n", res);

    res = test_ushintcpyK(100);
    sum += res;
    printf("[MAIN-DEBUG] \"test_ushintcpyK\": %d\n", res);

    res = test_uintcpyK(100);
    sum += res;
    printf("[MAIN-DEBUG] \"test_uintcpyK\": %d\n", res);

    res = test_lintcpyK(100);
    sum += res;
    printf("[MAIN-DEBUG] \"test_lintcpyK\": %d\n", res);

    res = test_ulintcpyK(100);
    sum += res;
    printf("[MAIN-DEBUG] \"test_ulintcpyK\": %d\n", res);

    res = test_llintcpyK(100);
    sum += res;
    printf("[MAIN-DEBUG] \"test_llintcpyK\": %d\n", res);

    res = test_ullintcpyK(100);
    sum += res;
    printf("[MAIN-DEBUG] \"test_ullintcpyK\": %d\n", res);
    printf("\n");


    res = test_floatcpyK(100);
    sum += res;
    printf("[MAIN-DEBUG] \"test_floatcpyK\": %d\n", res);
    printf("\n");


    res = test_doublecpyK(100);
    sum += res;
    printf("[MAIN-DEBUG] \"test_doublecpyK\": %d\n", res);

    res = test_ldoublecpyK(100);
    sum += res;
    printf("[MAIN-DEBUG] \"test_ldoublecpyK\": %d\n", res);


    return sum;
}





int test_charcpyK(int n) {
    for (int i=0; i<n; i++) {
        char a = rand() % 256 - 128;
        char b = rand() % 256 - 128;
        charcpyK(&a, &b, sizeof(char));
        if (a==b) {
            #if VERBOSE
            printf("charcpyK test %d passed: a->%d, b->%d\n", n, a, b);
            #endif
        } else {
            #if VERBOSE
            printf("charcpyK test %d failed: a->%d, b->%d\n", n, a, b);
            #endif
            return 1;
        }
    }

    return 0;
}
int test_scharcpyK(int n) {
    for (int i=0; i<n; i++) {
        signed char a = rand() % 256 - 128;
        signed char b = rand() % 256 - 128;
        scharcpyK(&a, &b, sizeof(signed char));
        if (a==b) {
            #if VERBOSE
            printf("scharcpyK test %d passed: a->%d, b->%d\n", n, a, b);
            #endif
        } else {
            #if VERBOSE
            printf("scharcpyK test %d failed: a->%d, b->%d\n", n, a, b);
            #endif
            return 1;
        }
    }

    return 0;
}
int test_ucharcpyK(int n) {
    for (int i=0; i<n; i++) {
        unsigned char a = rand() % 256;
        unsigned char b = rand() % 256;
        ucharcpyK(&a, &b, sizeof(unsigned char));
        if (a==b) {
            #if VERBOSE
            printf("ucharcpyK test %d passed: a->%d, b->%d\n", n, a, b);
            #endif
        } else {
            #if VERBOSE
            printf("ucharcpyK test %d failed: a->%d, b->%d\n", n, a, b);
            #endif
            return 1;
        }
    }

    return 0;
}


int test_intcpyK(int n) {
    for (int i=0; i<n; i++) {
        int a = rand() % 1000 - 500;
        int b = rand() % 1000 - 500;
        intcpyK(&a, &b, sizeof(int));
        if (a==b) {
            #if VERBOSE
            printf("intcpyK test %d passed: a->%d, b->%d\n", n, a, b);
            #endif
        } else {
            #if VERBOSE
            printf("intcpyK test %d failed: a->%d, b->%d\n", n, a, b);
            #endif
            return 1;
        }
    }

    return 0;
}
int test_shintcpyK(int n) {
    for (int i=0; i<n; i++) {
        signed int a = rand() % 1000 - 500;
        signed int b = rand() % 1000 - 500;
        shintcpyK(&a, &b, sizeof(signed int));
        if (a==b) {
            #if VERBOSE
            printf("shintcpyK test %d passed: a->%d, b->%d\n", n, a, b);
            #endif
        } else {
            #if VERBOSE
            printf("shintcpyK test %d failed: a->%d, b->%d\n", n, a, b);
            #endif
            return 1;
        }
    }

    return 0;
}
int test_ushintcpyK(int n) {
    for (int i=0; i<n; i++) {
        unsigned short int a = rand() % 1000;
        unsigned short int b = rand() % 1000;
        ushintcpyK(&a, &b, sizeof(unsigned short int));
        if (a==b) {
            #if VERBOSE
            printf("ushintcpyK test %d passed: a->%d, b->%d\n", n, a, b);
            #endif
        } else {
            #if VERBOSE
            printf("ushintcpyK test %d failed: a->%d, b->%d\n", n, a, b);
            #endif
            return 1;
        }
    }

    return 0;
}
int test_uintcpyK(int n) {
    for (int i=0; i<n; i++) {
        unsigned int a = rand() % 1000;
        unsigned int b = rand() % 1000;
        uintcpyK(&a, &b, sizeof(unsigned int));
        if (a==b) {
            #if VERBOSE
            printf("uintcpyK test %d passed: a->%d, b->%d\n", n, a, b);
            #endif
        } else {
            #if VERBOSE
            printf("uintcpyK test %d failed: a->%d, b->%d\n", n, a, b);
            #endif
            return 1;
        }
    }

    return 0;
}
int test_lintcpyK(int n) {
    for (int i=0; i<n; i++) {
        long int a = rand() % 1000 - 500;
        long int b = rand() % 1000 - 500;
        lintcpyK(&a, &b, sizeof(long int));
        if (a==b) {
            #if VERBOSE
            printf("lintcpyK test %d passed: a->%d, b->%d\n", n, a, b);
            #endif
        } else {
            #if VERBOSE
            printf("lintcpyK test %d failed: a->%d, b->%d\n", n, a, b);
            #endif
            return 1;
        }
    }

    return 0;
}
int test_ulintcpyK(int n) {
    for (int i=0; i<n; i++) {
        unsigned long int a = rand() % 1000;
        unsigned long int b = rand() % 1000;
        ulintcpyK(&a, &b, sizeof(unsigned long int));
        if (a==b) {
            #if VERBOSE
            printf("ulintcpyK test %d passed: a->%d, b->%d\n", n, a, b);
            #endif
        } else {
            #if VERBOSE
            printf("ulintcpyK test %d failed: a->%d, b->%d\n", n, a, b);
            #endif
            return 1;
        }
    }

    return 0;
}
int test_llintcpyK(int n) {
    for (int i=0; i<n; i++) {
        long long int a = rand() % 1000 - 500;
        long long int b = rand() % 1000 - 500;
        llintcpyK(&a, &b, sizeof(long long int));
        if (a==b) {
            #if VERBOSE
            printf("llintcpyK test %d passed: a->%d, b->%d\n", n, a, b);
            #endif
        } else {
            #if VERBOSE
            printf("llintcpyK test %d failed: a->%d, b->%d\n", n, a, b);
            #endif
            return 1;
        }
    }

    return 0;
}
int test_ullintcpyK(int n) {
    for (int i=0; i<n; i++) {
        unsigned long long int a = rand() % 1000;
        unsigned long long int b = rand() % 1000;
        ullintcpyK(&a, &b, sizeof(unsigned long long int));
        if (a==b) {
            #if VERBOSE
            printf("ullintcpyK test %d passed: a->%d, b->%d\n", n, a, b);
            #endif
        } else {
            #if VERBOSE
            printf("ullintcpyK test %d failed: a->%d, b->%d\n", n, a, b);
            #endif
            return 1;
        }
    }

    return 0;
}


int test_floatcpyK(int n) {
    for (int i=0; i<n; i++) {
        float a = (float)rand() / (float)RAND_MAX;
        float b = (float)rand() / (float)RAND_MAX;
        floatcpyK(&a, &b, sizeof(float));
        if (a==b) {
            #if VERBOSE
            printf("floatcpyK test %d passed: a->%f, b->%f\n", n, a, b);
            #endif
        } else {
            #if VERBOSE
            printf("floatcpyK test %d failed: a->%f, b->%f\n", n, a, b);
            #endif
            return 1;
        }
    }

    return 0;
}


int test_doublecpyK(int n) {
    for (int i=0; i<n; i++) {
        double a = (double)rand() / (double)RAND_MAX;
        double b = (double)rand() / (double)RAND_MAX;
        doublecpyK(&a, &b, sizeof(double));
        if (a==b) {
            #if VERBOSE
            printf("doublecpyK test %d passed: a->%f, b->%f\n", n, a, b);
            #endif
        } else {
            #if VERBOSE
            printf("doublecpyK test %d failed: a->%f, b->%f\n", n, a, b);
            #endif
            return 1;
        }
    }

    return 0;
}
int test_ldoublecpyK(int n) {
    for (int i=0; i<n; i++) {
        long double a = (long double)rand() / (long double)RAND_MAX;
        long double b = (long double)rand() / (long double)RAND_MAX;
        ldoublecpyK(&a, &b, sizeof(long double));
        if (a==b) {
            #if VERBOSE
            printf("ldoublecpyK test %d passed: a->%Lf, b->%Lf\n", n, a, b);
            #endif
        } else {
            #if VERBOSE
            printf("ldoublecpyK test %d failed: a->%Lf, b->%Lf\n", n, a, b);
            #endif
            return 1;
        }
    }

    return 0;
}