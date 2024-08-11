#ifndef SORT_KUTILS_C
#define SORT_KUTILS_C

#include <string.h>

#include "sort_Kutils.h"
#include "../../datatypehandleK/cmpK/cmp_Kutils.h"
#include "../../datatypehandleK/swapK/swap_Kutils.h"


// Auxiliary functions for the Standard sort functions
void *quicksortK_partition(void *begin, void *end, size_t datatype_size, int (*cmp)(const void *, const void *, size_t), void (*swap)(void *, void *, size_t)) {
    /* Partitions an array for the quicksort algorithm
     *
     *      INPUTS:
     *          begin: pointer to the first element of the array
     *          end: pointer to the last element of the array
     *          datatype_size: size of the elements in the array
     *          cmp: pointer to the comparison function
     *          swap: pointer to the swap function
     *          swapped: pointer to the number of swaps made
     *
     *      OUTPUT:
     *          pointer to the pivot element
     *
    */
    void *pivot = end-datatype_size;
    void *i = begin-datatype_size;

    for (void *j=begin; j<end-datatype_size; j+=datatype_size) {
        if ( cmp(j, pivot, datatype_size)==1 ) {
            i += datatype_size;
            swap(i, j, datatype_size);
        }
    }

    i += datatype_size;
    swap(i, end-datatype_size, datatype_size);

    return i;
}

void heapsortK_heapify(void *begin, void *end, void *i, size_t datatype_size, int (*cmp)(const void *, const void *, size_t), void (*swap)(void *, void *, size_t)) {
    /* Heapifies an array for the heapsort algorithm
     *
     *      INPUTS:
     *          begin (void *): pointer to the first element of the array
     *          end (void *): pointer to the last element of the array
     *          i (void *): pointer to the current element
     *          datatype_size (size_t): size of the elements in the array
     *          cmp: pointer to the comparison function
     *          swap: pointer to the swap function
     *
     */
    void *largest = i;
    void *left = begin + 2*(i-begin) + datatype_size;
    void *right = begin + 2*(i-begin) + 2*datatype_size;

    if ( (left<end) && (cmp(left, largest, datatype_size)>0) ) {
        largest = left;
    }

    if ( (right<end) && (cmp(right, largest, datatype_size)>0) ) {
        largest = right;
    }

    if (largest != i) {
        swap(i, largest, datatype_size);
        heapsortK_heapify(begin, end, largest, datatype_size, cmp, swap);
    }

}




/* Standard sort functions */
void bubblesortK(void *begin, void *end, size_t datatype_size, int (*cmp)(const void *, const void *, size_t), void (*swap)(void *, void *, size_t)) {
    /* Sorts an array using the bubble sort algorithm
     *
     *  Time complexity: best O(n), average O(n^2), worst O(n^2)
     *  Space complexity: O(1)
     *
     *      INPUTS:
     *          begin: pointer to the first element of the array
     *          end: pointer to the last element of the array
     *          datatype_size: size of the elements in the array
     *          cmp: pointer to the comparison function
     *          swap: pointer to the swap function
     *
     */
    for (void *i=begin; i<end; i+=datatype_size) {
        for (void *j=begin; j<end-datatype_size; j+=datatype_size) {
            if (cmp(j, j + datatype_size, datatype_size) > 0) {
                swap(j, j + datatype_size, datatype_size);
            }
        }
    }

}

void insertsortK(void *begin, void *end, size_t datatype_size, int (*cmp)(const void *, const void *, size_t), void (*swap)(void *, void *, size_t)) {
    /* Sorts an array using the insertion sort algorithm
     *
     *  Time complexity: best O(n), average O(n^2), worst O(n^2)
     *  Space complexity: O(1)
     * 
     *      INPUTS:
     *          begin: pointer to the first element of the array
     *          end: pointer to the last element of the array
     *          datatype_size: size of the elements in the array
     *          cmp: pointer to the comparison function
     *          swap: pointer to the swap function
     *
     */
    void *j;
    char key[datatype_size];

    for (void *i=begin+datatype_size; i<end; i+=datatype_size) {
        memcpy(&key, i, datatype_size);
        j = i-datatype_size;

        while ( (j>=begin) && (cmp(j, &key, datatype_size)==1) ) {
            memcpy(j+datatype_size, j, datatype_size);
            j -= datatype_size;
        }
        
        memcpy(j+datatype_size, &key, datatype_size);
    }
}

void quicksortK(void *begin, void *end, size_t datatype_size, int (*cmp)(const void *, const void *, size_t), void (*swap)(void *, void *, size_t)) {
    /* Sorts an array using the quick sort algorithm
     *
     *  Time complexity: best O(n log n), average O(n log n), worst O(n^2)
     *  Space complexity: best O(log n), average O(log n), worst O(n)
     * 
     *      INPUTS:
     *          begin: pointer to the first element of the array
     *          end: pointer to the last element of the array
     *          datatype_size: size of the elements in the array
     *          cmp: pointer to the comparison function
     *          swap: pointer to the swap function
     *
     */
    if (begin < end) {
        void *pivot = quicksortK_partition(begin, end, datatype_size, cmp, swap);
        quicksortK(begin, pivot, datatype_size, cmp, swap);
        quicksortK(pivot+datatype_size, end, datatype_size, cmp, swap);
    }
}

void heapsortK(void *begin, void *end, size_t datatype_size, int (*cmp)(const void *, const void *, size_t), void (*swap)(void *, void *, size_t)) {
    /* Sorts an array using the heap sort algorithm
     *
     *  Time complexity: best O(n log n), average O(n log n), worst O(n log n)
     *  Space complexity: O(1)
     * 
     *      INPUTS:
     *          begin: pointer to the first element of the array
     *          end: pointer to the last element of the array
     *          datatype_size: size of the elements in the array
     *          cmp: pointer to the comparison function
     *          swap: pointer to the swap function
     *
     */
    for (void *i=end; i>=begin; i-=datatype_size) {
        heapsortK_heapify(begin, end, i, datatype_size, cmp, swap);
    }

    for (void *i=end; i>begin; i-=datatype_size) {
        swap(begin, i, datatype_size);
        heapsortK_heapify(begin, i, begin, datatype_size, cmp, swap);
    }

}





/* master sortK function that can call all others */
void sortK(void *begin, void *end, size_t datatype_size, void (sort_type)(void *begin, void *end, size_t datatype_size, int (*cmp)(const void *, const void *, size_t), void (*swap)(void *, void *, size_t)), int (*cmp)(const void *, const void *, size_t), void (*swap)(void *, void *, size_t)) {
    /* Sorts an array using the specified sort, cmp and swap functions.
     * If no functions are provided (NULL), de defaults are: sort->heapsortK, cmp->bincmpK, swap->binswapK
     *
     *      INPUTS:
     *          begin: pointer to the first element of the array
     *          end: pointer to the last element of the array
     *          datatype_size: size of the elements in the array
     *          sort_type: pointer to the sort function
     *          cmp: pointer to the comparison function
     *          swap: pointer to the swap function
     *
     */

    if (sort_type==NULL) {
        sort_type = heapsortK;
    }
    if (cmp==NULL) {
        cmp = bincmpK;
    }
    if (swap==NULL) {
        swap = binswapK;
    }
    
    sort_type(begin, end, datatype_size, cmp, swap);
}



#endif // SORT_KUTILS_C