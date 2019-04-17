#include "tests.h"

#include "../src/dfa.h"

#define TESTS_NUM 2

int test_01() {
    return TEST_SUCCESS;
}

int (*tests[TESTS_NUM])(void) = {
        test_01
};

int main() {
    for (auto test_func : tests)
        testStatusLog(stdout, test_func);
    return 0;
}