#ifndef IINTEGER_H
#define IINTEGER_H

// !! Need to use the -lm prefix to compile. !!

#ifdef __cplusplus
extern "C" {
#endif

int integer_getNumberLength(int number);
int* integer_decomposeNumber(int number);
int integer_getRandom(int min, int max);

#ifdef __cplusplus
}
#endif

#endif /* IINTEGER_H */

