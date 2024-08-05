#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#include "vector_Kutils.h"



#define VERBOSE true


int test_initfree(int n, int k);
int test_copy(int n, int k);
int test_resize(int n, int k);
int test_pushpop(int k);


int main() {
    int sum = 0;
    int res;

    res = test_initfree(10000, 100);
    sum += res;
    printf("[MAIN-DEBUG] \"initfree\": %d\n", res);

    res = test_pushpop(100);
    sum += res;
    printf("[MAIN-DEBUG] \"testsetget\": %d\n", res);

    return sum;
}




int test_initfree(int n, int k) {
    vectorK *vectors[n];
    for (int i=0; i<n; i++) {
        vectors[i] = vectorK_init(sizeof(int), k, NULL);
        if (vectors[i]==NULL) {
            #if VERBOSE
            printf("[DEBUG] \"initfree\" init test#%d failed\n", i);
            #endif
            return -1;
        }
        #if VERBOSE
        printf("[DEBUG] \"initfree\" init test#%d passed\n", i);
        #endif
    }

    for (int i=0; i<n; i++) {
        vectorK_free(vectors[i]);
    }
    #if VERBOSE
    printf("[DEBUG] \"initfree\" all frees passed\n");
    #endif

    return 0;
}


int test_pushpop(int k) {
    vectorK *v = vectorK_init(sizeof(int), 1, NULL);
    if (v==NULL) {
        #if VERBOSE
        printf("[DEBUG] \"pushpop\" init failed\n");
        #endif
        return -1;
    }
    #if VERBOSE
    printf("[DEBUG] \"pushpop\" init passed, size:%ld, capacity:%ld\n", v->size, v->dinarray->capacity);
    #endif

    for (int i=0; i<k; i++) {
        int element = i;
        vectorK_pushback(v, &element);
        #if VERBOSE
        printf("[DEBUG] \"pushpop\" push#%d, size:%ld, capacity:%ld\n", i, v->size, v->dinarray->capacity);
        #endif
    }

    for (int i=0; i<k; i++) {
        int element = *(int *)vectorK_popback(v);
        if (element != k-i-1) {
            #if VERBOSE
            printf("[DEBUG] \"pushpop\" test#%d failed (%d-%d)\n", i, k-i-1, element);
            #endif
            return 1;
        }
        #if VERBOSE
        printf("[DEBUG] \"pushpop\" test#%d passed, size:%ld, capacity:%ld\n", i, v->size, v->dinarray->capacity);
        #endif
    }

    vectorK_free(v);

    return 0;
}