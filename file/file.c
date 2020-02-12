#include "file.h"

#include <stdbool.h>
#include <stdio.h>

#if defined(_WIN32)
	#include <direct.h>
#elif defined(__unix__)
	#include <sys/stat.h>
	#include <unistd.h>
#endif

#include "advstring.h"

#define READ_MODE "r"
#define WRITE_MODE "w"
#define APPEND_MODE "a"

long file_size(FILE* file) {
    long file_size;

    if (file != NULL) {
        fseek(file, 0, SEEK_END);
        file_size = ftell(file);
        rewind(file);
    }

    return file_size;
}

bool file_create(char* fileName) {
    FILE* file = fopen(fileName, WRITE_MODE);
    fclose(file);

    return file_exists(fileName);
}

void file_write(char* fileName, char* content) {
    FILE* file = fopen(fileName, APPEND_MODE);
    fputs(content, file);
    fclose(file);
}

bool file_delete(char* fileName) {
    remove(fileName);
    return !file_exists(fileName);
}

bool file_exists(char* fileLocation) {
    bool file_exists = false;

    FILE* file = fopen(fileLocation, READ_MODE);
    if (file != NULL) {
        file_exists = true;
        fclose(file);
    }

    return file_exists;
}

void file_createDirectory(char* directory) {
#if defined(_WIN32)
	mkdir(directory);
#elif defined(__unix__)
	mkdir(directory, 0700);
#endif
}

char* file_getActiveDirectory() {
	char* activeDirectory = advstring_allocateFromLength(BUFFER_DEFAULT_SIZE);

#if defined(_WIN32)
	_getcwd(activeDirectory, BUFFER_DEFAULT_SIZE);
#elif defined(__unix__)
	getcwd(activeDirectory, BUFFER_DEFAULT_SIZE);
#endif

	return activeDirectory;
}
