#ifndef CONSOLE_H
#define CONSOLE_H

#include "iString.h"

#ifdef __cplusplus
extern "C" {
#endif

#define console_clearScreen() system("@cls||clear");

char console_readChar();
char* console_readString();
void console_stopExecution();

#ifdef __cplusplus
}
#endif

#endif /* ILOG_H */
