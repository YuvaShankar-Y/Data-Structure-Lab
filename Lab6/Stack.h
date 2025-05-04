// Stack.h header file
#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
};

class CharStack {
private:
    Node* top;

public:
    CharStack();
    ~CharStack();
    void push(char ch);
    char pop();
    char peek();
    bool isEmpty();
};

CharStack::CharStack() {
    top = nullptr;
}

CharStack::~CharStack() {
    while (top != nullptr) { 
        Node* temp = top;      
        top = top->next;       
        delete temp;           
    }
}


void CharStack::push(char ch) {
    Node* newNode = new Node;
    newNode->data = ch;
    newNode->next = top;
    top = newNode;
}

char CharStack::pop() {
    if (isEmpty()) {
        cout << "Stack Underflow!" << endl;
        return '\0';
    }
    Node* temp = top;
    char ch = top->data;
    top = top->next;
    delete temp;
    return ch;
}

char CharStack::peek() {
    if (isEmpty())
        return '\0';
    return top->data;
}

bool CharStack::isEmpty() {
    return top == nullptr;
}

#endif