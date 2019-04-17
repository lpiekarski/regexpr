#if !defined(__TESTS_H__)
#define __TESTS_H__

#include <cstdio>
#include <string>

#define TEST_ASSERTION_FAILED (0)
#define TEST_SUCCESS (1)

std::string testContext;

const char *test_result[] = {
        "assertion failed",
        "success"
};

#define assert(pred)\
    if (!(pred)) {\
        fprintf(stderr,\
                "%s:%d assertion failed\n",\
                __func__,\
                __LINE__\
                );\
        return TEST_ASSERTION_FAILED;\
    }

#define testInfoLog(stream, msg)\
    if (testContext == __func__) {\
        fprintf(stream, "\t%s\n",  msg);\
    } else {\
        fprintf(stream, "%s: %s\n",  __func__, msg);\
        testContext = __func__;\
    }

#define testStatusLog(stream, func) fprintf(stream, "\t%s test result: %s\n\n",  testContext.c_str(), test_result[func()])

#endif // __TESTS_H__
