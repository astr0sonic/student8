#include "rpn.h"

double calculateRPN(const std::string& expr) {
    std::list<double> operandStack;

    for (char i : expr) {
        if (isdigit(static_cast<unsigned char>(i))) {
            operandStack.push_back(static_cast<double>(i - '0'));
        }
        else if (i == '-' || i == '+' || i == '*' || i == '/') {
            double operand2 = operandStack.back();
            operandStack.pop_back();
            double operand1 = operandStack.back();
            operandStack.pop_back();
            double result;
            switch (i) {
                case '+': result = operand1 + operand2; break;
                case '-': result = operand1 - operand2; break;
                case '*': result = operand1 * operand2; break;
                case '/': result = operand1 / operand2; break;
                case '^': result = pow(operand1, operand2); break;
            }
            operandStack.push_back(result);
        }
    }

    return operandStack.front();
}
