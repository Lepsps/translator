#include "parser.h"


int Parser::get_priority(TokenType type) {
    switch (type) {
    case TokenType::UNARY_MINUS:
        return 5;
    case TokenType::POWER:
        return 4;
    case TokenType::MULTIPLY:
    case TokenType::DIVIDE:
        return 3;
    case TokenType::PLUS:
    case TokenType::MINUS:
        return 2;
    case TokenType::LESS:
    case TokenType::GREATER:
        return 1;
    default:
        return 0;
    }
}

std::vector<Token> Parser::transform(const std::vector<Token>& tokens) {
    std::vector<Token> rpn;
    std::stack<Token> operators;

    for (const auto& token : tokens) {
        switch (token.type) {
        case TokenType::NUMBER:
        case TokenType::IDENTIFIER:
        case TokenType::PI:
        case TokenType::EXP:
            rpn.push_back(token);
            break;
        case TokenType::SIN:
        case TokenType::COS:
        case TokenType::MAX:
        case TokenType::MIN:
            operators.push(token);
            break;
        case TokenType::PLUS:
        case TokenType::MINUS:
        case TokenType::MULTIPLY:
        case TokenType::DIVIDE:
        case TokenType::POWER:
        case TokenType::LESS:
        case TokenType::GREATER:
            while (!operators.empty() && operators.top().type != TokenType::LEFT_PAREN &&
                get_priority(operators.top().type) >= get_priority(token.type)) {
                rpn.push_back(operators.top());
                operators.pop();
            }
            operators.push(token);
            break;
        case TokenType::UNARY_MINUS:
            operators.push(token);
            break;
        case TokenType::LEFT_PAREN:
            operators.push(token);
            break;
        case TokenType::RIGHT_PAREN:
            while (!operators.empty() && operators.top().type != TokenType::LEFT_PAREN) {
                rpn.push_back(operators.top());
                operators.pop();
            }
            if (!operators.empty() && operators.top().type == TokenType::LEFT_PAREN) {
                operators.pop();
                if (!operators.empty() && (operators.top().type == TokenType::SIN ||
                    operators.top().type == TokenType::COS ||
                    operators.top().type == TokenType::MAX ||
                    operators.top().type == TokenType::MIN))
                {
                    rpn.push_back(operators.top());
                    operators.pop();
                }
            }
            else {
                throw std::invalid_argument("Mismatched parentheses");
            }
            break;
        case TokenType::COMMA:
            while (!operators.empty() && operators.top().type != TokenType::LEFT_PAREN)
            {
                rpn.push_back(operators.top());
                operators.pop();
            }
            break;
        case TokenType::END_OF_EXPRESSION:
            while (!operators.empty()) {
                if (operators.top().type == TokenType::LEFT_PAREN) {
                    throw std::invalid_argument("Mismatched parentheses");
                }
                rpn.push_back(operators.top());
                operators.pop();
            }
            break;
        default:
            throw std::invalid_argument("Invalid token type");
        }
    }
    return rpn;
}