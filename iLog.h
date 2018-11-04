#include <stdarg.h>

#ifndef ILOG_H
#define ILOG_H

#ifdef __cplusplus
extern "C" {
#endif
    
#define success(message) printf("\n[%s] {SUCCESS}: %s", getTimestamp(), message);
#define error(message) printf("\n[%s] {ERROR}: %s", getTimestamp(), message);
#define log(message) printf("\n[%s]: %s", getTimestamp(), message);
    
char* getTimestamp();
char* getPatternedString(char* pattern, int argsCount, ...);

#ifdef __cplusplus
}
#endif

#endif /* ILOG_H */

