#ifndef IFILE_H
#define IFILE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stdio.h>

long fileSize(FILE* file);
bool createFile(char* fileName);
bool deleteFile(char* fileName);
bool fileExists(char* file);

#ifdef __cplusplus
}
#endif

#endif /* IFILE_H */


