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
};

#endif // __DFA_H__