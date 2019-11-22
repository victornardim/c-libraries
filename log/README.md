# log.h - C Log library

A simple C library to deal with message logging.

## Functions

```
// Get the current date and time in the format dd/mm/yyyy hh:mm:ss
char* log_getTimestamp()

// Get a string with the specified pattern and arguments
char* log_getPatternedString(char* pattern, int argsCount, ...)

// Print a message in green, precedded by the current timestamp and the word {SUCCESS}
void log_success(char* message)

// Print a message in red, precedded by the current timestamp and the word {ERROR}
void log_error(char* message)

// Print a message, precedded by the current timestamp
void log_message(char* message)
```
