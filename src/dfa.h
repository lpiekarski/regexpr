#if !defined(__DFA_H__)
#define __DFA_H__

#include "automata.h"

class DFA {
private:
    size_t n;
    Alphabet a;
    size_t start, stop;
public:
    DFA();

    explicit DFA(const Alphabet &a);

    DFA(size_t n, const Alphabet &a);
};

#endif // __DFA_H__