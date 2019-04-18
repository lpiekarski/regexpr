#if !defined(__DFA_H__)
#define __DFA_H__

#include <vector>

#include "automaton.h"

class DFA {
private:
    size_t n;
    Alphabet a;
    size_t start;
    std::vector<bool> accepting;
    std::vector<std::vector<size_t>> t;
public:
    DFA();

    explicit DFA(const Alphabet &a);

    DFA(size_t n, const Alphabet &a);

    DFA(size_t n,
        const Alphabet &a,
        const std::vector<std::vector<size_t>> &t,
        const std::vector<bool> &accepting);

    bool run(const std::string &str);
};

#endif // __DFA_H__