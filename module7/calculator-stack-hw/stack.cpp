#include "stack.h"
#include <cassert>
using namespace std;

Stack::Stack() {
    top = -1;
}

bool Stack::isEmpty() {
    return top < 0;
}

void Stack::push(char c) {
    if(top < MAX_SIZE - 1) {
        top++;
        items[top] = c;
        return;
    }
    cout<<"No room for new entry"<<endl;
    return;
}

char Stack::pop() {
    if(!isEmpty()) {
        return items[top--];
    }
    return '\0';
}

char Stack::peek() {
    assert (!isEmpty()); 
    return items[top];
}