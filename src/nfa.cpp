#include "nfa.h"

NFA::NFA():
    n(0),
    a(""),
    starting(),
    accepting(),
    t() {}

NFA::NFA(const Alphabet &a):
    n(0),
    a(a),
    starting(),
    accepting(),
    t() {}

NFA::NFA(size_t n, const Alphabet &a):
    n(n),
    a(a),
    starting(),
    accepting(),
    t() {
    starting.resize(n);
    accepting.resize(n);
    std::vector<std::vector<size_t>> v;
    v.resize(a.size());
    t.resize(n, v);
}

NFA::NFA(size_t n,
         const Alphabet &a,
         const std::vector<std::vector<std::vector<size_t>>> &t,
         const std::vector<bool> &starting,
         const std::vector<bool> &accepting):
         n(n),
         a(a),
         t(t),
         starting(starting),
         accepting(accepting) {
    if (starting.size() != n)
        throw InvalidAutomaton();
    if (accepting.size() != n)
        throw InvalidAutomaton();
    if (t.size() != n)
        throw InvalidAutomaton();
    for (const std::vector<std::vector<size_t>> &v : t)
        if (v.size() != a.size())
            throw InvalidAutomaton();
}

bool NFA::run(const std::string &str) {
    std::vector<bool> state(this->starting);
    std::vector<bool> nextState;
    nextState.resize(this->n);

    for (const char &c : str) {
        for (size_t s = 0; s < this->n; ++s)
            if (state[s])
                for (const size_t &tr : this->t[s][this->a.charId(c)])
                    nextState[tr] = true;
        state = nextState;
        for (bool &&b : nextState)
            b = false;
    }

    bool ret = false;
    for (size_t s = 0; s < this->n; ++s)
        if (state[s] && this->accepting[s])
            ret = true;
    return ret;
}