#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <string>

class Stack {
private:
    static const int MAX_SIZE = 100;
    int top;
    char items[MAX_SIZE];

public:
    Stack();

    void push(char c);
    char pop();
    char peek();
    bool isEmpty();
};

#endif