#include "iString.h"

#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define STRING_INITIALIZATOR '\0'
#define INITIALIZATOR_SIZE 1

#define FIRST_POSITION 0

#define STRING_FILLER 0

/**
 * Allocates a string from a pre-allocated buffer string 
 * and copy the content of this buffer to it.
 * 
 * Both string will be identical: length and content.
 * 
 * Example: allocateStringFromBuffer(&string, buffer);
 * 
 * P.S.: For the first argument, the address has to be passed.
 */
void allocateStringFromBuffer(char **string, const char *buffer){
    size_t length = strlen(buffer) + INITIALIZATOR_SIZE;
    *string = (char*)calloc((length * sizeof(char)), sizeof(char));
    
    *string[FIRST_POSITION] = STRING_INITIALIZATOR;
    
    strcpy(*string, buffer);
}

/**
 * Allocates a string according to a length passed.
 * 
 * Example: allocateStringFromLength(&string, 50);
 * 
 * P.S.: For the first argument, the address has to be passed.
 */
void allocateStringFromLength(char **string, size_t length){
    length = length + INITIALIZATOR_SIZE;
    *string = (char*)calloc(length * sizeof(char), sizeof(char));
    
    *string[FIRST_POSITION] = STRING_INITIALIZATOR;
}

/**
 * Clear a string filling it with zeros.
 */
void clearString(char *string){
    size_t length = strlen(string);
    memset(string, STRING_FILLER, length);
}


/**
 * Check if a string contains a substring.
 */
bool stringContains(const char *string, const char *content){
    bool contains = false;
    
    if(strstr(string, content) != NULL){
        contains = true;
    }
    
    return contains;
}

bool stringEquals(const char *string, const char *comparation){
    bool equals = false;
    
    if(string != NULL && comparation != NULL){
        if(strcmp(string, comparation) == 0){
            equals = true;
        }
    }
    
    return equals;
}

bool stringIsEmpty(const char *string){
    bool empty = false;
    
    if(string != NULL){
        if(strlen(string) <= 0){
            empty = true;
        }else if(string[0] == '\0' || string[0] == 0){
            empty = true;
        }
    }else{
        empty = true;
    }
    
    return empty;
}

/**
 * Remove a substring from the source as many times as it have been found.
 */
void removeFromString(char* source, const char *toRemove){
    void *sourcePosition;
    size_t copyPosition;
    
    while(source = strstr(source,toRemove)){
        sourcePosition = source + strlen(toRemove);
        copyPosition = 1 + strlen(source + strlen(toRemove));
        
        memmove(source, sourcePosition, copyPosition);
    }
}

bool stringIsValidInteger(const char *string){
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

