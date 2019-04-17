#include <array>
#include <exception>

#include "automata.h"

class CharacterOutOfAlphabet : public std::exception {
public:
    char const *what() const noexcept override {
        return "CharacterOutOfAlphabet";
    }

};

Alphabet::Alphabet(): s("") {}

Alphabet::Alphabet(const std::string &str): s("") {
    std::array<bool, UCHAR_MAX + 1> used_chars = {};
    for (size_t i = 0; i <= UCHAR_MAX; ++i)
        used_chars[i] = false;
    for (const char &c : str) {
        if (used_chars[c])
            continue;
        this->s = this->s + c;
        used_chars[c] = true;
    }
}

size_t Alphabet::size() const {
    return s.size();
}

size_t Alphabet::charId(char c) const {
    for (size_t i = 0; i < this->s.size(); ++i)
        if (this->s[i] == c)
            return i;
    throw CharacterOutOfAlphabet();
}

int Alphabet::compare(char c1, char c2) const {
    size_t cid1 = this->charId(c1),
           cid2 = this->charId(c2);
    if (cid1 > cid2)
        return 1;
    else if (cid1 < cid2)
        return -1;
    return 0;
}

std::string Alphabet::str() const {
    return s;
}