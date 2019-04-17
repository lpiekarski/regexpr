#include <array>
#include <string>

#include "tests.h"
#include "../src/automata.h"

#define TESTS_NUM 3

int test_01() {
    testInfoLog(stdout, "compare test");

    Alphabet a("3214");
    assert(a.compare('3', '1') == -1);
    assert(a.compare('1', '3') == 1);
    assert(a.compare('1', '1') == 0);

    return TEST_SUCCESS;
}

int test_02() {
    testInfoLog(stdout, "charId test");

    Alphabet a("3214");
    assert(a.charId('3') == 0);
    assert(a.charId('2') == 1);
    assert(a.charId('1') == 2);
    assert(a.charId('4') == 3);

    return TEST_SUCCESS;
}

int test_03() {
    testInfoLog(stdout, "size test");

    const size_t testsNum = 4;

    std::array<std::string, testsNum> testAlphabets = {
            "",
            "123321123312123",
            "abcbcbcbcbcbcbcbcbbcbcbc",
            "12 3\n45 678 90-= qwe\trtyuiop[]\\asdf\tghjkl;'"
    };

    std::array<const size_t, testsNum> sizes = {
            0,
            3,
            3,
            39
    };

    for (size_t i = 0; i < testsNum; ++i) {
        testInfoLog(stdout, ("subtest number " + std::to_string(i)).c_str());
        assert(Alphabet(testAlphabets[i]).size() == sizes[i]);
    }

    return TEST_SUCCESS;
}

int (*tests[TESTS_NUM])(void) = {
        test_01,
        test_02,
        test_03
};

int main() {
    for (auto test_func : tests)
        testStatusLog(stdout, test_func);
    return 0;
}