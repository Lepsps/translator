#ifndef TRANS_H
#define TRANS_H

#include "lexical_analysis.h"
#include "syntax_analysis.h"
#include "parser.h"
#include "calculation.h"

class Translator {
private:
    Lexical_analysis lex;
    Parser parser;
    Ñalculation evaluator;
    Syntax_analysis syn;
    std::map<std::string, double> variables;

    double processExpression(const std::string& input);
public:
    void processInput(const std::string& input);
    void execute();
};

#endif