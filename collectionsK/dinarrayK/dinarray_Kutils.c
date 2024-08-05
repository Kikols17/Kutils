#ifndef DINARRAY_KUTILS_C
#define DINARRAY_KUTILS_C

#include "dinarray_Kutils.h"
#include <stdlib.h>
#include <string.h>

dinarrayK *dinarrayK_init(size_t datatype_size, size_t capacity) {
    /* Create a new dinarrayK with the given datatype_size and capacity.
     *      INPUTS:
     *          -> datatype_size (size_t): size of the datatype in bytes
     *          -> capacity (size_t): initial capacity of the dinarray
     * 
     *      OUTPUT (dinarrayK *):
     *          -> NULL: memory allocation fails
     *          -> [valid pointer]: pointer to the new dinarrayK
     *
     */
    dinarrayK *new_collection = (dinarrayK *)malloc( sizeof(dinarrayK) );
    if (new_collection == NULL) {
        return NULL;
    }
    new_collection->data = (void*)malloc(datatype_size * capacity);
    if (new_collection->data == NULL) {
        free(new_collection);
        return NULL;
    }
    new_collection->datatype_size = datatype_size;
    new_collection->capacity = capacity;
    return new_collection;
}

dinarrayK *dinarrayK_copy(dinarrayK *dinarray) {
    /* Create a new dinarrayK with the same datatype_size, capacity and elements as the given dinarrayK.
     *      INPUTS:
     *          -> dinarray (dinarrayK *): pointer to the dinarrayK to be copied
     * 
     *      OUTPUT (dinarrayK *):
     *          -> NULL: memory allocation fails or copy fail
     *          -> [valid pointer]: pointer to the new dinarrayK
     *
     */
    dinarrayK *new_collection = dinarrayK_init(dinarray->datatype_size, 0);
    if (new_collection == NULL) {
        return NULL;
    }
    if ( dinarrayK_copyto(new_collection, dinarray)!=0 ) {
        dinarrayK_free(new_collection);
        return NULL;
    }
    return new_collection;
}

int dinarrayK_copyto(dinarrayK *dest, dinarrayK *src) {
    /* Copy the elements from the source dinarrayK to the destination dinarrayK.
     *      INPUTS:
     *          -> dest (dinarrayK *): pointer to the destination dinarrayK
     *          -> src (dinarrayK *): pointer to the source dinarrayK
     * 
     *      OUTPUT (int):
     *          -> -1: memory allocation fails
     *          -> 0: if copying is successful
     *          -> 1: if the datatype_size of the source and destination dinarrayK are different
     *
     */
    if (dest->datatype_size != src->datatype_size) {
        return 1;
    }

    if (dinarrayK_resize(dest, src->capacity) != 0) {
        return -1;
    }
    memcpy(dest->data, src->data, (size_t)(src->datatype_size*src->capacity) );
    return 0;
}


void dinarrayK_free(dinarrayK *dinarray) {
    /* Free the memory allocated for the dinarrayK.
     *      INPUTS:
     *          -> dinarray (dinarrayK *): pointer to the dinarrayK to be freed
     */
    free(dinarray->data);
    free(dinarray);
}



void *dinarrayK_begin(dinarrayK *dinarray) {
    /* Get the pointer to the first element in the dinarray.
     *      INPUTS:
     *          -> dinarray (dinarrayK *): pointer to the dinarrayK
     * 
     *      OUTPUT (void *):
     *          -> [valid pointer]: pointer to the first element in the dinarray
     */
    return dinarray->data;
}

void *dinarrayK_end(dinarrayK *dinarray) {
    /* Get the pointer to the last element in the dinarray.
     *      INPUTS:
     *          -> dinarray (dinarrayK *): pointer to the dinarrayK
     * 
     *      OUTPUT (void *):
     *          -> [valid pointer]: pointer to the last element in the dinarray
     */
    return dinarray->data + (dinarray->capacity * dinarray->datatype_size);
}



void *dinarrayK_get(dinarrayK *dinarray, size_t index) {
    /* Get the pointer to the element at the given index in the dinarray.
     * after you get the pointer, you can cast it to the appropriate datatype.
     *      INPUTS:
     *          -> dinarray (dinarrayK *): pointer to the dinarrayK
     *          -> index (size_t): index of the element to get
     * 
     *      OUTPUT (void *):
     *          -> NULL: if the index is out of bounds
     *          -> [valid pointer]: pointer to the element at the given index
     */
    if (index >= dinarray->capacity) {
        return NULL;
    }
    return dinarray->data + (index*dinarray->datatype_size);
}

void *dinarrayK_set(dinarrayK *dinarray, size_t index, void *element) {
    /* Set the element at the given index in the dinarray.
     *      INPUTS:
     *          -> dinarray (dinarrayK *): pointer to the dinarrayK
     *          -> index (size_t): index of the element to set
     *          -> element (void *): pointer to the element to set
     * 
     *      OUTPUT (void *):
     *          -> NULL: if the index is out of bounds
     *          -> [valid pointer]: pointer to the element at the given index
     */
    if (index >= dinarray->capacity) {
        return NULL;
    }
    void *dest = dinarray->data + (index*dinarray->datatype_size);
    memcpy(dest, element, dinarray->datatype_size);
    return dest;
}



int dinarrayK_resize(dinarrayK *dinarray, size_t new_capacity) {
    /* Resize the dinarrayK to the new capacity.
     *      INPUTS:
     *          -> dinarray (dinarrayK *): pointer to the dinarrayK
     *          -> new_capacity (size_t): new capacity of the dinarray
     * 
     *      OUTPUT (int):
     *          -> -1: memory allocation failed, dinarray->data is unchanged
     *          -> 0: if resizing is successful
     */
    void *new_data = realloc(dinarray->data, dinarray->datatype_size * new_capacity);
    if (new_data == NULL) {
        return -1;
    }
    dinarray->data = new_data;
    dinarray->capacity = new_capacity;
    return 0;
}




#endif // DINARRAY_KUTILS_C