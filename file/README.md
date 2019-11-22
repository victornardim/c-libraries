# file.h - C File util library

A simple C library with some high level functions to deal with files.

## Functions

<code>
// Return the file length in characters.
<b>long file_size(FILE* file)</b>

// Create a new file with the specified name and returns if it was created with success.
<b>bool file_create(char* fileName)</b>

// Delete a file with the specified name and returns if it was deleted with success.
<b>bool file_delete(char* fileName)</b>

// Return if the specified file exists.
<b>bool file_exists(char* file)</b>

// Create a new directory with the specified name.
<b>void file_createDirectory(char* directory)</b>

// Get the current direcetory where the application is running.
<b>char* file_getActiveDirectory()</b>
</code>
