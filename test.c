#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "iTest.h"
#include "iString.h"
#include "iArray.h"

#define ADDRESS_SIZE 8

static int errors = 0;

testSuite* createTestSuite(char* name) {
    testSuite* newSuite = malloc(sizeof(testSuite));
    allocateStringFromBuffer(&newSuite->name, name);
    newSuite->tests = createArray(ADDRESS_SIZE);
    
    return newSuite;
}

void destroyTestSuite(testSuite* suite) {
    free(suite->name);
    destroyArray(suite->tests);
    free(suite);
}

void addTestToSuite(testSuite* suite, testFunction test) {
    arrayPush(suite->tests, test);
}

static void logSuiteStart(char* suiteName) {
    printf("\nExecuting suite '%s'...", suiteName);
}

static void logSuiteEnd(char* suiteName, float duration, int passedTests, int testQuantity) {
    printf("\nSuite '%s' finished in %.2fs!", suiteName, duration);
    printf("\n%d/%d (%d%%) of the tests have passed.\n", passedTests, testQuantity, (passedTests * 100 / testQuantity));
}

void executeSuite(testSuite* suite) {
    time_t start, end;
    time(&start);
    
    logSuiteStart(suite->name);
    
    int testQuantity = suite->tests->length;
    while(suite->tests->length > 0) {
        testFunction function = (testFunction)arrayPop(suite->tests);
        function();
    }

    int passedTests = (testQuantity - errors);
    
    time(&end);
    
    logSuiteEnd(suite->name, (float)(end - start), passedTests, testQuantity);
    
    clearTestErrors();
}

void reportTestError() {
    errors++;
}

void clearTestErrors() {
    errors = 0;
}