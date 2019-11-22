#ifndef FILE_H
#define FILE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stdio.h>

long file_size(FILE* file);
bool file_create(char* fileName);
bool file_delete(char* fileName);
bool file_exists(char* file);
void file_createDirectory(char* directory);
char* file_getActiveDirectory();

#ifdef __cplusplus
}
#endif

#endif /* FILE_H */


