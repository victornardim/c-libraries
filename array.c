#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "iArray.h"

array* array_create(int dataSize) {
    array *newArray = malloc(sizeof(array));
    newArray->data = malloc(10 * dataSize);
    newArray->dataSize = dataSize;
    newArray->length = 0;
    newArray->maxLength = 10;

    return newArray;
}

void array_destroy(array* array) {
    free(array->data);
    free(array);
}

static bool expandArray(array* array) {
    void* newDataArray = realloc(array->data, array->dataSize * (array->maxLength + 10));
    if(newDataArray != NULL) {
        array->maxLength += 10;
        array->data = newDataArray;

        return true;
    }

    return false;
}

void array_push(array* array, void* data) {
    bool pushData = true;
    if(array->length >= array->maxLength) {
        pushData = expandArray(array);
    }

    if(pushData){
        memcpy(array->data + (array->length * array->dataSize), data, array->dataSize);
        array->length++;
    }
}

void* array_get(array* array, int index) {
    return array->data + (index * array->dataSize);
}

void* array_pop(array* array) {
    if(array->length == 0) return NULL;
    void* returnData = malloc(array->dataSize);
    memcpy(returnData, array->data + (--array->length * array->dataSize), array->dataSize);
    memset(array->data + (array->length * array->dataSize), 0, array->dataSize);
    return returnData;
}

size_t array_size(array* array) {
    return array->length;
}
