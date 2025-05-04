//To do a  C++ Menu-Driven Program for Infix to Postfix Conversion and Postfix Evaluation using Character Singly Linked List Stack
#include <iostream>
#include <cctype>
#include <string>
#include "Stack.h"
using namespace std;

// Class
struct IntNode {
    int data;
    IntNode* next;
};

class IntStack {
private:
    IntNode* top;
public:
    IntStack() : top(nullptr) {}

    void push(int val) {
        IntNode* newNode = new IntNode{val, top};
        top = newNode;
    }

    int pop() {
        if (!top) return 0;
        int val = top->data;
        IntNode* temp = top;
        top = top->next;
        delete temp;
        return val;
    }

    ~IntStack() {
        while (top) pop();
    }
};

// Main Menu
int main() {
    string infix, postfix; 

    int choice;
    while (true) {
        cout << "\n        Menu\n";
        cout << "1. Get Infix Expression\n";
        cout << "2. Convert to Postfix\n";
        cout << "3. Evaluate Postfix\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Infix Expression: ";
                cin >> infix;
                break;

            case 2:
                if (infix.empty()) {
                    cout << "Enter infix first!\n";
                } else {
                    postfix = convertToPostfix(infix);
                    cout << "Postfix Expression: " << postfix << endl;
                }
                break;

            case 3:
                if (postfix.empty()) {
                    cout << "Convert to postfix first!\n";
                } else {
                    cout << "Evaluation Result: " << evaluatePostfix(postfix) << endl;
                }
                break;

            case 4:
                cout << "Exiting.\n";
                return 0;  

            default:
                cout << "Invalid Choice!\n";
                break;
        }
    }
}

// Operator Precedence Function
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Infix to Postfix Conversion
string convertToPostfix(const string& infix) {
    CharStack s;
    string postfix = "";

    for (char ch : infix) {
        if (isalnum(ch)) {
            postfix += ch;  // Operand directly to output
        } else if (ch == '(') {
            s.push(ch);
        } else if (ch == ')') {
            while (!s.isEmpty() && s.peek() != '(') {
                postfix += s.pop();
            }
            s.pop();  
        } else {  
            while (!s.isEmpty() && precedence(s.peek()) >= precedence(ch)) {
                postfix += s.pop();
            }
            s.push(ch);
        }
    }

    while (!s.isEmpty()) {
        postfix += s.pop();
    }

    return postfix;
}

// Postfix Evaluation using Integer Stack
int evaluatePostfix(const string& postfix) {
    IntStack stack;

    for (char ch : postfix) {
        if (isdigit(ch)) {
            stack.push(ch - '0');
        } else {
            int b = stack.pop();
            int a = stack.pop();
            switch (ch) {
                case '+': stack.push(a + b); break;
                case '-': stack.push(a - b); break;
                case '*': stack.push(a * b); break;
                case '/': stack.push(a / b); break;
            }
        }
    }

    return stack.pop();
}

/*
Operation                Time Complexity
Get Infix                 O(n)
Convert to Postfix        O(n)
Evaluate Postfix          O(n)
Operator Precedence       O(1)
*/