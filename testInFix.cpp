//
// testStack.cpp
// Cameron Fisher - Section 2
// Last Modified: 11/08/2021
//
#include "Stack.h"

int main() {
    //Creating stack and string to be evaluated
    Stack stack;
    std::string testString = "10 + 30 * 10 + 10 / 2"; //RPN should be 10 30 10 * + 10 2 / +
    stack.setCapacity(testString.size());
    for(auto i=0; i<testString.size(); i++) { //Push String contents as characters
        stack.push(testString[i]);
    }

    //Evaluating string
    stack.print();
    std::cout << "Top: " << stack.top()  << "\nEvaluating RPN (" << testString << "): \n" << stack.evaluate() << std::endl << std::endl;
    return 0;
}
