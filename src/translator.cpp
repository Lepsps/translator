#include "translator.h"

double Translator::processExpression(const std::string& input) {
    try {
        std::vector<Token> tokens = lex.lexus(input);
        syn.analyze(tokens);
        std::vector<Token> rpn = parser.transform(tokens);
        return evaluator.evaluate(rpn, variables);
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return NAN;
    }
}

void Translator::processInput(const std::string& input) {
    size_t equal_pos = input.find('=');
    if (equal_pos != std::string::npos) {
        std::string var_name = input.substr(0, equal_pos);
        var_name.erase(remove_if(var_name.begin(), var_name.end(), ::isspace), var_name.end());
        if (!isalpha(var_name[0])) {
            std::cerr << "Error: Invalid variable name: "  << std::endl;
            return;
        }
        for (size_t i = 1; i < var_name.size(); i++) {
            if (!isalnum(var_name[i]) && var_name[i] != '_') {
                std::cerr << "Error: Invalid variable name: " << std::endl;
                return;
            }
        }


        std::string expression = input.substr(equal_pos + 1);
        double result = processExpression(expression);
        if (!isnan(result)) {
            variables[var_name] = result;
        }
        
    }
    else {
        std::string trimmed_input = input;
        trimmed_input.erase(remove_if(trimmed_input.begin(), trimmed_input.end(), ::isspace), trimmed_input.end());
        if (isalpha(trimmed_input[0])) {
            for (size_t i = 1; i < trimmed_input.size(); i++) {
                if (!isalnum(trimmed_input[i]) && trimmed_input[i] != '_') {
                    std::cout << processExpression(input) << std::endl;
                    return;
                }
            }
            if (variables.count(input)) {
                std::cout << variables[input] << std::endl;
            }
            else {
                std::cout << processExpression(input) << std::endl;
            }
        }
        else {
            std::cout << processExpression(input) << std::endl;
        }
    }
}

void Translator::execute() {
    std::string input;
    std::cout << "\nThis is the simplest translator of mathematical expressions \n" << std::endl;
    std::cout << "Use operators +,-,*,/,^, mathematical functions sin(),cos() and constants pi and exp (e) \n" << std::endl;
    std::cout << "Enter your mathematical expression. His answer or the reason for the error will be displayed in the line below.\n" << std::endl;

    while (true) {
        std::cout << ">>> ";
        getline(std::cin, input);
        if (input == "exit") {
            break;
        }
        processInput(input);
    }
}