//
// Stack.cpp
// Cameron Fisher - Section 2
// Last Modified: 11/08/2021
//
#include "Stack.h"

void Stack::setCapacity(size_t n) {
    stack.reserve(n);
}

uint64_t Stack::getSize() {
    return stack.size();
}

void Stack::push(char data){
    stack.push_back(data);
}

char Stack::pop(){
    char data = stack.back();
    stack.pop_back();
    return data;
}

char Stack::top(){
    return stack.back();
}

void Stack::print(){
    std::cout << "Stack contains (top to bottom): " << std::endl;
    for (auto i=stack.size()-1; i>0; i--) {
        std::cout << stack.at(i);
    }
    std::cout << stack.at(0) << std::endl;
}

double Stack::makeOperand() { //Creates operands
    std::string operand;
    char temp;
    while (top() != ' ' && stack.size() > 0) {// While not space or empty
        temp = pop();
        operand.append(1, temp);
    }
    for(auto i=0; i<operand.size()/2; i++) { //correct order of operand
        std::swap(operand[i], operand[operand.size()-1-i]);
    }
    pop(); //remove space
    return stod(operand);
}

double Stack::evaluate() { //Evaluates a RPN equation
    double operand1;
    double operand2;
    char op = pop(); //take operator
    pop(); //remove space
    if (top() > 47) { //If greater than possible operators ( *=42, +=43, -=45, /=47)
        operand2 = makeOperand();
    } else {
        operand2 = evaluate(); //Else is a possible operator
    }
    if (top() > 47) { //If greater than possible operators ( *=42, +=43, -=45, /=47)
        operand1 = makeOperand();
    } else {
        operand1 = evaluate(); //Else is a possible operator
    }
    switch (op) { //Returns
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            return operand1 / operand2;
        default:
            std::cout << "Error: Operator not a proper mathematical operator!" << std::endl;
            return -1;
    }
}
