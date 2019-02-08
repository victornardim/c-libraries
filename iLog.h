#include <stdarg.h>

#ifndef ILOG_H
#define ILOG_H

#ifdef __cplusplus
extern "C" {
#endif

#define log_success(message) printf("\n[%s] {SUCCESS}: %s", log_getTimestamp(), message);
#define log_error(message) printf("\n[%s] {ERROR}: %s", log_getTimestamp(), message);
#define log_message(message) printf("\n[%s]: %s", log_getTimestamp(), message);

char* log_getTimestamp();
char* log_getPatternedString(char* pattern, int argsCount, ...);

#ifdef __cplusplus
}
#endif

#endif /* ILOG_H */

