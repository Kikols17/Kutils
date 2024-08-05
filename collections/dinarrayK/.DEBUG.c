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
    // test init_dinarrayK
    dinarrayK *dinarray = init_dinarrayK(sizeof(int), 10);
    if (dinarray == NULL) {
        return 1;
    }
    free_dinarrayK(dinarray);
    printf("init_dinarrayK (and free_dinarrayK) passed\n");


    // test copy_dinarrayK
    dinarray = init_dinarrayK(sizeof(int), 10);
    if (dinarray == NULL) {
        return 1;
    }
    dinarrayK *new_collection = copy_dinarrayK(dinarray);
    if (new_collection == NULL) {
        free_dinarrayK(dinarray);
        return 1;
    }
    free_dinarrayK(dinarray);
    free_dinarrayK(new_collection);
    printf("copy_dinarrayK passed\n");


    // test copyto_dinarrayK
    dinarray = init_dinarrayK(sizeof(int), 10);
    if (dinarray == NULL) {
        return 1;
    }
    new_collection = init_dinarrayK(sizeof(int), 10);
    if (new_collection == NULL) {
        free_dinarrayK(dinarray);
        return 1;
    }
    if (copyto_dinarrayK(new_collection, dinarray) != 0) {
        free_dinarrayK(dinarray);
        free_dinarrayK(new_collection);
        return 1;
    }
    free_dinarrayK(dinarray);
    free_dinarrayK(new_collection);
    printf("copyto_dinarrayK passed\n");

    */

    return sum;
}



int test_initfree(int n, int k) {
    dinarrayK *dinarray[n];
    for (int i=0; i<n; i++) {
        dinarray[i] = init_dinarrayK(sizeof(int), k);
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
        free_dinarrayK(dinarray[i]);
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
        dinarray[i] = init_dinarrayK(sizeof(int), k);
        for (int ii=0; ii<k; ii++) {
            set_dinarrayK(dinarray[i], ii, &ii);
            if ( ii!=*(int*)get_dinarrayK(dinarray[i], ii) ) {
                res++;
                #if VERBOSE
                printf("[DEBUG] \"setget\" test#%d.%d failed", i, ii);
                #endif
            }
            //printf("%d, %d\n", ii, *(int*)get_dinarrayK(dinarray[i], ii));
        }
    }

    return res;
}


int test_copy(int n, int k) {
    dinarrayK *dinarray[n];
    dinarray[0] = init_dinarrayK(sizeof(int), k);
    if (dinarray[0]==NULL) {
        return -1;
    }
    for (int ii=0; ii<k; ii++) {
        set_dinarrayK(dinarray[0], ii, &ii);
    }

    for (int i=1; i<n; i++) {
        dinarray[i] = copy_dinarrayK(dinarray[i-1]);
        if (dinarray[i]==NULL) {
            return -1;
        }
    }

    bool mismatch = false;
    for (int i=1; i<n; i++) {
        bool local_mismatch = false;
        for (int ii=0; ii<k; ii++) {
            //printf("%d: %d\n", ii, *(int*)get_dinarrayK(dinarray[i], ii));
            if ( *(int*)get_dinarrayK(dinarray[i-1], ii) != *(int*)get_dinarrayK(dinarray[i], ii) ) {
                local_mismatch = true;
                mismatch = true;
            }

            if ( get_dinarrayK(dinarray[i-1], ii) == get_dinarrayK(dinarray[i], ii) ) {
                local_mismatch = true;
                mismatch = true;
            }
        }
        free_dinarrayK(dinarray[i-1]);

        #if VERBOSE
        if (local_mismatch) {
            printf("[DEBUG] \"copy\" match test#(%d->%d) failed\n", i-1, i);
        } else {
            printf("[DEBUG] \"copy\" match test#(%d->%d) passed\n", i-1, i);
        }
        #endif
    }
    free_dinarrayK(dinarray[n-1]);

    return (int)mismatch;
}



int test_resize(int n, int k) {
    bool fail = false;
    dinarrayK *dinarray[n];
    for (int i=0; i<n; i++) {
        dinarray[i] = init_dinarrayK(sizeof(int), 1);
        for (int ii=2; ii<=k; ii++) {
            if ( resize_dinarrayK(dinarray[i], ii)!=0 ) {
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
        free_dinarrayK(dinarray[i]);
    }

    return (int)fail;
}