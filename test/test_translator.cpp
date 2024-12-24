#include "gtest.h"
#include "translator.h" // Replace with the actual header file name
#include "lexical_analysis.h"
#include "syntax_analysis.h"
#include "calculation.h"


TEST(TranslatorTest, SimpleAddition) {
    Translator t;
    std::stringstream ss;
    std::streambuf* oldCout = std::cout.rdbuf();
    std::cout.rdbuf(ss.rdbuf());

    t.processInput("2+3");

    std::cout.rdbuf(oldCout);
    ASSERT_EQ(ss.str(), "5\n");
}

TEST(TranslatorTest, SimpleSubtraction) {
    Translator t;
    std::stringstream ss;
    std::streambuf* oldCout = std::cout.rdbuf();
    std::cout.rdbuf(ss.rdbuf());

    t.processInput("5-2");
    
    std::cout.rdbuf(oldCout);
    ASSERT_EQ(ss.str(), "3\n");
}

TEST(TranslatorTest, SimpleMultiplication) {
    Translator t;
    std::stringstream ss;
    std::streambuf* oldCout = std::cout.rdbuf();
    std::cout.rdbuf(ss.rdbuf());
    
    t.processInput("4*5");
    
    std::cout.rdbuf(oldCout);
    ASSERT_EQ(ss.str(), "20\n");
}

TEST(TranslatorTest, SimpleDivision) {
    Translator t;
    std::stringstream ss;
    std::streambuf* oldCout = std::cout.rdbuf();
    std::cout.rdbuf(ss.rdbuf());
    
    t.processInput("10/2");
    
    std::cout.rdbuf(oldCout);
    ASSERT_EQ(ss.str(), "5\n");
}

TEST(TranslatorTest, Power) {
    Translator t;
    std::stringstream ss;
    std::streambuf* oldCout = std::cout.rdbuf();
    std::cout.rdbuf(ss.rdbuf());
    
    t.processInput("2^3");
    
    std::cout.rdbuf(oldCout);
    ASSERT_EQ(ss.str(), "8\n");
}


TEST(TranslatorTest, Parentheses) {
    Translator t;
    std::stringstream ss;
    std::streambuf* oldCout = std::cout.rdbuf();
    std::cout.rdbuf(ss.rdbuf());
    
    t.processInput("(2+3)*2");
    
    std::cout.rdbuf(oldCout);
    ASSERT_EQ(ss.str(), "10\n");
}

TEST(TranslatorTest, UnaryMinus) {
    Translator t;
    std::stringstream ss;
    std::streambuf* oldCout = std::cout.rdbuf();
    std::cout.rdbuf(ss.rdbuf());
    
    t.processInput("-5+2");
    
    std::cout.rdbuf(oldCout);
    ASSERT_EQ(ss.str(), "-3\n");
}

TEST(TranslatorTest, VariableAssignment) {
    Translator t;
    std::stringstream ss;
    std::streambuf* oldCout = std::cout.rdbuf();
    std::cout.rdbuf(ss.rdbuf());
    
    t.processInput("x = 5");
    t.processInput("x + 2");
    
    std::cout.rdbuf(oldCout);
    ASSERT_EQ(ss.str(), "7\n");
}
TEST(TranslatorTest, VariableUsage) {
    Translator t;
    std::stringstream ss;
    std::streambuf* oldCout = std::cout.rdbuf();
    std::cout.rdbuf(ss.rdbuf());
    
    t.processInput("x = 5");
    t.processInput("y = x + 2");
    t.processInput("y");
    
    std::cout.rdbuf(oldCout);
    ASSERT_EQ(ss.str(), "7\n");

}
TEST(TranslatorTest, RedefineVariable) {
    Translator t;
    std::stringstream ss;
    std::streambuf* oldCout = std::cout.rdbuf();
    std::cout.rdbuf(ss.rdbuf());
    
    t.processInput("x = 5");
    t.processInput("x = 10");
    t.processInput("x");
    
    std::cout.rdbuf(oldCout);
    ASSERT_EQ(ss.str(), "10\n");
}
TEST(TranslatorTest, ExpressionWithVariable) {
    Translator t;
    std::stringstream ss;
    std::streambuf* oldCout = std::cout.rdbuf();
    std::cout.rdbuf(ss.rdbuf());
    
    t.processInput("x = 3");
    t.processInput("2 * x + 5");
    
    std::cout.rdbuf(oldCout);
    ASSERT_EQ(ss.str(), "11\n");

}

TEST(TranslatorTest, ComparisonTrue) {
    Translator t;
    std::stringstream ss;
    std::streambuf* oldCout = std::cout.rdbuf();
    std::cout.rdbuf(ss.rdbuf());
    
    t.processInput("5 < 10");
    
    std::cout.rdbuf(oldCout);
    ASSERT_EQ(ss.str(), "1\n");
}
TEST(TranslatorTest, Comparison) {
    Translator t;
    std::stringstream ss;
    std::streambuf* oldCout = std::cout.rdbuf();
    std::cout.rdbuf(ss.rdbuf());
    
    t.processInput("5 > 10");

    std::cout.rdbuf(oldCout);
    ASSERT_EQ(ss.str(), "0\n");
}
TEST(TranslatorTest, SinFunction) {
    Translator t;
    std::stringstream ss;
    std::streambuf* oldCout = std::cout.rdbuf();
    std::cout.rdbuf(ss.rdbuf());
    
    t.processInput("sin(0)");
    
    std::cout.rdbuf(oldCout);
    ASSERT_EQ(ss.str(), "0\n");
}

TEST(TranslatorTest, CosFunction) {
    Translator t;
    std::stringstream ss;
    std::streambuf* oldCout = std::cout.rdbuf();
    std::cout.rdbuf(ss.rdbuf());
    
    t.processInput("cos(0)");
    
    std::cout.rdbuf(oldCout);
    ASSERT_EQ(ss.str(), "1\n");
}

TEST(TranslatorTest, MaxFunction) {
    Translator t;
    std::stringstream ss;
    std::streambuf* oldCout = std::cout.rdbuf();
    std::cout.rdbuf(ss.rdbuf());
    
    t.processInput("max(5, 10)");
    
    std::cout.rdbuf(oldCout);
    ASSERT_EQ(ss.str(), "10\n");
}
TEST(TranslatorTest, MinFunction) {
    Translator t;
    std::stringstream ss;
    std::streambuf* oldCout = std::cout.rdbuf();
    std::cout.rdbuf(ss.rdbuf());
    
    t.processInput("min(5, 10)");
    
    std::cout.rdbuf(oldCout);
    ASSERT_EQ(ss.str(), "5\n");
}

TEST(TranslatorTest, ComplexExpression) {
    Translator t;
    std::stringstream ss;
    std::streambuf* oldCout = std::cout.rdbuf();
    std::cout.rdbuf(ss.rdbuf());
    
    t.processInput("(10 + 5) * sin(pi / 2)");
    
    std::cout.rdbuf(oldCout);
    ASSERT_EQ(ss.str(), "15\n");
}

TEST(TranslatorTest, HardComplexExpression) {
    Translator t;
    std::stringstream ss;
    std::streambuf* oldCout = std::cout.rdbuf();
    std::cout.rdbuf(ss.rdbuf());
   
    t.processInput("max(100,min(100,10)) -- (10 + 5) * cos(sin(pi / 2))");
    
    std::cout.rdbuf(oldCout);
    ASSERT_EQ(ss.str(), "108.105\n");
}

TEST(TranslatorTest, Spaces) {
    Translator t;
    std::stringstream ss;
    std::streambuf* oldCout = std::cout.rdbuf();
    std::cout.rdbuf(ss.rdbuf());
    
    t.processInput("  2 +   3  ");
    
    std::cout.rdbuf(oldCout);
    ASSERT_EQ(ss.str(), "5\n");
}

TEST(LexicalAnalysisTest, EmptyInput) {
    Lexical_analysis lex;
    ASSERT_THROW(lex.lexus(""), std::invalid_argument);
}

TEST(LexicalAnalysisTest, ValidTokens) {
    Lexical_analysis lex;
    std::vector<Token> tokens = lex.lexus("12 + 3.14 * sin(x)");
    ASSERT_EQ(tokens.size(), 9);
    ASSERT_EQ(tokens[0].type, TokenType::NUMBER);
    ASSERT_EQ(tokens[1].type, TokenType::PLUS);
    ASSERT_EQ(tokens[2].type, TokenType::NUMBER);
    ASSERT_EQ(tokens[3].type, TokenType::MULTIPLY);
    ASSERT_EQ(tokens[4].type, TokenType::SIN);
    ASSERT_EQ(tokens[5].type, TokenType::LEFT_PAREN);
    ASSERT_EQ(tokens[6].type, TokenType::IDENTIFIER);
    ASSERT_EQ(tokens[7].type, TokenType::RIGHT_PAREN);
    ASSERT_EQ(tokens[8].type, TokenType::END_OF_EXPRESSION);

}


TEST(SyntaxAnalysisTest, UnclosedParentheses) {
    Syntax_analysis syn;
    Lexical_analysis lex;
    std::vector<Token> tokens = lex.lexus("(1 + 2");

    ASSERT_THROW(syn.analyze(tokens), std::invalid_argument);
}

TEST(SyntaxAnalysisTest, IncorrectExpression1) {
    Syntax_analysis syn;
    Lexical_analysis lex;
    std::vector<Token> tokens = lex.lexus("1 + + 2");

    try {
        syn.analyze(tokens);
        FAIL() << "Expected std::invalid_argument";
    }
    catch (const std::invalid_argument& e) {
        ASSERT_STREQ("SyntaxError: invalid syntax after operator", e.what());
    }
}
TEST(SyntaxAnalysisTest, IncorrectExpression2) {
    Syntax_analysis syn;
    Lexical_analysis lex;
    std::vector<Token> tokens = lex.lexus("1 +  ");

    try {
        syn.analyze(tokens);
        FAIL() << "Expected std::invalid_argument";
    }
    catch (const std::invalid_argument& e) {
        ASSERT_STREQ("SyntaxError: invalid syntax after operator", e.what());
    }
}

TEST(SyntaxAnalysisTest, IncorrectExpression3) {
    Syntax_analysis syn;
    Lexical_analysis lex;
    std::vector<Token> tokens = lex.lexus("1 + (");

    try {
        syn.analyze(tokens);
        FAIL() << "Expected std::invalid_argument";
    }
    catch (const std::invalid_argument& e) {
        ASSERT_STREQ("SyntaxError: invalid syntax after lbrack", e.what());
    }
}
TEST(SyntaxAnalysisTest, IncorrectExpression4) {
    Syntax_analysis syn;
    Lexical_analysis lex;
    std::vector<Token> tokens = lex.lexus("(1+)");

    try {
        syn.analyze(tokens);
        FAIL() << "Expected std::invalid_argument";
    }
    catch (const std::invalid_argument& e) {
        ASSERT_STREQ("SyntaxError: invalid syntax after operator", e.what());
    }
}

TEST(SyntaxAnalysisTest, ValidExpression) {
    Syntax_analysis syn;
    Lexical_analysis lex;
    std::vector<Token> tokens = lex.lexus("2 * (3 + 4) - 5");

    ASSERT_NO_THROW(syn.analyze(tokens));
}


TEST(ParserTest, MismatchedParentheses) {
    Parser parser;
    Lexical_analysis lex;
    std::vector<Token> tokens = lex.lexus("(1 + 2");

    try {
        parser.transform(tokens);
        FAIL() << "Expected std::invalid_argument";
    }
    catch (const std::invalid_argument& e) {
        ASSERT_STREQ("Mismatched parentheses", e.what());
    }
}


TEST(ParserTest, InvalidToken) {
    Parser parser;
    Lexical_analysis lex;
    std::vector<Token> tokens = lex.lexus("2 @ 3");

    try {
        parser.transform(tokens);
        FAIL() << "Expected std::invalid_argument";
    }
    catch (const std::invalid_argument& e) {
        ASSERT_STREQ("Invalid token type", e.what());
    }
}

TEST(ParserTest, ValidExpression) {
    Parser parser;
    Lexical_analysis lex;
    std::vector<Token> tokens = lex.lexus("2 * (3 + 4) - 5");
    ASSERT_NO_THROW(parser.transform(tokens));
}



TEST(CalculationTest, DivisionByZero) {
    Ñalculation calc;
    Lexical_analysis lex;
    Parser parser;
    std::vector<Token> tokens = lex.lexus("10 / 0");

    std::vector<Token> rpn = parser.transform(tokens);
    std::map<std::string, double> variables;

    ASSERT_THROW(calc.evaluate(rpn, variables), std::invalid_argument);
}

TEST(CalculationTest, UndefinedVariable) {
    Ñalculation calc;
    Lexical_analysis lex;
    Parser parser;
    std::vector<Token> tokens = lex.lexus("x + 1");
    std::vector<Token> rpn = parser.transform(tokens);
    std::map<std::string, double> variables;

    ASSERT_THROW(calc.evaluate(rpn, variables), std::invalid_argument);
}
TEST(CalculationTest, NotEnoughOperands) {
    Ñalculation calc;
    Lexical_analysis lex;
    Parser parser;
    std::vector<Token> tokens = lex.lexus("sin + 2");
    std::vector<Token> rpn = parser.transform(tokens);
    std::map<std::string, double> variables;
    try {
        calc.evaluate(rpn, variables);
        FAIL() << "Expected std::invalid_argument";
    }
    catch (const std::invalid_argument& e) {
        ASSERT_STREQ("Invalid expression: not enough operands for +", e.what());
    }
}


TEST(CalculationTest, InvalidExpression) {
    Ñalculation calc;
    Lexical_analysis lex;
    Parser parser;
    std::vector<Token> tokens = lex.lexus("1 2 + +");
    std::vector<Token> rpn = parser.transform(tokens);
    std::map<std::string, double> variables;
    try {
        calc.evaluate(rpn, variables);
        FAIL() << "Expected std::invalid_argument";
    }
    catch (const std::invalid_argument& e) {
        ASSERT_STREQ("Invalid expression: not enough operands for +", e.what());
    }
}
TEST(CalculationTest, InvalidTokenInRpn) {
    Ñalculation calc;
    std::vector<Token> rpn = { {TokenType::UNKNOWN,""} };
    std::map<std::string, double> variables;
    try {
        calc.evaluate(rpn, variables);
        FAIL() << "Expected std::invalid_argument";
    }
    catch (const std::invalid_argument& e) {
        ASSERT_STREQ("Invalid token in RPN evaluation", e.what());
    }
}

TEST(CalculationTest, ValidCalculation) {
    Ñalculation calc;
    Lexical_analysis lex;
    Parser parser;
    std::vector<Token> tokens = lex.lexus("2 * (3 + 4) - 5");
    std::vector<Token> rpn = parser.transform(tokens);
    std::map<std::string, double> variables;
    ASSERT_NO_THROW(calc.evaluate(rpn, variables));
}


TEST(Trans, ValidCalculation) {
    Translator t;
    ASSERT_NO_THROW(t.execute());
}
