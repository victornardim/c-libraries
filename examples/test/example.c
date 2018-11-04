#include <stdio.h>
#include <stdbool.h>

#include "iExample.h"
#include "iString.h"

int addition(int a, int b) {
    return a + b;
}

int subtraction(int a, int b) {
    return a - b;
}

int multiplication(int a, int b) {
    return a * b;
}

int division(int a, int b) {
    if(b == 0) fprintf(stderr, "ERROR! Divide by zero!");
    return a / b;
}

bool isEven(int number) {
    return (number % 2 == 0);
}

char* getNumberName(int number) {
    char* name;
    switch(number){
        case 0:
            allocateStringFromBuffer(&name, "zero");
            break;
            
        case 1:
            allocateStringFromBuffer(&name, "one");
            break;
            
        case 2:
            allocateStringFromBuffer(&name, "two");
            break;
            
        case 3:
            allocateStringFromBuffer(&name, "three");
            break;
            
        case 4:
            allocateStringFromBuffer(&name, "four");
            break;
            
        case 5:
            allocateStringFromBuffer(&name, "five");
            break;
            
        case 6:
            allocateStringFromBuffer(&name, "six");
            break;
            
        case 7:
            allocateStringFromBuffer(&name, "seven");
            break;
            
        case 8:
            allocateStringFromBuffer(&name, "eight");
            break;
            
        case 9:
            allocateStringFromBuffer(&name, "nine");
            break;
            
        default:
            allocateStringFromBuffer(&name, "not supported");
    }
    
    return name;
}