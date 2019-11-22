# file.h - C File util library

A simple C library with some high level functions to deal with files.

## Functions

```c
// Return the file length in characters.
long file_size(FILE* file);

// Create a new file with the specified name and returns if it was created with success.
bool file_create(char* fileName);

// Delete a file with the specified name and returns if it was deleted with success.
bool file_delete(char* fileName);

// Return if the specified file exists.
bool file_exists(char* file);

// Create a new directory with the specified name.
void file_createDirectory(char* directory);

// Get the current direcetory where the application is running.
char* file_getActiveDirectory();
```
