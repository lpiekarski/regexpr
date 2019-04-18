#include "tests.h"
#include "../src/regexpr.h"

#define TESTS_NUM 2

int test_01() {
    testInfoLog(stdout, "constructors test");

    assertNoException(DFA());
    assertNoException(DFA(Alphabet("123456")));
    assertNoException(DFA(1500, Alphabet("123456")));
    assertNoException(DFA(3,
                          Alphabet("abc"),
                          std::vector<std::vector<size_t>>{
                              std::vector<size_t>{1, 0, 0},
                              std::vector<size_t>{0, 2, 0},
                              std::vector<size_t>{2, 2, 2},
                          },
                          std::vector<bool>{
                              false,
                              false,
                              true}))

    return TEST_SUCCESS;
}

int test_02() {
    testInfoLog(stdout, "run test");

    DFA dfa(3,
            Alphabet("abc"),
            std::vector<std::vector<size_t>>{
                    std::vector<size_t>{1, 0, 0},
                    std::vector<size_t>{0, 2, 0},
                    std::vector<size_t>{2, 2, 2},
            },
            std::vector<bool>{
                    false,
                    false,
                    true});

    assert(dfa.run("aacabccacabca"));
    assert(!dfa.run("aacaccacacccacacaccac"));
    assert(dfa.run("aacaccacacccacaaaaaaaaaacccabccccccacacacacaccac"));

    return TEST_SUCCESS;
}

int (*tests[TESTS_NUM])(void) = {
        test_01,
        test_02
};

int main() {
    for (auto test_func : tests)
        testStatusLog(stdout, test_func);
    return 0;
}