#ifndef SYN_AN_H
#define SYN_AN_H

#include "tokens.h"

class Syntax_analysis {
public:
	void analyze(const std::vector<Token>& tokens);
};

#endif