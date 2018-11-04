#include <stdlib.h>
#include <math.h>

#include "iInteger.h"

int getNumberLength(int number) {
    return floor(log10(number)) + 1;
}

int* decomposeNumber(int number) {
    int numberLength = getNumberLength(number);
    int* array = (int*)malloc(numberLength * sizeof(int));
    int i = numberLength;
    do {
        array[--i] = number % 10;
    } while(number /= 10);
    
    return array;
}