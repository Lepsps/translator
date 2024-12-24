#include "lexical_analysis.h"

std::vector<Token> Lexical_analysis::lexus(const std::string& input) {
    if (input.empty()) {
        throw std::invalid_argument("SyntaxError: empty string");
    }

    State state = State::START;
    std::vector<Token> tokens;
    std::string current_token;

    for (size_t i = 0; i < input.length(); ++i) {
        char s = input[i];

        switch (state) {
        case State::START:
            if (isdigit(s)) {
                current_token += s;
                state = State::INT_N;
            }
            else if (s == '(') {
                tokens.push_back({ TokenType::LEFT_PAREN, "(" });
            }
            else if (s == ')') {
                tokens.push_back({ TokenType::RIGHT_PAREN, ")" });
            }
            else if (s == '/' || s == '*' || s == '+' || s == '^' || s == '<' || s == '>' || s == '=')
            {
                TokenType type;
                switch (s) {
                case '+': type = TokenType::PLUS; break;
                case '-': type = TokenType::MINUS; break;
                case '*': type = TokenType::MULTIPLY; break;
                case '/': type = TokenType::DIVIDE; break;
                case '^': type = TokenType::POWER; break;
                case '<': type = TokenType::LESS; break;
                case '>': type = TokenType::GREATER; break;
                case '=': type = TokenType::EQUAL; break;
                default:  type = TokenType::UNKNOWN; break;
                }
                tokens.push_back({ type, std::string(1, s) });
            }
            else if (isalpha(s) || s == '_') {
                current_token += s;
                state = State::VAR;
            }
            else if (s == '-') {

                if (tokens.empty() ||
                    tokens.back().type == TokenType::LEFT_PAREN ||
                    tokens.back().type == TokenType::PLUS ||
                    tokens.back().type == TokenType::MINUS ||
                    tokens.back().type == TokenType::MULTIPLY ||
                    tokens.back().type == TokenType::DIVIDE ||
                    tokens.back().type == TokenType::POWER ||
                    tokens.back().type == TokenType::LESS ||
                    tokens.back().type == TokenType::GREATER ||
                    tokens.back().type == TokenType::COMMA
                    ) {
                    tokens.push_back({ TokenType::UNARY_MINUS, "-" });
                }
                else {
                    tokens.push_back({ TokenType::MINUS, "-" });
                }
            }
            else if (s == ',') {
                tokens.push_back({ TokenType::COMMA, "," });
            }
            else if (isspace(s)) {
                continue;
            }
            else {
                current_token += s;
                tokens.push_back({ TokenType::UNKNOWN, current_token });
                current_token.clear();

            }
            break;

        case State::INT_N:
            if (isdigit(s)) {
                current_token += s;
            }
            else if (s == '.') {
                current_token += s;
                state = State::DYBLE_N;
            }
            else {
                tokens.push_back({ TokenType::NUMBER, current_token });
                current_token.clear();
                state = State::START;
                --i;
            }
            break;

        case State::DYBLE_N:
            if (isdigit(s)) {
                current_token += s;
            }
            else {
                tokens.push_back({ TokenType::NUMBER, current_token });
                current_token.clear();
                state = State::START;
                --i;
            }
            break;
        case State::VAR:
            if (isalpha(s) || isdigit(s) || s == '_') {
                current_token += s;
            }
            else {

                if (current_token == "sin") {
                    tokens.push_back({ TokenType::SIN, current_token });
                }
                else if (current_token == "cos") {
                    tokens.push_back({ TokenType::COS, current_token });
                }
                else if (current_token == "max") {
                    tokens.push_back({ TokenType::MAX, current_token });
                }
                else if (current_token == "min") {
                    tokens.push_back({ TokenType::MIN, current_token });
                }
                else if (current_token == "pi") {
                    tokens.push_back({ TokenType::PI, current_token });
                }
                else if (current_token == "exp") {
                    tokens.push_back({ TokenType::EXP, current_token });
                }
                else {
                    tokens.push_back({ TokenType::IDENTIFIER, current_token });
                }
                current_token.clear();
                state = State::START;
                --i;
            }
            break;
        }
    }
    if (!current_token.empty()) {
        if (state == State::INT_N || state == State::DYBLE_N) {
            tokens.push_back({ TokenType::NUMBER, current_token });
        }
        else if (state == State::VAR) {
            if (current_token == "sin") {
                tokens.push_back({ TokenType::SIN, current_token });
            }
            else if (current_token == "cos") {
                tokens.push_back({ TokenType::COS, current_token });
            }
            else if (current_token == "max") {
                tokens.push_back({ TokenType::MAX, current_token });
            }
            else if (current_token == "min") {
                tokens.push_back({ TokenType::MIN, current_token });
            }
            else if (current_token == "pi") {
                tokens.push_back({ TokenType::PI, current_token });
            }
            else if (current_token == "exp") {
                tokens.push_back({ TokenType::EXP, current_token });
            }
            else {
                tokens.push_back({ TokenType::IDENTIFIER, current_token });
            }
        }
        else {
            tokens.push_back({ TokenType::UNKNOWN, current_token });
        }
    }

    tokens.push_back({ TokenType::END_OF_EXPRESSION, "" });
    return tokens;
}
