#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "iInteger.h"

int integer_getNumberLength(int number) {
    return floor(log10(number)) + 1;
}

int* integer_decomposeNumber(int number) {
    int numberLength = integer_getNumberLength(number);
    int* array = (int*)malloc(numberLength * sizeof(int));
    int i = numberLength;
    do {
        array[--i] = number % 10;
    } while(number /= 10);

    return array;
}

int integer_getRandom(int min, int max) {
    srand(clock());
    return (min + rand() / (RAND_MAX / (max - min + 1) + 1));
}
