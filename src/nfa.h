#if !defined(__NFA_H__)
#define __NFA_H__

#include <vector>

#include "automaton.h"

class NFA {
private:
    size_t n;
    Alphabet a;
    std::vector<bool> starting;
    std::vector<bool> accepting;
    std::vector<std::vector<std::vector<size_t>>> t;
public:
    NFA();

    explicit NFA(const Alphabet &a);

    NFA(size_t n, const Alphabet &a);

    NFA(size_t n,
        const Alphabet &a,
        const std::vector<std::vector<std::vector<size_t>>> &t,
        const std::vector<bool> &starting,
        const std::vector<bool> &accepting);

    bool run(const std::string &str);
};


#endif // __NFA_H__