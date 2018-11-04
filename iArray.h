#ifndef IARRAY_H
#define IARRAY_H

#ifdef __cplusplus
extern "C" {
#endif

struct array {
    void** data;
    int dataSize;
    int length;
    int maxLength;
} typedef array;
    
array* createArray(int dataSize);
void destroyArray(array* array);
void arrayPush(array* array, void* data);
void* arrayGet(array* array, int index);
void* arrayPop(array* array);

#ifdef __cplusplus
}
#endif

#endif /* IARRAY_H */

