#if !defined(__AUTOMATA_H__)
#define __AUTOMATA_H__

#include <exception>
#include <string>

class CharacterOutOfAlphabet : public std::exception {
public:
    char const *what() const noexcept override {
        return "CharacterOutOfAlphabet";
    }
};

class InvalidAutomaton : public std::exception {
public:
    char const *what() const noexcept override {
        return "InvalidAutomaton";
    }
};

class Alphabet {
private:
    std::string s;
public:
    Alphabet();

    explicit Alphabet(const std::string &str);

    size_t size() const;

    size_t charId(char c) const;

    int compare(char c1, char c2) const;

    std::string str() const;
};

#endif // __AUTOMATA_H__
