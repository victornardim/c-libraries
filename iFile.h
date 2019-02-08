#ifndef IFILE_H
#define IFILE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stdio.h>

long file_size(FILE* file);
bool file_create(char* fileName);
bool file_delete(char* fileName);
bool file_exists(char* file);

#ifdef __cplusplus
}
#endif

#endif /* IFILE_H */


