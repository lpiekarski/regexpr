cmake_minimum_required(VERSION 3.8)
project(regexpr)

add_definitions(-std=c++17)

# automata tests
add_executable(automaton_test
        tests/automaton_test.cpp
        src/automaton
        tests/tests.h)

# dfa tests
add_executable(dfa_test
        tests/dfa_test.cpp
        src/dfa
        src/automaton
        tests/tests.h)

# nfa tests
add_executable(nfa_test
        tests/nfa_test.cpp
        src/nfa
        src/automaton
        tests/tests.h)

# all tests
add_custom_target(tests)
add_dependencies(tests
        automaton_test
        dfa_test
        nfa_test)