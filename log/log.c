#include <stdlib.h>
#include <time.h>
#include <stdarg.h>

#include "log.h"
#include "advstring.h"

char* log_getTimestamp(){
    char* timestamp = advstring_allocateFromLength(50);

    time_t now = time(NULL);
    struct tm* timeStruct = localtime(&now);

    strftime(timestamp, 50, "%d/%m/%Y %T", timeStruct); //Format [dd/mm/yyyy hh:mm:ss]

    return timestamp;
}

char* log_getPatternedString(char* pattern, int argsCount, ...) {
    va_list args;
    va_start(args, argsCount);

    char* message = advstring_allocateFromLength(BUFFER_DEFAULT_SIZE);
    vsnprintf(message, BUFFER_DEFAULT_SIZE, pattern, args);

    va_end(args);

    return message;
}

void log_success(char* message) {
    char* timestamp = log_getTimestamp();
    printf(ANSI_COLOR_GREEN "\n[%s] {SUCCESS}: %s" ANSI_COLOR_RESET, timestamp, message);
    free(timestamp);
}

void log_error(char* message){
    char* timestamp = log_getTimestamp();
    printf(ANSI_COLOR_RED "\n[%s] {ERROR}: %s" ANSI_COLOR_RESET, timestamp, message);
    free(timestamp);
}

void log_message(char* message) {
    char* timestamp = log_getTimestamp();
    printf("\n[%s]: %s", timestamp, message);
    free(timestamp);
}
