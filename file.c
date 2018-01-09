#include "iFile.h"

#include <stdbool.h>
#include <stdio.h>

#define READ_MODE "r"
#define WRITE_MODE "w"

long fileSize(FILE* file){
    long fileSize;
    
    if(file != NULL){
        fseek(file , 0 , SEEK_END);
        fileSize = ftell(file);
        rewind(file);
    }
    
    return fileSize;
}

bool createFile(char* fileName){     
    FILE* file = fopen(fileName, WRITE_MODE);
    pclose(file);
    
    return fileExists(fileName);
}

bool deleteFile(char* fileName){
    remove(fileName);
    
    return !fileExists(fileName);
}

bool fileExists(char* fileLocation){
    bool fileExists = false;
    
    FILE* file = fopen(fileLocation, READ_MODE);
    if(file != NULL){
        fileExists = true;
        pclose(file);
    }
    
    return fileExists;
}
