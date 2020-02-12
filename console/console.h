#ifndef CONSOLE_H
#define CONSOLE_H

#ifdef __cplusplus
extern "C" {
#endif

#define console_clearScreen() system("@cls||clear");

char console_readChar();
char* console_readString();
void console_stopExecution();
#if defined(_WIN32)
    void console_hide();
#endif

#ifdef __cplusplus
}
#endif

#endif /* CONSOLE_H */
