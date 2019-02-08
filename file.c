#include "iFile.h"

#include <stdbool.h>
#include <stdio.h>

#define READ_MODE "r"
#define WRITE_MODE "w"

long file_size(FILE* file){
    long file_size;

    if(file != NULL){
        fseek(file , 0 , SEEK_END);
        file_size = ftell(file);
        rewind(file);
    }

    return file_size;
}

bool file_create(char* fileName){
    FILE* file = fopen(fileName, WRITE_MODE);
    pclose(file);

    return file_exists(fileName);
}

bool file_delete(char* fileName){
    remove(fileName);

    return !file_exists(fileName);
}

bool file_exists(char* fileLocation){
    bool file_exists = false;

    FILE* file = fopen(fileLocation, READ_MODE);
    if(file != NULL){
        file_exists = true;
        pclose(file);
    }

    return file_exists;
}
