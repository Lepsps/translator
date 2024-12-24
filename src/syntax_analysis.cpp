#include "syntax_analysis.h"

void Syntax_analysis::analyze(const std::vector<Token>& tokens) {
    State state = State::START;
    int paren_count = 0;

    for (size_t i = 0; i < tokens.size(); i++) {
        const Token& token = tokens[i];
        if (token.type == TokenType::LEFT_PAREN) paren_count++;
        else if (token.type == TokenType::RIGHT_PAREN) paren_count--;
        switch (state) {
        case State::START:
            if (token.type == TokenType::NUMBER) {
                state = State::NUMBER_S;
            }
            else if (token.type == TokenType::IDENTIFIER) {
                state = State::IDENTIFIER_S;
            }
            else if (token.type == TokenType::LEFT_PAREN) {
                state = State::LBRACK_S;
            }
            else if (token.type == TokenType::UNARY_MINUS) {
                state = State::UNARY_MINUS_S;
            }
            else if (token.type == TokenType::PI) {
                state = State::NUMBER_S;
            }
            else if (token.type == TokenType::EXP) {
                state = State::NUMBER_S;
            }
            else if (token.type == TokenType::SIN ||
                token.type == TokenType::COS ||
                token.type == TokenType::MAX ||
                token.type == TokenType::MIN) {
                state = State::FUNCTION_S;
            }
            else if (token.type == TokenType::END_OF_EXPRESSION) {

            }
            else {
                throw std::invalid_argument("SyntaxError: invalid syntax at start");
            }
            break;

        case State::NUMBER_S:
            if (token.type == TokenType::PLUS ||
                token.type == TokenType::MINUS ||
                token.type == TokenType::MULTIPLY ||
                token.type == TokenType::DIVIDE ||
                token.type == TokenType::POWER ||
                token.type == TokenType::LESS ||
                token.type == TokenType::GREATER)
            {
                state = State::OPERATOR_S;
            }
            else if (token.type == TokenType::RIGHT_PAREN) {
                state = State::RBRACK_S;
            }
            else if (token.type == TokenType::COMMA) {
                state = State::START;
            }
            else if (token.type == TokenType::END_OF_EXPRESSION) {

            }
            else {
                throw std::invalid_argument("SyntaxError: invalid syntax after number");
            }
            break;

        case State::IDENTIFIER_S:
            if (token.type == TokenType::PLUS ||
                token.type == TokenType::MINUS ||
                token.type == TokenType::MULTIPLY ||
                token.type == TokenType::DIVIDE ||
                token.type == TokenType::POWER ||
                token.type == TokenType::LESS ||
                token.type == TokenType::GREATER)
            {
                state = State::OPERATOR_S;
            }
            else if (token.type == TokenType::RIGHT_PAREN) {
                state = State::RBRACK_S;
            }
            else if (token.type == TokenType::LEFT_PAREN)
            {
                state = State::LBRACK_S;
            }
            else if (token.type == TokenType::COMMA) {
                state = State::START;
            }
            else if (token.type == TokenType::END_OF_EXPRESSION) {

            }
            else {
                throw std::invalid_argument("SyntaxError: invalid syntax after identifier");
            }
            break;
        case State::FUNCTION_S:
            if (token.type == TokenType::LEFT_PAREN) {
                state = State::LBRACK_S;
            }
            else {
                throw std::invalid_argument("SyntaxError: invalid syntax after function");
            }
            break;

        case State::UNARY_MINUS_S:
            if (token.type == TokenType::NUMBER)
            {
                state = State::NUMBER_S;
            }
            else if (token.type == TokenType::LEFT_PAREN)
            {
                state = State::LBRACK_S;
            }
            else if (token.type == TokenType::IDENTIFIER)
            {
                state = State::IDENTIFIER_S;
            }
            else if (token.type == TokenType::PI) {
                state = State::NUMBER_S;
            }
            else if (token.type == TokenType::EXP) {
                state = State::NUMBER_S;
            }
            else if (token.type == TokenType::SIN ||
                token.type == TokenType::COS ||
                token.type == TokenType::MAX ||
                token.type == TokenType::MIN) {
                state = State::FUNCTION_S;
            }
            else {
                throw std::invalid_argument("SyntaxError: invalid syntax after unary -");
            }
            break;

        case State::LBRACK_S:
            if (token.type == TokenType::NUMBER) {
                state = State::NUMBER_S;
            }
            else if (token.type == TokenType::IDENTIFIER) {
                state = State::IDENTIFIER_S;
            }
            else if (token.type == TokenType::LEFT_PAREN) {
                state = State::LBRACK_S;
            }
            else if (token.type == TokenType::UNARY_MINUS) {
                state = State::UNARY_MINUS_S;
            }
            else if (token.type == TokenType::PI) {
                state = State::NUMBER_S;
            }
            else if (token.type == TokenType::EXP) {
                state = State::NUMBER_S;
            }
            else if (token.type == TokenType::SIN ||
                token.type == TokenType::COS ||
                token.type == TokenType::MAX ||
                token.type == TokenType::MIN) {
                state = State::FUNCTION_S;
            }
            else {
                throw std::invalid_argument("SyntaxError: invalid syntax after lbrack");
            }
            break;
        case State::RBRACK_S:
            if (token.type == TokenType::PLUS ||
                token.type == TokenType::MINUS ||
                token.type == TokenType::MULTIPLY ||
                token.type == TokenType::DIVIDE ||
                token.type == TokenType::POWER ||
                token.type == TokenType::LESS ||
                token.type == TokenType::GREATER)
            {
                state = State::OPERATOR_S;
            }
            else if (token.type == TokenType::COMMA) {
                state = State::START;
            }
            else if (token.type == TokenType::RIGHT_PAREN)
            {
                state = State::RBRACK_S;
            }
            else if (token.type == TokenType::END_OF_EXPRESSION) {

            }
            else {
                throw std::invalid_argument("SyntaxError: invalid syntax after rbrack");
            }
            break;
        case State::OPERATOR_S:
            if (token.type == TokenType::NUMBER) {
                state = State::NUMBER_S;
            }
            else if (token.type == TokenType::IDENTIFIER) {
                state = State::IDENTIFIER_S;
            }
            else if (token.type == TokenType::LEFT_PAREN) {
                state = State::LBRACK_S;
            }
            else if (token.type == TokenType::UNARY_MINUS) {
                state = State::UNARY_MINUS_S;
            }
            else if (token.type == TokenType::SIN ||
                token.type == TokenType::COS ||
                token.type == TokenType::MAX ||
                token.type == TokenType::MIN) {
                state = State::FUNCTION_S;
            }
            else if (token.type == TokenType::PI) {
                state = State::NUMBER_S;
            }
            else if (token.type == TokenType::EXP) {
                state = State::NUMBER_S;
            }
            else {
                throw std::invalid_argument("SyntaxError: invalid syntax after operator");
            }
            break;

        }
    }
    if (paren_count != 0) {
        throw std::invalid_argument("SyntaxError: invalid syntax - wrong parenthes");
    }
    if (tokens.back().type == TokenType::PLUS ||
        tokens.back().type == TokenType::MINUS ||
        tokens.back().type == TokenType::MULTIPLY ||
        tokens.back().type == TokenType::DIVIDE ||
        tokens.back().type == TokenType::POWER ||
        tokens.back().type == TokenType::COMMA ||
        tokens.back().type == TokenType::LESS ||
        tokens.back().type == TokenType::GREATER ||
        tokens.back().type == TokenType::LEFT_PAREN) {
        throw std::invalid_argument("SyntaxError: invalid syntax - last element is operator or ( ");
    }
}
