//// TO do a  C++ Menu-Driven Program for Stack ADT using Character Singly linked list
#include <iostream>
using namespace std;

// Node structure 
struct Node {
    char data;
    Node* next;
};

// Class 
class CharStack {
private:
    Node* top;

public:
    CharStack();            // Constructor to initialize stack
    void push(char ch);      // Push operation
    void pop();              // Pop operation
    void peek();             // Peek operation
};

// Main function
int main() {
    CharStack s;
    int choice;
    char element;

    while(1) {
        cout << "\n       Menu " << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
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
    top = nullptr;  
}

// Push operation 
void CharStack::push(char ch) {
    Node* newNode = new Node;
    newNode->data = ch;
    newNode->next = top;
    top = newNode;
    cout << ch << " pushed into stack." << endl;
}

// Pop operation 
void CharStack::pop() {
    if (top == nullptr) {
        cout << "Stack Underflow! No element to pop." << endl;
    } else {
        cout << top->data << " popped from stack." << endl;
        Node* temp = top;
        top = top->next;
        delete temp;
    }
}

// Peek operation 
void CharStack::peek() {
    if (top == nullptr) {
        cout << "Stack is empty! Nothing to peek." << endl;
    } else {
        cout << "Top element is: " << top->data << endl;
    }
}

/*
Operation	Time Complexity
  Push	        O(1)
  Pop	        O(1)
  Peek	        O(1)
*/
