#include "tests.h"
#include "../src/regexpr.h"

#define TESTS_NUM 1

int test_01() {
    testInfoLog(stdout, "constructors test");

    assertNoException(DFA());
    assertNoException(DFA(Alphabet("123456")));
    assertNoException(DFA(1500, Alphabet("123456")));

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