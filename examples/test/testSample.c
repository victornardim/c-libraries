#include <stdio.h>
#include <stdlib.h>

#include "iExample.h"
#include "iTest.h"

void testCorretAddition() {
    assertEquals(addition(1 ,5), 6);
}

void testIncorrectAddition() {
    assertNotEquals(addition(2, 17), 10);
}

void testCorrectSubtraction() {
    assertEquals(subtraction(10, 2), 8);
}

void testIncorrectSubtraction() {
    assertNotEquals(subtraction(17, 8), 5);
}

void testCorrectMultiplication() {
    assertEquals(multiplication(5, 6), 30);
}

void testIncorrectMultiplication() {
    assertNotEquals(multiplication(2, 8), 14);
}

void testCorrectDivision() {
    assertEquals(division(20, 5), 4);
}

void testIncorrectDivision() {
    assertNotEquals(division(12, 6), 3);
}

void testIsEvenWithEvenNumber() {
    assertTrue(isEven(18));    
}

void testIsEvenWithOddNumber() {
    assertFalse(isEven(29));
}

void testGetSupportedNumberName() {
    assertStringEquals(getNumberName(5), "five");
}

void testGetNotSupportedNumberName() {
    assertStringEquals(getNumberName(11), "not supported");
}

void testGetIncorrectNumberName() {
    assertStringNotEquals(getNumberName(7), "nine");
}

int main(int argc, char** argv) {
    testSuite* suite = createTestSuite("Example test suite");
    addTestToSuite(suite, testGetIncorrectNumberName);
    addTestToSuite(suite, testGetNotSupportedNumberName);
    addTestToSuite(suite, testGetSupportedNumberName);
    addTestToSuite(suite, testIsEvenWithOddNumber);
    addTestToSuite(suite, testIsEvenWithEvenNumber);
    addTestToSuite(suite, testIncorrectDivision);
    addTestToSuite(suite, testCorrectDivision);
    addTestToSuite(suite, testIncorrectMultiplication);
    addTestToSuite(suite, testCorrectMultiplication);
    addTestToSuite(suite, testIncorrectSubtraction);
    addTestToSuite(suite, testCorrectSubtraction);
    addTestToSuite(suite, testIncorrectAddition);
    addTestToSuite(suite, testCorretAddition);
    executeSuite(suite);
    destroyTestSuite(suite);
    
    return (EXIT_SUCCESS);
}
