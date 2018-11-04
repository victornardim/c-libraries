#ifndef IINTEGER_H
#define IINTEGER_H

// !! Need to use the -lm prefix to compile. !!

#ifdef __cplusplus
extern "C" {
#endif
    
int getNumberLength(int number);
int* decomposeNumber(int number);

#ifdef __cplusplus
}
#endif

#endif /* IINTEGER_H */

