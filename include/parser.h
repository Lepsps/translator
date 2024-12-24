#ifndef PARS_H
#define PARS_H
#include "tokens.h"
#include <stack>

class Parser {
private:
	int get_priority(TokenType type);
public:
	std::vector<Token> transform(const std::vector<Token>& tokens);
};

#endif