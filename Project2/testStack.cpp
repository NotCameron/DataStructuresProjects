//
// testStack.cpp
// Cameron Fisher - Section 2
// Last Modified: 11/06/2021
//
#include "Stack.h"

int main() {
    //Creating stack and string to be evaluated
    Stack stack;
    std::string testString = "400 40 100 * + 30 + 60 4 / -";
    stack.setCapacity(testString.size());
    for(auto i=0; i<testString.size(); i++) { //Push String contents as characters
        stack.push(testString[i]);
    }
    //Test normal stack functions
    stack.push('Z');
    stack.print();
    std::cout << "Testing pop: " << stack.pop() << std::endl;
    std::cout << "Size of Stack: " << stack.getSize() << std::endl << std::endl;

    //Evaluating string
    stack.print();
    std::cout << "Top: " << stack.top()  << "\nEvaluating RPN (" << testString << "): " << stack.evaluate() << std::endl << std::endl;
    return 0;
}
