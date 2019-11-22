# log.h - C Log library

A simple C library to deal with message logging.

## Functions

<code>
// Get the current date and time in the format dd/mm/yyyy hh:mm:ss
<b>char* log_getTimestamp()</b>

// Get a string with the specified pattern and arguments
<b>char* log_getPatternedString(char* pattern, int argsCount, ...)</b>

// Print a message in green, precedded by the current timestamp and the word {SUCCESS}
<b>void log_success(char* message)</b>

// Print a message in red, precedded by the current timestamp and the word {ERROR}
<b>void log_error(char* message)</b>

// Print a message, precedded by the current timestamp
<b>void log_message(char* message)</b>
</code>
