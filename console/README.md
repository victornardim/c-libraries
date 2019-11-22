# console.h - C Console utils library

A simple C library to work with terminals.

## Functions

```c
// Clear the console screen.
void console_clearScreen();

// Wait for the user to enter a char in the terminal and returns it.
char console_readChar();

// Wait for the user to enter a string in the terminal and returns it.
char* console_readString();

// Wait for the user to press some key.
void console_stopExecution();
```
