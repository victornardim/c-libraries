# integer.h - C Integer util library

A simple C library that provides some general functions linked to integers.

## Functions

<code>
<pre>
// Return the number length, in digits.
<b>int integer_getNumberLength(int number)</b>

// Return an array of int, which each position is a digit from the number.
<b>int* integer_decomposeNumber(int number)</b>

// Return a random integer between the range of min and max.
<b>int integer_getRandom(int min, int max)</b>

// Convert the specified string into integer.
<b>int integer_convertFromString(char* string)</b>
</pre>
</code>
