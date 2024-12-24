#ifndef LEX_AN_H
#define LEX_AN_H

#include "tokens.h"

class Lexical_analysis {
public:
    std::vector<Token> lexus(const std::string& input);
};

#endif