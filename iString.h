#include <stdio.h>
#include <stdbool.h>

#ifndef ISTRING_H
#define ISTRING_H

#ifdef __cplusplus
extern "C" {
#endif
    
    void allocateStringFromBuffer(char **string, const char *buffer);
    void allocateStringFromLength(char **string, size_t size);
    void clearString(char *string);
    
    bool stringContains(const char *source, const char *content);
    bool stringEquals(const char *source, const char *comparation);
    bool stringIsEmpty(const char *string);
    void removeFromString(char* source, const char *toRemove);
    bool stringIsValidInteger(const char *string);
    
#ifdef __cplusplus
}
#endif

#endif /* ISTRING_H */

