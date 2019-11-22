#include "advstring.h"

#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define NULL_CHARACTER '\0'
#define INITIALIZATOR_SIZE 1

#define FIRST_POSITION 0

#define STRING_FILLER 0

#define FIRST_UPPERCASE_LETTER 65
#define LAST_UPPERCASE_LETTER 90
#define FIRST_LOWERCASE_LETTER 97
#define LAST_LOWERCASE_LETTER 122
#define LOWERCASE_TO_UPPERCASE_DIFFERENCE 32

char* advstring_allocateFromBuffer(const char* buffer){
    size_t length = strlen(buffer) + INITIALIZATOR_SIZE;
    char* string = (char*)calloc((length * sizeof(char)), sizeof(char));

    strcpy(string, buffer);

    return string;
}

char* advstring_allocateFromLength(size_t length){
    length = length + INITIALIZATOR_SIZE;
    char* string = (char*)calloc(length * sizeof(char), sizeof(char));

    string[FIRST_POSITION] = NULL_CHARACTER;

    return string;
}

void advstring_destroy(char* string) {
    if(string != NULL)
        free(string);
}

void advstring_clear(char *string){
    size_t length = strlen(string);
    memset(string, STRING_FILLER, length);
}

bool advstring_contains(const char *string, const char *content){
    bool contains = false;

    if(strstr(string, content) != NULL){
        contains = true;
    }

    return contains;
}

bool advstring_equals(const char *string, const char *comparation){
    bool equals = false;

    if(string != NULL && comparation != NULL){
        if(strcmp(string, comparation) == 0){
            equals = true;
        }
    }

    return equals;
}

bool advstring_isEmpty(const char *string){
    return !((string != NULL) && (strlen(string) > 0) && (string[0] != NULL_CHARACTER));
}

char* advstring_remove(char* source, const char *toRemove){
    return advstring_replace(source, toRemove, "");
}

char* advstring_replace(char* source, const char* toReplace, const char* replaceFor) {
    char* sourceCopy = advstring_allocateFromBuffer(source);
    char* replacedString = advstring_allocateFromLength(500);
    char* occurrence = NULL;

    void *destinationPosition;

    size_t moveLength;

    while((occurrence = strstr(sourceCopy, toReplace))) {
        strncat(replacedString, sourceCopy, occurrence - sourceCopy);
        strncat(replacedString, replaceFor, strlen(replaceFor));

        destinationPosition = occurrence + strlen(toReplace);

        moveLength = 1 + strlen(occurrence + strlen(toReplace));

        memmove(sourceCopy, destinationPosition, moveLength);
    }

    if(strlen(sourceCopy) > 0) {
        strncat(replacedString, sourceCopy, occurrence - sourceCopy);
    }

    advstring_destroy(sourceCopy);

    return replacedString;
}

bool advstring_isValidInteger(const char *string){
    bool integer = true;

    size_t length = strlen(string);

    int i = 0;
    for(i = 0; i < length; i++){
        if(!isdigit(string[i])){
            integer = false;

            break;
        }
    }

    return integer;
}

char* advstring_toUppercase(const char* string) {
    size_t length = strlen(string);

    char* uppedString = advstring_allocateFromLength(length);

    int i = 0;
    for (i = 0; i < length; i++) {
        if (string[i] >= FIRST_LOWERCASE_LETTER && string[i] <= LAST_LOWERCASE_LETTER) {
            uppedString[i] = string[i] - LOWERCASE_TO_UPPERCASE_DIFFERENCE;
        } else {
            uppedString[i] = string[i];
        }
    }

    uppedString[length] = '\0';

    return uppedString;
}

char* advstring_toLowercase(const char* string) {
    size_t length = strlen(string);

    char* loweredString = advstring_allocateFromLength(length);

    int i = 0;
    for (i = 0; i < length; i++) {
        if (string[i] >= FIRST_UPPERCASE_LETTER && string[i] <= LAST_UPPERCASE_LETTER) {
            loweredString[i] = string[i] + LOWERCASE_TO_UPPERCASE_DIFFERENCE;
        } else {
            loweredString[i] = string[i];
        }
    }

    loweredString[length] = '\0';

    return loweredString;
}
