#ifndef TOKENS_H
#define TOKENS_H

#include <iostream>
#include <string>
#include <vector>

enum class TokenType {
    NUMBER,
    IDENTIFIER,
    PLUS,
    MINUS,
    MULTIPLY,
    DIVIDE,
    POWER,
    LESS,
    GREATER,
    LEFT_PAREN,
    RIGHT_PAREN,
    EQUAL,
    SIN,
    COS,
    MAX,
    MIN,
    COMMA,
    PI,
    EXP,
    UNARY_MINUS,
    END_OF_EXPRESSION,
    UNKNOWN
};

struct Token {
    TokenType type;
    std::string value;
};

enum class State {
    START,
    INT_N,
    DYBLE_N,
    VAR,
    LBRACK_S,
    RBRACK_S,
    OPERATOR_S,
    UNARY_MINUS_S,
    NUMBER_S,
    IDENTIFIER_S,
    FUNCTION_S
};

#endif