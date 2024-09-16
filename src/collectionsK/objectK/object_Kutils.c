#ifndef OBJECT_KUTILS_C
#define OBJECT_KUTILS_C

#include "object_Kutils.h"

#include "../../datatypehandleK/cpyK/cpy_Kutils.h"


objectK *objectK_init(size_t datatype_size, void (*cpy)(void *dest, const void *src, size_t datatype_size)) {
    /* Create a new objectK with the given datatype_size.
     *      INPUTS:
     *          -> datatype_size (size_t): size of the datatype in bytes
     *          -> cpy (void (*)(void *, const void *, size_t)): copy function for the element
     * 
     *      OUTPUT (objectK *):
     *          -> NULL: memory allocation fails
     *          -> [valid pointer]: pointer to the new objectK
     *
     */
    // initialize new_object
    objectK *new_object = (objectK *)malloc( sizeof(objectK) );
    if (new_object == NULL) {
        return NULL;
    }

    // allocate memory for data
    new_object->data = (void*)malloc(datatype_size);
    if (new_object->data == NULL) {
        free(new_object);
        return NULL;
    }

    // set datatype_size
    new_object->datatype_size = datatype_size;

    // set copy function
    if (cpy == NULL) {
        new_object->cpy = bincpyK;
    } else {
        new_object->cpy = cpy;
    }

    new_object->id = -1;

    return new_object;
}

objectK *objectK_copy(objectK *object) {
    /* Create a new objectK with the same datatype_size and data as the given objectK.
     *      INPUTS:
     *          -> object (objectK *): pointer to the objectK to be copied
     * 
     *      OUTPUT (objectK *):
     *          -> NULL: memory allocation fails or copy fail
     *          -> [valid pointer]: pointer to the new objectK
     *
     */
    // initialize new_object
    objectK *new_object = objectK_init(object->datatype_size, object->cpy);
    if (new_object == NULL) {
        return NULL;
    }

    // copy to the new_object
    if ( objectK_copyto(new_object, object)!=0 ) {
        objectK_free(new_object);
        return NULL;
    }

    return new_object;
}

int objectK_copyto(objectK *dest, objectK *src) {
    /* Copy the data from the source objectK to the destination objectK.
     *      INPUTS:
     *          -> dest (objectK *): pointer to the destination objectK
     *          -> src (objectK *): pointer to the source objectK
     * 
     *      OUTPUT (int):
     *          -> 0: copy success
     *          -> 1: copy failled, datatype_size of the source and destination objectK are different
     *
     */
    // check for incompatible datatype_size's
    if (dest->datatype_size != src->datatype_size) {
        return 1;
    }

    // copy the data
    dest->cpy(dest->data, src->data, dest->datatype_size);

    return 0;
}


void objectK_free(objectK *object) {
    /* Free the memory allocated for the given objectK.
     *      INPUTS:
     *          -> object (objectK *): pointer to the objectK to be freed
     * 
     */
    free(object->data);
    free(object);
}



void objectK_set(objectK *object, void *data) {
    /* Set the data of the objectK.
     *      INPUTS:
     *          -> object (objectK *): pointer to the objectK
     *          -> data (void *): pointer to the data
     * 
     */
    object->cpy(object->data, data, object->datatype_size);
}

void objectK_get(objectK *object, void *data) {
    /* Get the data of the objectK.
     *      INPUTS:
     *          -> object (objectK *): pointer to the objectK
     *          -> data (void *): pointer to the data
     * 
     */
    object->cpy(data, object->data, object->datatype_size);
}



#endif // OBJECT_KUTILS_C