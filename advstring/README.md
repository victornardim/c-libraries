# advstring.h - C Advanced string library
A library based on the main c string lib.  
It has some high level functions to help you deal with strings.

## Functions

```c
// Allocate memmory for your string based on a buffer string.
// Also, it will copy the content of the buffer string to your new string.
char* advstring_allocateFromBuffer(const char *buffer)

// Allocate memmory for your string based on a length.
char* advstring_allocateFromLength(size_t size)

// Destroy the string by freeing it, if it isn't freed yet.
void advstring_destroy(char* string)

// Fill all the positions of the string with zeroes.
void advstring_clear(char *string)

// Check if the string contains a substring.
bool advstring_contains(const char *source, const char *content)

// Check if a string is exactly equal another.
bool advstring_equals(const char *source, const char *comparation)

// Check if the string is empty by veryfying if it is null, the length is greater than zero and the first character isn't a null character.
bool advstring_isEmpty(const char *string)

// Remove a substring from your string, as many times as it appears.
char* advstring_remove(char* source, const char* toRemove)

// Replace a substring by another in your string, as many times as it appears.
char* advstring_replace(char* string, const char* toReplace, const char* replaceFor)

// Check if your string is a valid integer.
bool advstring_isValidInteger(const char *string)

// Turns all the lower alphabetical characters (a-z) in your string to uppercase (A-Z)
char* advstring_toUppercase(const char* string)

// Turns all the upper alphabetical characters (A-Z) in your string to lowercase (a-z)
char* advstring_toLowercase(const char* string)
```
