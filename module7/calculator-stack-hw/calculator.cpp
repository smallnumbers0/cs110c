#include <iostream>
#include <string>
#include "stack.h"

using namespace std;

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int pemdas(char c) {
    if(c == '+' || c == '-') {
        return 1;
    }
    else if(c == '/' || c == '*') {
        return 2;
    }
    
    return 0;
}

string infixToPostfix(const string& expression) {
    string postfix = "";
    Stack s;

    for (char c : expression) {
        if (isdigit(c)) {
            postfix += c;
        } else if (c == '(') {
            s.push(c);
        } else if (c == ')') {
            while (!s.isEmpty() && s.peek() != '(') {
                postfix += s.pop();
            }
            s.pop(); // Discard the '('
        } else if (isOperator(c)) {
            while (!s.isEmpty() && pemdas(c) <= pemdas(s.peek())) {
                postfix += s.pop();
            }
            s.push(c);
        }
    }

    while (!s.isEmpty()) {
        postfix += s.pop();
    }

    return postfix;
}

int evaluatePostfix(const string& postfix) {
    Stack s;

    for (char c : postfix) {
        if (isdigit(c)) {
            s.push(c - '0');
        } else if (isOperator(c)) {
            int operand2 = s.pop();
            int operand1 = s.pop();
            switch(c) {
                case '+': s.push(operand1 + operand2); break;
                case '-': s.push(operand1 - operand2); break;
                case '*': s.push(operand1 * operand2); break;
                case '/': s.push(operand1 / operand2); break;
            }
        }
    }

    return s.pop();
}


int evaluateExpression(const string& expression) {
    string postfix = infixToPostfix(expression);
    return evaluatePostfix(postfix);
}


int main() {
    string expression;
    cout<<"Enter a string for an operation with NO SPACES (Ex: 5+5-3): ";
    cin>>expression;
    int answer = evaluateExpression(expression);
    cout << expression << " = " << answer << endl;
    return 0;
}
