#ifndef INTEGER_H
#define INTEGER_H

// !! Need to use the -lm prefix to compile. !!

#ifdef __cplusplus
extern "C" {
#endif

int integer_getNumberLength(int number);
int* integer_decomposeNumber(int number);
int integer_getRandom(int min, int max);
int integer_convertFromString(char* string);

#ifdef __cplusplus
}
#endif

#endif /* INTEGER_H */

