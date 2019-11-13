#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "console.h"
#include "iString.h"

char console_readChar() {
    char* buffer = string_allocateFromLength(BUFFER_DEFAULT_SIZE);
    char readedChar;

    fgets(buffer, BUFFER_DEFAULT_SIZE, stdin);
    sscanf(buffer, "%c", &readedChar);

    string_destroy(buffer);

    return readedChar;
}

char* console_readString() {
    char* readedString = string_allocateFromLength(BUFFER_DEFAULT_SIZE);

    fgets(readedString, BUFFER_DEFAULT_SIZE, stdin);
    readedString[strcspn(readedString, "\n")] = 0;

    return readedString;
}

void console_stopExecution() {
    printf("\n\nPress <ENTER> to continue...");
    getchar();
}
