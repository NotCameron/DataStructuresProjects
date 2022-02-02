//
// Stack.h
// Cameron Fisher - Section 2
// Last Modified: 11/08/2021
//
#ifndef PROJECT2_STACK_H
#define PROJECT2_STACK_H

#include <vector>
#include <cstdint>
#include <iostream>
class Stack {
private:
    std::vector<char> stack;
public:
    void setCapacity(size_t n);
    uint64_t getSize();
    void push(char data);
    char pop();
    char top();
    void print();
    double makeOperand();
    double evaluate();
};
#endif //PROJECT2_STACK_H
