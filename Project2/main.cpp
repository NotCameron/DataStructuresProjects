//
// main.cpp
// Cameron Fisher - Section 2
// Last Modified: 11/07/2021
//
#include "Stack.h"

int main (int argc, char *argv[]) {
    //Parse command line arguments
    std::string expression;
    for(auto i=1; i<argc; i++) { //append remaining arguments
        expression.append(" ");
        expression.append(argv[i]);
    }
    //RPN Stuff
    Stack stack;
    stack.setCapacity(expression.size()); //Set capacity to string size
    for(auto i=0; i<expression.size(); i++) { //Push String contents as characters
        stack.push(expression[i]);
    }
    std::cout <<"Evaluating RPN of " << expression << std::endl;
    std::cout << "Result: " << stack.evaluate() << std::endl;
}
