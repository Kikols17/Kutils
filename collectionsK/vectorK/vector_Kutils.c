#ifndef VECTOR_KUTILS_C
#define VECTOR_KUTILS_C

#include "vector_Kutils.h"
#include "../dinarrayK/dinarray_Kutils.h"

#include <stdio.h>
#include <stdlib.h>


vectorK *vectorK_init(size_t datatype_size, size_t capacity, int (*resize_func)(int, int)) {
    /* Create a new vectorK with the given datatype_size and capacity.
     *      INPUTS:
     *          -> datatype_size (size_t): size of the datatype in bytes
     *          -> capacity (size_t): initial capacity of the collection
     *          -> resize_func (void *): pointer to the resize_func (if NULL, defresize_func is automagically set)
     * 
     *      OUTPUT (vectorK *):
     *          -> NULL: memory allocation fails
     *          -> [valid pointer]: pointer to the new vectorK
     *
     */
    // initialize vectorK
    vectorK *new_vectorK = (vectorK *)malloc( sizeof(vectorK) );
    if (new_vectorK == NULL) {
        return NULL;
    }

    // initialize vectorK->dinarrayK
    new_vectorK->dinarray = dinarrayK_init(datatype_size, capacity);
    if (new_vectorK->dinarray == NULL) {
        free(new_vectorK);
        return NULL;
    }

    // initialize vectorK->size
    new_vectorK->size = 0;

    // initialize vectorK->resize_func
    if (resize_func==NULL) {
        new_vectorK->resize_func = vectorK_defresize;
    } else {
        new_vectorK->resize_func = resize_func;
    }

    return new_vectorK;
}

vectorK *vectorK_copy(vectorK *v) {
    /* Create a new vectorK with the same datatype size, capacity and elements as the given vectorK.
     *      INPUTS:
     *          -> v (vectorK *): pointer to the vectorK to be copied
     * 
     *      OUTPUT (vectorK *):
     *          -> NULL: memory allocation fails or copy fail
     *          -> [valid pointer]: pointer to the new vectorK
     *
     */
    // initialize vectorK
    vectorK *new_vectorK = vectorK_init(v->dinarray->datatype_size, 0, v->resize_func);
    if (new_vectorK == NULL) {
        return NULL;
    }

    // copy v to new_vectorK
    if ( dinarrayK_copyto(new_vectorK->dinarray, v->dinarray)!=0 ) {
        vectorK_free(new_vectorK);
        return NULL;
    }

    return new_vectorK;
}

int vectorK_copyto(vectorK *dest, vectorK *src) {
    /* Copy the elements from the source vectorK to the destination vectorK.
     *      INPUTS:
     *          -> dest (vectorK *): pointer to the destination vectorK
     *          -> src (vectorK *): pointer to the source vectorK
     * 
     *      OUTPUT (int):
     *          -> -1: memory allocation fails
     *          -> 0: copy successful
     *          -> 1: datatype size mismatch
     *
     */
    // check for incompatibility on the datatype_size
    if (dest->dinarray->datatype_size != src->dinarray->datatype_size) {
        return 1;
    }

    // copy src->dinarray to dest->dinarray
    if ( dinarrayK_copyto(dest->dinarray, src->dinarray)!=0 ) {
        return -1;
    }

    // copy rest of atributes
    dest->size = src->size;
    dest->resize_func = src->resize_func;

    return 0;
}


void vectorK_free(vectorK *v) {
    /* Free the memory allocated for the given vectorK.
     *      INPUTS:
     *          -> v (vectorK *): pointer to the vectorK to be freed
     * 
     *      OUTPUT (void):
     *          -> None
     *
     */
    dinarrayK_free(v->dinarray);
    free(v);
}



void *vectorK_begin(vectorK *v) {
    /* Get the pointer to the first element of the vectorK, that coincides with the first element of vectorK->dinarray.
     *      INPUTS:
     *          -> v (vectorK *): pointer to the vectorK
     * 
     *      OUTPUT (void *):
     *          -> [valid pointer]: pointer to the first element of the vectorK
     *
     */
    return dinarrayK_begin(v->dinarray);
}

void *vectorK_end(vectorK *v) {
    /* Get the pointer to the last element of the vectorK, that does not necessarily coincide with the last element of vectorK->dinarray.
     *      INPUTS:
     *          -> v (vectorK *): pointer to the vectorK
     * 
     *      OUTPUT (void *):
     *          -> [valid pointer]: pointer to the last element of the vectorK
     *
     */
    return v->dinarray->data + (v->size * v->dinarray->datatype_size);
}



void *vectorK_get(vectorK *v, size_t index) {
    /* Get the pointer to the element at the given index in the vectorK.
     *      INPUTS:
     *          -> v (vectorK *): pointer to the vectorK
     *          -> index (size_t): index of the element to be accessed
     * 
     *      OUTPUT (void *):
     *          -> [valid pointer]: pointer to the element at the given index
     *
     */
    return dinarrayK_get(v->dinarray, index);
}

void *vectorK_set(vectorK *v, size_t index, void *element) {
    /* Set the element at the given index in the vectorK.
     *      INPUTS:
     *          -> v (vectorK *): pointer to the vectorK
     *          -> index (size_t): index of the element to be set
     *          -> element (void *): pointer to the element to be set
     * 
     *      OUTPUT (void *):
     *          -> [valid pointer]: pointer to the element at the given index
     *
     */
    return dinarrayK_set(v->dinarray, index, element);
}



void *vectorK_pushback(vectorK *v, void *element) {
    /* Pushed back the element to the given vectorK.
     * If necessary, increases the capacity of the dinamic array, following the "resize_func" function.
     *      INPUTS:
     *          -> v (vectorK *): pointer to the vectorK
     *          -> element (void *): pointer to the element to be set
     * 
     *      OUTPUT (void *):
     *          -> NULL: failed to pushback element (most likely error in the realloc resizing of the dinarray)
     *          -> [valid pointer]: pointer to the element just added
     * 
     */

    // calculate the new capacity
    int new_capacity = v->resize_func(v->size+1, v->dinarray->capacity);
    if (new_capacity<0) {
        return NULL;
    }

    // resize the dinarray if necessary
    if (new_capacity != v->dinarray->capacity) {
        if ( dinarrayK_resize(v->dinarray, new_capacity)!=0 ) {
            return NULL;
        }
        v->dinarray->capacity = new_capacity;
    }

    // push the element
    void *dest = dinarrayK_set(v->dinarray, v->size, element);
    v->size++;
    
    return dest;
}

void *vectorK_popback(vectorK *v) {
    /* Pops back the given vectorK, returning a pointer to the newly poped element.
     * If necessary, decrease the capacity of the dinamic array, following the "resize_func" function.
     * [ATENTION]: after the element is poped back theres no garantee that the value at the returned pointer will not be altered.
     * For speed purposes, the element is not copied to the "element" pointer, so you'll want to copy it beforehand if you want to keep it.
     *      INPUTS:
     *          -> v (vectorK *): pointer to the vectorK
     *      
     *      OUTPUT:
     *          -> NULL: failed to popback element (most likely, dinarray was already empty, or error in the realloc resizing of the dinarray)
     */

    // calculate the new capacity
    int new_capacity = v->resize_func(v->size-1, v->dinarray->capacity);
    if ( new_capacity<0 ) {
        return NULL;
    }

    // pop the element, and copy it to the "element" pointer
    void *dest = dinarrayK_get(v->dinarray, v->size-1);
    v->size--;

    // resize the dinarray if necessary
    if (new_capacity != v->dinarray->capacity) {
        if ( dinarrayK_resize(v->dinarray, new_capacity)!=0 ) {
            return NULL;
        }
        v->dinarray->capacity = new_capacity;
    }

    return dest;
}





int vectorK_defresize(int new_size, int cur_capacity) {
    /* Default funtion for resizing the vector.
     * 
     * 
     * [IMPORTANT][ALL OTHER IMPLEMENTATIONS OF THIS FUNCTION SHOULD FOLLOW THIS INPUTS/OUTPUT RULES]
     *      INPUTS:
     *          -> new_size (int): value of the new_size that the dinarray will have after the current operation (+1 if push_back, -1 if pop_back)
     *          -> cur_capacity (int): value of the current capacity of the dinarray
     * 
     *      OUTPUT:
     *          -> -1: impossible new_size/capacity setup
     *          -> n, n>-1: new capacity that the dinarrayK should have
     */
    
    // if the values are invalid, return -1
    if (new_size<0 || cur_capacity<=0 || new_size-1>cur_capacity) {
        return -1;
    }

    // if the new_size does not fit inside the cur_capacity, double it
    if (new_size>cur_capacity) {
        return cur_capacity*2;
    }

    // if the new_size if 1/4 of the cur_capacity, half it.
    // (This is done so that we are not always doubling and then halfing the capacity, when pushing and popping)
    if (new_size*4<cur_capacity) {
        return cur_capacity/2;
    }

    return cur_capacity;
}

int vectorK_tightresize(int new_size, int cur_capacity) {
    /* Tight funtion for resizing the vector.
     *
     *
     * [IMPORTANT][ALL OTHER IMPLEMENTATIONS OF THIS FUNCTION SHOULD FOLLOW THIS INPUTS/OUTPUT RULES]
     *      INPUTS:
     *          -> new_size (int): value of the new_size that the dinarray will have after the current operation (+1 if push_back, -1 if pop_back)
     *          -> cur_capacity (int): value of the current capacity of the dinarray
     *
     *      OUTPUT:
     *          -> -1: impossible new_size/capacity setup
     *          -> n, n>-1: new capacity that the dinarrayK should have
     */
    
    // if the values are invalid, return -1
    if (new_size<0 || cur_capacity<=0 || new_size-1>cur_capacity) {
        return -1;
    }

    // make sure that the new_capacity is never smaller than 1
    if (new_size==0) {
        return 1;
    }

    // make sure that the new_capacity is always the same as the new_size (except if the new_size is 0, then it should be 1)
    return new_size;
}



#endif // VECTOR_KUTILS_C