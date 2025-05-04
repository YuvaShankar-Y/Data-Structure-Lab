// TO do a  C++ Menu-Driven Program for Stack ADT using Character array
#include <iostream>
using namespace std;
#define MAX 5 

//Class 
class CharStack {
private:
    char stack[MAX];
    int top;

public:
    CharStack();            // Constructor to initialize stack
    void push(char ch);      // Push operation
    void pop();               // Pop operation
    void peek();              // Peek operation
};

// Main function
int main() {
    CharStack s;
    int choice;
    char element;

    while(1){
        cout <<"\n       Menu "<<endl;
        cout<<"1.Push"<<endl;
        cout<<"2.Pop"<<endl;
        cout<<"3.Peek"<<endl;
        cout<<"4.Exit"<<endl;
        cout<<"Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter character to push: ";
                cin >> element;
                s.push(element);
                break;

            case 2:
                s.pop();
                break;

            case 3:
                s.peek();
                break;

            case 4:
                cout << "Exiting program.\n";
                return 0;

            default:
                cout << "Invalid choice! Please enter a valid option.\n";
        }
    }
}

// Constructor 
CharStack::CharStack() {
    top = -1;  // Stack is initially empty
}

// Push operation 
void CharStack::push(char ch) {
    if (top == MAX - 1) {
        cout << "Stack Overflow! Cannot push " << ch << endl;
    } else {
        stack[++top] = ch;
        cout << ch << " pushed into stack." << endl;
    }
}

// Pop operation 
void CharStack::pop() {
    if (top == -1) {
        cout << "Stack Underflow! No element to pop." << endl;
    } else {
        cout << stack[top--] << " popped from stack." << endl;
    }
}

// Peek operation
void CharStack::peek() {
    if (top == -1) {
        cout << "Stack is empty! Nothing to peek." << endl;
    } else {
        cout << "Top element is: " << stack[top] << endl;
    }
}

/*
Operation	Time Complexity
  Push	        O(1)
  Pop	        O(1)
  Peek	        O(1)
*/