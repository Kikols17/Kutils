#ifndef STACK_KUTILS_C
#define STACK_KUTILS_C


#include "stack_Kutils.h"





stackK *stackK_init(size_t datatype_size, size_t capacity, size_t (*resize_func)(size_t, size_t)) {
    /* Create a new stackK with the given datatype_size and capacity.
     *      INPUTS:
     *          -> datatype_size (size_t): size of the datatype in bytes
     *          -> capacity (size_t): initial capacity of the collection
     *          -> resize_func (void *): pointer to the resize_func (if NULL, defresize_func is automagically set)
     * 
     *      OUTPUT (stackK *):
     *          -> NULL: memory allocation fails
     *          -> [valid pointer]: pointer to the new stackK
     *
     */
    // initialize stackK
    stackK *new_stackK = (stackK *)malloc( sizeof(stackK) );
    if (new_stackK == NULL) {
        return NULL;
    }

    // initialize stackK->vectorK
    new_stackK->vector = vectorK_init(datatype_size, capacity, resize_func);
    if (new_stackK->vector == NULL) {
        free(new_stackK);
        return NULL;
    }

    return new_stackK;
}

stackK *stackK_copy(stackK *s) {
    /* Create a new stackK with the same datatype size, capacity and elements as the given stackK.
     *      INPUTS:
     *          -> s (stackK *): pointer to the stackK to be copied
     * 
     *      OUTPUT (stackK *):
     *          -> NULL: memory allocation fails or copy fail
     *          -> [valid pointer]: pointer to the new stackK
     *
     */
    // initialize stackK
    stackK *new_stackK = stackK_init(s->vector->dinarray->datatype_size, 0, s->vector->resize_func);
    if (new_stackK == NULL) {
        return NULL;
    }

    // copy vectorK
    if (vectorK_copyto(new_stackK->vector, s->vector) == -1) {
        stackK_free(new_stackK);
        return NULL;
    }

    return new_stackK;
}

int stackK_copyto(stackK *dest, stackK *src) {
    /* Copy the elements of the source stackK to the destination stackK.
     *      INPUTS:
     *          -> dest (stackK *): pointer to the destination stackK
     *          -> src (stackK *): pointer to the source stackK
     * 
     *      OUTPUT (int):
     *          -> -1: copy fail
     *          -> 0: copy success
     *
     */
    // copy vectorK
    if (vectorK_copyto(dest->vector, src->vector) == -1) {
        return -1;
    }

    return 0;
}


void stackK_free(stackK *s) {
    /* Free the memory allocated for the stackK.
     *      INPUTS:
     *          -> s (stackK *): pointer to the stackK to be freed
     * 
     *      OUTPUT (void):
     *          -> None
     *
     */
    vectorK_free(s->vector);
    free(s);
}




void *stackK_begin(stackK *s) {
    /* Get the pointer to the first element of the stackK.
     *      INPUTS:
     *          -> s (stackK *): pointer to the stackK
     * 
     *      OUTPUT (void *):
     *          -> NULL: stackK is empty
     *          -> [valid pointer]: pointer to the first element of the stackK
     *
     */
    return vectorK_begin(s->vector);
}

void *stackK_end(stackK *s) {
    /* Get the pointer to the last element of the stackK.
     *      INPUTS:
     *          -> s (stackK *): pointer to the stackK
     * 
     *      OUTPUT (void *):
     *          -> NULL: stackK is empty
     *          -> [valid pointer]: pointer to the last element of the stackK
     *
     */
    return vectorK_end(s->vector);
}




void *stackK_push(stackK *s, void *element) {
    /* Push an element to the stackK.
     *      INPUTS:
     *          -> s (stackK *): pointer to the stackK
     *          -> element (void *): pointer to the element to be pushed
     * 
     *      OUTPUT (void *):
     *          -> NULL: memory allocation fails
     *          -> [valid pointer]: pointer to the pushed element
     *
     */
    return vectorK_pushback(s->vector, element);
}

void *stackK_pop(stackK *s) {
    /* Pop an element from the stackK.
     *      INPUTS:
     *          -> s (stackK *): pointer to the stackK
     * 
     *      OUTPUT (void *):
     *          -> NULL: stackK is empty
     *          -> [valid pointer]: pointer to the popped element
     *
     */
    return vectorK_popback(s->vector);
}

void *stackK_top(stackK *s, void *element) {
    /* Get the top element of the stackK.
     *      INPUTS:
     *          -> s (stackK *): pointer to the stackK
     *          -> element (void *): pointer to the element to be set
     * 
     *      OUTPUT (void *):
     *          -> NULL: stackK is empty
     *          -> [valid pointer]: pointer to the top element
     *
     */
    // get the pointer to the last element of the vector
    void *end = vectorK_get(s->vector, s->vector->size - 1);

    // copy to element
    if (end != NULL) {
        memcpy(element, end, s->vector->dinarray->datatype_size);
    }
    
    return end;
}





#endif // STACK_KUTILS_C