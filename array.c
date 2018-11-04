#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "iArray.h"

array* createArray(int dataSize) {
    array *newArray = malloc(sizeof(array));
    newArray->data = malloc(10 * dataSize);
    newArray->dataSize = dataSize;
    newArray->length = 0;
    newArray->maxLength = 10;
    
    return newArray;
}

void destroyArray(array* array) {
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

void arrayPush(array* array, void* data) {
    bool pushData = true;
    if(array->length >= array->maxLength) {
        pushData = expandArray(array);
    }
    
    if(pushData){
        array->data[array->length++] = data;
    }
}

void* arrayGet(array* array, int index) {
    return array->data[index];
}

void* arrayPop(array* array) {
    if(array->length == 0) return NULL;
    return array->data[--array->length];
}