cmake_minimum_required(VERSION 3.8)
project(regexpr)

add_definitions(-std=c++17)

# automata tests
add_executable(automata_test
        tests/automata_test.cpp
        src/automata
        tests/tests.h)

# dfa tests
add_executable(dfa_test
        tests/dfa_test.cpp
        src/dfa
        src/automata
        tests/tests.h)

# all tests
add_custom_target(tests)
add_dependencies(tests
        automata_test
        dfa_test)