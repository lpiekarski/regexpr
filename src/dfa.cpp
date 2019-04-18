#include "dfa.h"

DFA::DFA():
    n(0),
    a(""),
    start(0),
    accepting(),
    t() {}

DFA::DFA(const Alphabet &a):
    n(0),
    a(a),
    start(0),
    accepting(),
    t() {}

DFA::DFA(size_t n, const Alphabet &a):
    n(n),
    a(a),
    start(0),
    accepting(),
    t() {
    std::vector<size_t> v;
    v.resize(a.size());
    t.resize(n, v);
}

DFA::DFA(size_t n,
         const Alphabet &a,
         const std::vector<std::vector<size_t>> &t,
         const std::vector<bool> &accepting):
         n(n),
         a(a),
         start(0),
         t(t),
         accepting(accepting) {
    if (this->accepting.size() != n)
        throw InvalidAutomaton();
    if (this->t.size() != n)
        throw InvalidAutomaton();
    for (const std::vector<size_t> &v : t)
        if (v.size() != a.size())
            throw InvalidAutomaton();
}

bool DFA::run(const std::string &str) {
    size_t state = this->start;
    for (const char &c : str)
        state = t[state][this->a.charId(c)];
    return this->accepting[state];
}