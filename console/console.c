#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if defined(_WIN32)
    #include <windows.h>
#endif

#include "console.h"
#include "advstring.h"

char console_readChar() {
    char* buffer = advstring_allocateFromLength(BUFFER_DEFAULT_SIZE);
    char readChar;

    fgets(buffer, BUFFER_DEFAULT_SIZE, stdin);
    sscanf(buffer, "%c", &readChar);

    advstring_destroy(buffer);

    return readChar;
}

char* console_readString() {
    char* readString = advstring_allocateFromLength(BUFFER_DEFAULT_SIZE);

    fgets(readString, BUFFER_DEFAULT_SIZE, stdin);
    readString[strcspn(readString, "\n")] = 0;

    return readString;
}

void console_stopExecution() {
    printf("\n\nPress <ENTER> to continue...");
    getchar();
}

#if defined(_WIN32)
    void console_hide() {
        HWND consoleWindow;
        char screenTitle[100];

        GetConsoleTitleA(screenTitle, sizeof(screenTitle));
        consoleWindow = FindWindowA(NULL, screenTitle);

        ShowWindow(consoleWindow, SW_HIDE);
    }
#endif
