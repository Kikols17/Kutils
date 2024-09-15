#ifndef SORT_KUTILS_H
#define SORT_KUTILS_H

#include <stdlib.h>


// Auxiliary functions for the standard sort functions
void *quicksortK_partition(void *begin, void *end, size_t datatype_size, int (*cmp)(const void *, const void *, size_t), void (*swap)(void *, void *, size_t));
void heapsortK_heapify(void *begin, void *end, void *i, size_t datatype_size, int (*cmp)(const void *, const void *, size_t), void (*swap)(void *, void *, size_t));


/* Standard sort functions */
void bubblesortK(void *begin, void *end, size_t datatype_size, int (*cmp)(const void *, const void *, size_t), void (*swap)(void *, void *, size_t));
void insertsortK(void *begin, void *end, size_t datatype_size, int (*cmp)(const void *, const void *, size_t), void (*swap)(void *, void *, size_t));
void quicksortK(void *begin, void *end, size_t datatype_size, int (*cmp)(const void *, const void *, size_t), void (*swap)(void *, void *, size_t));
void heapsortK(void *begin, void *end, size_t datatype_size, int (*cmp)(const void *, const void *, size_t), void (*swap)(void *, void *, size_t));


/* master sortK function that can call all others */
void sortK(void *begin, void *end, size_t datatype_size, void (sort_type)(void *begin, void *end, size_t datatype_size, int (*cmp)(const void *, const void *, size_t), void (*swap)(void *, void *, size_t)), int (*cmp)(const void *, const void *, size_t), void (*swap)(void *, void *, size_t));







#endif