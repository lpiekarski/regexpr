#include "dfa.h"

DFA::DFA(): n(0), a(""), start(), stop() {}

DFA::DFA(const Alphabet &a): n(0), a(a), start(), stop() {}

DFA::DFA(size_t n, const Alphabet &a): n(n), a(a), start(), stop() {}