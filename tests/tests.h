#if !defined(__TESTS_H__)
#define __TESTS_H__

#include <cstdio>
#include <exception>
#include <string>

#define TEST_ASSERTION_FAILED (0)
#define TEST_SUCCESS (1)
#define TEST_EXCEPTION (2)

std::string testContext;

const char *test_result[] = {
        "assertion failed",
        "success",
        "exception"
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

#define assertNoException(prog)\
    try {\
        prog;\
    } catch (const std::exception &e) {\
        fprintf(stderr,\
                "%s:%d noexcept assertion failed: %s\n",\
                __func__,\
                __LINE__,\
                e.what()\
                );\
        return TEST_EXCEPTION;\
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
