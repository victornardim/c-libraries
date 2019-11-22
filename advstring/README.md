# advstring.h - C Advanced string library
A library based on the main c string lib.  
It has some high level functions to help you deal with strings.

## Functions

```
<pre>
// Allocate memmory for your string based on a buffer string.
// Also, it will copy the content of the buffer string to your new string.
<b>char* advstring_allocateFromBuffer(const char *buffer)</b>

// Allocate memmory for your string based on a length.
<b>char* advstring_allocateFromLength(size_t size)</b>

// Destroy the string by freeing it, if it isn't freed yet.
<b>void advstring_destroy(char* string)</b>

// Fill all the positions of the string with zeroes.
<b>void advstring_clear(char *string)</b>

// Check if the string contains a substring.
<b>bool advstring_contains(const char *source, const char *content)</b>

// Check if a string is exactly equal another.
<b>bool advstring_equals(const char *source, const char *comparation)</b>

// Check if the string is empty by veryfying if it is null, the length is greater than zero and the first character isn't a null character.
<b>bool advstring_isEmpty(const char *string)</b>

// Remove a substring from your string, as many times as it appears.
<b>char* advstring_remove(char* source, const char* toRemove)</b>

// Replace a substring by another in your string, as many times as it appears.
<b>char* advstring_replace(char* string, const char* toReplace, const char* replaceFor)</b>

// Check if your string is a valid integer.
<b>bool advstring_isValidInteger(const char *string)</b>

// Turns all the lower alphabetical characters (a-z) in your string to uppercase (A-Z)
<b>char* advstring_toUppercase(const char* string)</b>

// Turns all the upper alphabetical characters (A-Z) in your string to lowercase (a-z)
<b>char* advstring_toLowercase(const char* string)</b>
</pre>
```
