## integer.h - C Integer util library

A simple C library that provides some general functions linked to integers.

## Functions

```
// Return the number length, in digits.
int integer_getNumberLength(int number)

// Return an array of int, which each position is a digit from the number.
int* integer_decomposeNumber(int number)

// Return a random integer between the range of min and max.
int integer_getRandom(int min, int max)

// Convert the specified string into integer.
int integer_convertFromString(char* string)
```
