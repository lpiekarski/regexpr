#include "tests.h"
#include "../src/regexpr.h"

#define TESTS_NUM 2

int test_01() {
    testInfoLog(stdout, "constructors test");

    testInfoLog(stdout, "NFA()");
    assertNoException(NFA());

    testInfoLog(stdout, "NFA(1)");
    assertNoException(NFA(Alphabet("abcabc")));

    testInfoLog(stdout, "NFA(2)");
    assertNoException(NFA(1000, Alphabet("abc")));

    testInfoLog(stdout, "NFA(5)");
    assertNoException(NFA(4,
                          Alphabet("abcdef"),
                          std::vector<std::vector<std::vector<size_t>>> {
                              std::vector<std::vector<size_t>> {
                                  std::vector<size_t> {0, 1},
                                  std::vector<size_t> {0},
                                  std::vector<size_t> {0},
                                  std::vector<size_t> {0},
                                  std::vector<size_t> {0},
                                  std::vector<size_t> {0},
                              },
                              std::vector<std::vector<size_t>> {
                                  std::vector<size_t> {},
                                  std::vector<size_t> {2},
                                  std::vector<size_t> {},
                                  std::vector<size_t> {},
                                  std::vector<size_t> {},
                                  std::vector<size_t> {},
                              },
                              std::vector<std::vector<size_t>> {
                                  std::vector<size_t> {},
                                  std::vector<size_t> {},
                                  std::vector<size_t> {3},
                                  std::vector<size_t> {},
                                  std::vector<size_t> {},
                                  std::vector<size_t> {},
                              },
                              std::vector<std::vector<size_t>> {
                                  std::vector<size_t> {3},
                                  std::vector<size_t> {3},
                                  std::vector<size_t> {3},
                                  std::vector<size_t> {3},
                                  std::vector<size_t> {3},
                                  std::vector<size_t> {3},
                              },
                          },
                          std::vector<bool> {true, false, false, false},
                          std::vector<bool> {false, false, false, true}));

    return TEST_SUCCESS;
}

int test_02() {
    testInfoLog(stdout, "run test");

    NFA nfa(4,
           Alphabet("abcdef"),
           std::vector<std::vector<std::vector<size_t>>> {
                   std::vector<std::vector<size_t>> {
                       std::vector<size_t> {0, 1},
                       std::vector<size_t> {0},
                       std::vector<size_t> {0},
                       std::vector<size_t> {0},
                       std::vector<size_t> {0},
                       std::vector<size_t> {0},
                   },
                   std::vector<std::vector<size_t>> {
                       std::vector<size_t> {},
                       std::vector<size_t> {2},
                       std::vector<size_t> {},
                       std::vector<size_t> {},
                       std::vector<size_t> {},
                       std::vector<size_t> {},
                   },
                   std::vector<std::vector<size_t>> {
                       std::vector<size_t> {},
                       std::vector<size_t> {},
                       std::vector<size_t> {3},
                       std::vector<size_t> {},
                       std::vector<size_t> {},
                       std::vector<size_t> {},
                   },
                   std::vector<std::vector<size_t>> {
                       std::vector<size_t> {3},
                       std::vector<size_t> {3},
                       std::vector<size_t> {3},
                       std::vector<size_t> {3},
                       std::vector<size_t> {3},
                       std::vector<size_t> {3},
                   },
               },
               std::vector<bool> {true, false, false, false},
               std::vector<bool> {false, false, false, true});
    assert(nfa.run("abcdebcfadefcda"));
    assert(nfa.run("bcadfedabcfedfaafdcfabf"));
    assert(nfa.run("bcadfedfedfaafdcfabfabc"));
    assert(!nfa.run("bcadfedfedfaafdcfabf"));

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