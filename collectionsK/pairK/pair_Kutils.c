#ifndef PAIR_KUTILS_C
#define PAIR_KUTILS_C

#include "pair_Kutils.h"


pairK *init_pairK(size_t first_datatype_size, size_t second_datatype_size) {
    /* Create a new pairK with the given first_datatype_size and second_datatype_size.
     *      INPUTS:
     *          -> first_datatype_size (size_t): size of the first datatype in bytes
     *          -> second_datatype_size (size_t): size of the second datatype in bytes
     * 
     *      OUTPUT (pairK *):
     *          -> NULL: memory allocation fails
     *          -> [valid pointer]: pointer to the new pairK
     *
     */
    // initialize new_pair
    pairK *new_pair = (pairK *)malloc( sizeof(pairK) );
    if (new_pair == NULL) {
        return NULL;
    }

    // allocate memory for first
    new_pair->first = (void*)malloc(first_datatype_size);
    if (new_pair->first == NULL) {
        free(new_pair);
        return NULL;
    }

    // allocate memory for second
    new_pair->second = (void*)malloc(second_datatype_size);
    if (new_pair->second == NULL) {
        free(new_pair->first);
        free(new_pair);
        return NULL;
    }

    // set datatype_size's
    new_pair->first_datatype_size = first_datatype_size;
    new_pair->second_datatype_size = second_datatype_size;

    return new_pair;
}

pairK *copy_pairK(pairK *pair) {
    /* Create a new pairK with the same first_datatype_size, second_datatype_size and elements as the given pairK.
     *      INPUTS:
     *          -> pair (pairK *): pointer to the pairK to be copied
     * 
     *      OUTPUT (pairK *):
     *          -> NULL: memory allocation fails or copy fail
     *          -> [valid pointer]: pointer to the new pairK
     *
     */
    // initialize new_pair
    pairK *new_pair = init_pairK(pair->first_datatype_size, pair->second_datatype_size);
    if (new_pair == NULL) {
        return NULL;
    }

    // copy to the new_pair
    if ( copyto_pairK(new_pair, pair)!=0 ) {
        free_pairK(new_pair);
        return NULL;
    }

    return new_pair;
}

int copyto_pairK(pairK *dest, pairK *src) {
    /* Copy the elements from the source pairK to the destination pairK.
     *      INPUTS:
     *          -> dest (pairK *): pointer to the destination pairK
     *          -> src (pairK *): pointer to the source pairK
     * 
     *      OUTPUT (int):
     *          -> 0: copy success
     *          -> 1: copy failled, datatype_size of the source and destination pairK are different
     *
     */
    // check for incompatible datatype_size's
    if (dest->first_datatype_size != src->first_datatype_size || dest->second_datatype_size != src->second_datatype_size) {
        return 1;
    }

    // copy the elements
    memcpy(dest->first, src->first, dest->first_datatype_size);
    memcpy(dest->second, src->second, dest->second_datatype_size);

    return 0;
}


void free_pairK(pairK *pair) {
    /* Free the memory allocated for the given pairK.
     *      INPUTS:
     *          -> pair (pairK *): pointer to the pairK to be freed
     * 
     */
    free(pair->first);
    free(pair->second);
    free(pair);
}



void set_pairK(pairK *pair, void *first, void *second) {
    /* Set the first and second elements of the pairK.
     *      INPUTS:
     *          -> pair (pairK *): pointer to the pairK
     *          -> first (void *): pointer to the first element
     *          -> second (void *): pointer to the second element
     * 
     *      OUTPUT (void *):
     *          -> NULL: memory allocation fails
     *          -> [valid pointer]: pointer to the pairK
     *
     */
    // set first
    memcpy(pair->first, first, pair->first_datatype_size);

    // set second
    memcpy(pair->second, second, pair->second_datatype_size);
}

void setfirst_pairK(pairK *pair, void *first) {
    /* Set the first element of the pairK.
     *      INPUTS:
     *          -> pair (pairK *): pointer to the pairK
     *          -> first (void *): pointer to the first element
     * 
     *      OUTPUT (void *):
     *          -> NULL: memory allocation fails
     *          -> [valid pointer]: pointer to the pairK
     *
     */
    // set first
    memcpy(pair->first, first, pair->first_datatype_size);
}

void setsecond_pairK(pairK *pair, void *second) {
    /* Set the second element of the pairK.
     *      INPUTS:
     *          -> pair (pairK *): pointer to the pairK
     *          -> second (void *): pointer to the second element
     * 
     *      OUTPUT (void *):
     *          -> NULL: memory allocation fails
     *          -> [valid pointer]: pointer to the pairK
     *
     */
    // set second
    memcpy(pair->second, second, pair->second_datatype_size);
}



#endif // PAIR_KUTILS_C