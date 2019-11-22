#include <stdarg.h>

#ifndef LOG_H
#define LOG_H

#ifdef __cplusplus
extern "C" {
#endif

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_RESET "\x1b[0m"

char* log_getTimestamp();
char* log_getPatternedString(char* pattern, int argsCount, ...);
void log_success(char* message);
void log_error(char* message);
void log_message(char* message);

#ifdef __cplusplus
}
#endif

#endif /* LOG_H */

