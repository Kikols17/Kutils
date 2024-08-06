#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#include "vector_Kutils.h"



#define VERBOSE false


int test_initfree(int n, int k);
int test_pushpop(int k);
int test_copy(int n, int k);


int main() {
    int sum = 0;
    int res;

    res = test_initfree(10000, 100);
    sum += res;
    printf("[MAIN-DEBUG] \"initfree\": %d\n", res);

    res = test_pushpop(500000000);
    sum += res;
    printf("[MAIN-DEBUG] \"pushpop\": %d\n", res);

    res = test_copy(10000, 100);
    sum += res;
    printf("[MAIN-DEBUG] \"testcopy\": %d\n", res);

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
        int element = *(int*)vectorK_popback(v);
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


int test_copy(int n, int k) {
    vectorK *vectors[n];
    vectors[0] = vectorK_init(sizeof(int), k, NULL);
    if (vectors[0]==NULL) {
        return -1;
    }
    for (int ii=0; ii<k; ii++) {
        vectorK_pushback(vectors[0], &ii);
    }

    for (int i=1; i<n; i++) {
        vectors[i] = vectorK_copy(vectors[0]);
        if (vectors[i]==NULL) {
            #if VERBOSE
            printf("[DEBUG] \"copy\" copy test#%d failed\n", i);
            #endif
            return -1;
        }
        for (int ii=0; ii<k; ii++) {
            if ( ii!=*(int*)vectorK_get(vectors[i], ii) ) {
                #if VERBOSE
                printf("[DEBUG] \"copy\" test#%d.%d failed\n", i, ii);
                #endif
                return 1;
            }
            #if VERBOSE
            printf("[DEBUG] \"copy\" test#%d.%d passed\n", i, ii);
            #endif
        }
    }

    for (int i=0; i<n; i++) {
        vectorK_free(vectors[i]);
    }

    return 0;
}