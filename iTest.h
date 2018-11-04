#ifndef ITEST_H
#define ITEST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "iString.h"
#include "iArray.h"
#include "iLog.h"

#ifdef __cplusplus
extern "C" {
#endif
    
#define logTest(status, testName, assertType) if(status){ success(getPatternedString("%s (%s)", 2, testName, assertType)) } else { error(getPatternedString("%s (%s)", 2, testName, assertType)); reportTestError();}
#define assertTrue(assert) logTest((assert == true), __func__, "assertTrue");
#define assertFalse(assert) logTest(assert == false, __func__, "assertFalse");
#define assertEquals(firstData, secondData) logTest((firstData == secondData), __func__, "assertEquals");
#define assertNotEquals(firstData, secondData) logTest((firstData != secondData), __func__, "assertNotEquals");
#define assertStringEquals(firstString, secondString) logTest(stringEquals(firstString, secondString), __func__, "assertStringEquals");
#define assertStringNotEquals(firstString, secondString) logTest(!stringEquals(firstString, secondString), __func__, "assertStringNotEquals");
    
typedef void (*testFunction)();

struct testSuite {
    char* name;
    array* tests;
} typedef testSuite;

testSuite* createTestSuite(char* name);
void destroyTestSuite(testSuite* suite);
void addTestToSuite(testSuite* suite, testFunction test);
void executeSuite(testSuite* suite);
void executeTest(testFunction function);
void reportTestError();
void clearTestErrors();

#ifdef __cplusplus
}
#endif

#endif /* ITEST_H */

