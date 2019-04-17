#if !defined(__AUTOMATA_H__)
#define __AUTOMATA_H__

#include <string>

class Alphabet {
private:
    std::string s;
public:
    Alphabet();

    explicit Alphabet(const std::string &str);

    size_t size() const;

    size_t charId(char c) const;

    int compare(char c1, char c2) const;
};

#endif // __AUTOMATA_H__
