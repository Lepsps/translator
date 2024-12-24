#ifndef CALC_H
#define CALC_H
#include "tokens.h"
#include <map>
#include <stack>

class �alculation {
public:
    double evaluate(const std::vector<Token>& rpn, std::map<std::string, double>& variables);
};

#endif