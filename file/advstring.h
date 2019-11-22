#include <stdio.h>
#include <stdbool.h>

#ifndef ADVSTRING_H
#define ADVSTRING_H

#define BUFFER_DEFAULT_SIZE 256

#ifdef __cplusplus
extern "C" {
#endif

    char* advstring_allocateFromBuffer(const char *buffer);
    char* advstring_allocateFromLength(size_t size);
    void advstring_destroy(char* string);
    void advstring_clear(char *string);
    bool advstring_contains(const char *source, const char *content);
    bool advstring_equals(const char *source, const char *comparation);
    bool advstring_isEmpty(const char *string);
    char* advstring_remove(char* source, const char* toRemove);
    char* advstring_replace(char* string, const char* toReplace, const char* replaceFor);
    bool advstring_isValidInteger(const char *string);
    char* advstring_toUppercase(const char* string);
    char* advstring_toLowercase(const char* string);

#ifdef __cplusplus
}
#endif

#endif /* ADVSTRING_H */

