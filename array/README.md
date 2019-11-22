# array.h - C Array library

A C library to easily deal with arrays like a stack (FILO).  
It works with a void pointer (void*), that represents an abstract data type in C.  
You can set any data type of any size to it, but it had to be in a variable, because the lib copies the value from the address. To get the data back it is requires an explicit cast.

## How it works

Some addresses are alloc'd for the array of void* with the size of 10 times the specified data size. If more addresses are required, it will be done when the 11th data is pushed.  
The data from a buffer is copied to this addresses, continuously, this way: array[arraySize * dataSize] = data.  
Let's supose that the array have 5 positions of char[10], that is, 50 addresses:  
  
(array) |--------------------------------------------------|  
  
If we push the string "something" to it:  
  
(array) |something\0----------------------------------------|  
  
And if we push another string "important" to it:  
  
(array) |something\0important\0------------------------------|  
   
That's the way it works, concatenating data after data, continuously.  


## Functions

<code>
<pre>
// Creates an array with 10 initial positions, with the specified data size per position.
<b>array* array_create(int dataSize)</b>

// Destroy the array, freeing all the possible pointers.
<b>void array_destroy(array* array)</b>

// Push the data into the array.
// If the initial max size (10 positions) was exceeded, 10 new positions are allocated.
<b>void array_push(array* array, void* data)</b>

// Get the value from the last position of the array, removing it.
<b>void* array_pop(array* array)</b>

// Get the value from the specified index.
<b>void* array_get(array* array, int index)</b>

// Get the array length.
<b>size_t array_size(array* array)</b>

// Find the specified data in the array and return its index.
<b>int array_find(array* array, void* data)</b>
</pre>
</code>

## Example

<code>
<pre>
int buffer;

array* stack = array_create(sizeof(int));
buffer = 12
array_push(stack, &buffer);
buffer = 35;
array_push(stack, &buffer);
buffer = 8;
array_push(stack, &buffer);
buffer = 17;
array_push(stack, &buffer);

int number = *(int*)array_get(stack, 2); // 8
int size = array_size(stack); // 4
number = *(int*)array_pop(stack); // 17
size = array_size(stack); // 3

buffer = 35;
int foundIndex = array_find(stack, &buffer); // 1

array_destroy(stack);
</pre>
</code>
