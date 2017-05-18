#include <stdio.h>
#include <stdbool.h>

#ifndef ISTRING_H
#define ISTRING_H

#ifdef __cplusplus
extern "C" {
#endif
    
    void allocateStringFromBuffer(char **string, char *buffer);
    void allocateStringFromLength(char **string, size_t size);
    void clearString(char *string);
    
    bool stringContains(char *source, char *content);
    bool stringEquals(char *source, char *comparation);
    bool stringIsEmpty(char *string);
    void removeFromString(char* source, const char *toRemove);
    bool stringIsValidInteger(char *string);
    
#ifdef __cplusplus
}
#endif

#endif /* ISTRING_H */

