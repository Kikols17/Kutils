#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#include "dinarray_Kutils.h"



#define VERBOSE false


int test_initfree(int n, int k);
int test_setget(int n, int k);
int test_copy(int n, int k);
int test_resize(int n, int k);


// test all functions
int main() {
    int sum = 0;
    int res;
    
    res = test_initfree(10000, 100);
    sum += res;
    printf("[MAIN-DEBUG] \"initfree\": %d\n", res);
    
    res = test_setget(10000, 100);
    sum += res;
    printf("[MAIN-DEBUG] \"testsetget\": %d\n", res);

    res = test_copy(10000, 100);
    sum += res;
    printf("[MAIN-DEBUG] \"testcopy\": %d\n", res);

    res = test_resize(10000, 100);
    sum += res;
    printf("[MAIN-DEBUG] \"testresize\": %d\n", res);
    /*
    // test dinarrayK_init
    dinarrayK *dinarray = dinarrayK_init(sizeof(int), 10);
    if (dinarray == NULL) {
        return 1;
    }
    dinarrayK_free(dinarray);
    printf("dinarrayK_init (and dinarrayK_free) passed\n");


    // test dinarrayK_copy
    dinarray = dinarrayK_init(sizeof(int), 10);
    if (dinarray == NULL) {
        return 1;
    }
    dinarrayK *new_collection = dinarrayK_copy(dinarray);
    if (new_collection == NULL) {
        dinarrayK_free(dinarray);
        return 1;
    }
    dinarrayK_free(dinarray);
    dinarrayK_free(new_collection);
    printf("dinarrayK_copy passed\n");


    // test dinarrayK_copyto
    dinarray = dinarrayK_init(sizeof(int), 10);
    if (dinarray == NULL) {
        return 1;
    }
    new_collection = dinarrayK_init(sizeof(int), 10);
    if (new_collection == NULL) {
        dinarrayK_free(dinarray);
        return 1;
    }
    if (dinarrayK_copyto(new_collection, dinarray) != 0) {
        dinarrayK_free(dinarray);
        dinarrayK_free(new_collection);
        return 1;
    }
    dinarrayK_free(dinarray);
    dinarrayK_free(new_collection);
    printf("dinarrayK_copyto passed\n");

    */

    return sum;
}



int test_initfree(int n, int k) {
    dinarrayK *dinarray[n];
    for (int i=0; i<n; i++) {
        dinarray[i] = dinarrayK_init(sizeof(int), k);
        if (dinarray[i]==NULL) {
            #if VERBOSE
            printf("[DEBUG] \"initfree\" init test#%lld failed\n", i);
            #endif
            return -1;
        }
        #if VERBOSE
        printf("[DEBUG] \"initfree\" init test#%lld passed\n", i);
        #endif
    }

    for (int i=0; i<n; i++) {
        dinarrayK_free(dinarray[i]);
    }
    #if VERBOSE
    printf("[DEBUG] \"initfree\" all frees passed\n");
    #endif

    return 0;
}


int test_setget(int n, int k) {
    dinarrayK *dinarray[n];
    int res = 0;
    for (int i=0; i<n; i++) {
        dinarray[i] = dinarrayK_init(sizeof(int), k);
        for (int ii=0; ii<k; ii++) {
            dinarrayK_set(dinarray[i], ii, &ii);
            if ( ii!=*(int*)dinarrayK_get(dinarray[i], ii) ) {
                res++;
                #if VERBOSE
                printf("[DEBUG] \"setget\" test#%d.%d failed", i, ii);
                #endif
            }
            //printf("%d, %d\n", ii, *(int*)dinarrayK_get(dinarray[i], ii));
        }
    }

    return res;
}


int test_copy(int n, int k) {
    dinarrayK *dinarray[n];
    dinarray[0] = dinarrayK_init(sizeof(int), k);
    if (dinarray[0]==NULL) {
        return -1;
    }
    for (int ii=0; ii<k; ii++) {
        dinarrayK_set(dinarray[0], ii, &ii);
    }

    for (int i=1; i<n; i++) {
        dinarray[i] = dinarrayK_copy(dinarray[i-1]);
        if (dinarray[i]==NULL) {
            return -1;
        }
    }

    bool mismatch = false;
    for (int i=1; i<n; i++) {
        bool local_mismatch = false;
        for (int ii=0; ii<k; ii++) {
            //printf("%d: %d\n", ii, *(int*)dinarrayK_get(dinarray[i], ii));
            if ( *(int*)dinarrayK_get(dinarray[i-1], ii) != *(int*)dinarrayK_get(dinarray[i], ii) ) {
                local_mismatch = true;
                mismatch = true;
            }

            if ( dinarrayK_get(dinarray[i-1], ii) == dinarrayK_get(dinarray[i], ii) ) {
                local_mismatch = true;
                mismatch = true;
            }
        }
        dinarrayK_free(dinarray[i-1]);

        #if VERBOSE
        if (local_mismatch) {
            printf("[DEBUG] \"copy\" match test#(%d->%d) failed\n", i-1, i);
        } else {
            printf("[DEBUG] \"copy\" match test#(%d->%d) passed\n", i-1, i);
        }
        #endif
    }
    dinarrayK_free(dinarray[n-1]);

    return (int)mismatch;
}



int test_resize(int n, int k) {
    bool fail = false;
    dinarrayK *dinarray[n];
    for (int i=0; i<n; i++) {
        dinarray[i] = dinarrayK_init(sizeof(int), 1);
        for (int ii=2; ii<=k; ii++) {
            if ( dinarrayK_resize(dinarray[i], ii)!=0 ) {
                #if VERBOSE
                printf("[DEBUG] \"resize\" test#%d cur_cap%d memory failed\n", i, ii);
                #endif
                fail = true;
            } else {
                #if VERBOSE
                printf("[DEBUG] \"resize\" test#%d cur_cap%d memory passed\n", i, ii); 
                #endif
            }
        }
        if (dinarray[i]->capacity!=k) {
            #if VERBOSE
            printf("[DEBUG] \"resize\" test#%d capacity failed\n", i);
            #endif
            fail = true;
        } else {
            #if VERBOSE
            printf("[DEBUG] \"resize\" test#%d capacity passed\n", i);
            #endif
        }
    }

    for (int i=0; i<n; i++) {
        dinarrayK_free(dinarray[i]);
    }

    return (int)fail;
}