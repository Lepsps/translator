#include "calculation.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
#ifndef M_E
#define M_E 2.71828182845904523536
#endif

double Ñalculation::evaluate(const std::vector<Token>& rpn, std::map<std::string, double>& variables) {
    std::stack<double> values;
    auto rpn_iter = rpn.begin();

    for (; rpn_iter != rpn.end(); ++rpn_iter) {
        const auto& token = *rpn_iter;
        switch (token.type) {
        case TokenType::NUMBER:
            values.push(stod(token.value));
            break;
        case TokenType::IDENTIFIER: {
            if (variables.count(token.value)) {
                values.push(variables[token.value]);
            }
            else {
                throw std::invalid_argument("Undefined variable");
            }
            break;
        }
        case TokenType::PI:
            values.push(M_PI);
            break;
        case TokenType::EXP:
            values.push(M_E);
            break;
        case TokenType::SIN: {
            if (values.size() < 1) throw std::invalid_argument("Invalid expression: not enough operands for sin");
            double val = values.top(); values.pop();
            values.push(sin(val));
            break;
        }
        case TokenType::COS: {
            if (values.size() < 1) throw std::invalid_argument("Invalid expression: not enough operands for cos");
            double val = values.top(); values.pop();
            values.push(cos(val));
            break;
        }
        case TokenType::MAX: {
            if (values.size() < 2) throw std::invalid_argument("Invalid expression: not enough operands for max");
            double val2 = values.top(); values.pop();
            double val1 = values.top(); values.pop();
            values.push(std::max(val1, val2));
            break;
        }
        case TokenType::MIN: {
            if (values.size() < 2) throw std::invalid_argument("Invalid expression: not enough operands for min");
            double val2 = values.top(); values.pop();
            double val1 = values.top(); values.pop();
            values.push(std::min(val1, val2));
            break;
        }
        case TokenType::PLUS: {
            if (values.size() < 2) throw std::invalid_argument("Invalid expression: not enough operands for +");
            double val2 = values.top(); values.pop();
            double val1 = values.top(); values.pop();
            values.push(val1 + val2);
            break;
        }
        case TokenType::MINUS: {
            if (values.size() < 2) {
                throw std::invalid_argument("Invalid expression: not enough operands for -");
            }
            double val2 = values.top(); values.pop();
            double val1 = values.top(); values.pop();
            values.push(val1 - val2);
            break;
        }
        case TokenType::UNARY_MINUS: {
            if (values.size() < 1) throw std::invalid_argument("Invalid expression: not enough operands for unary -");
            double val = values.top();
            values.pop();
            values.push(-val);
            while (rpn_iter + 1 != rpn.end() && (rpn_iter + 1)->type == TokenType::UNARY_MINUS) {
                ++rpn_iter;
                val = values.top();
                values.pop();
                values.push(-val);
            }
            break;
        }
        case TokenType::MULTIPLY: {
            if (values.size() < 2) throw std::invalid_argument("Invalid expression: not enough operands for *");
            double val2 = values.top(); values.pop();
            double val1 = values.top(); values.pop();
            values.push(val1 * val2);
            break;
        }
        case TokenType::DIVIDE: {
            if (values.size() < 2) throw std::invalid_argument("Invalid expression: not enough operands for /");
            double val2 = values.top(); values.pop();
            double val1 = values.top(); values.pop();
            if (val2 == 0) throw std::invalid_argument("Division by zero");
            values.push(val1 / val2);
            break;
        }
        case TokenType::POWER: {
            if (values.size() < 2) throw std::invalid_argument("Invalid expression: not enough operands for ^");
            double val2 = values.top(); values.pop();
            double val1 = values.top(); values.pop();
            values.push(pow(val1, val2));
            break;
        }
        case TokenType::LESS: {
            if (values.size() < 2) throw std::invalid_argument("Invalid expression: not enough operands for <");
            double val2 = values.top(); values.pop();
            double val1 = values.top(); values.pop();
            values.push(val1 < val2);
            break;
        }
        case TokenType::GREATER: {
            if (values.size() < 2) throw std::invalid_argument("Invalid expression: not enough operands for >");
            double val2 = values.top(); values.pop();
            double val1 = values.top(); values.pop();
            values.push(val1 > val2);
            break;
        }
        default:
            throw std::invalid_argument("Invalid token in RPN evaluation");
        }
    }
    if (values.size() != 1) {
        throw std::invalid_argument("Invalid expression: more than one value on the stack");
    }
    return values.top();
}

